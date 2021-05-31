/*
 *  Arduino code for 16 button (4x4) TTP229 touch module
 *  
 *  original source: http://itimewaste.blogspot.com/2014/12/arduino-code-for-ttp229-touch-16-button.html
 *  
 * updated by Ahmad Shamshiri for Robojax.com 
 * on December 08, 2018 at 20:48 in Ajax, Ontario, Canada

watch video instruction for this code:https://youtu.be/2AEzQtKhBBY
Get this code and other Arduono codes from Robojax.com
 * 
  * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
 
//#include <SPI.h>

#define SCLpin 3 // define SCL pin
#define SDOpin 2 // define SDO pin

// the pins you want to turn ON or OFF or connect to relay
const int outputPins[] ={4, 5, 6, 7, 8, 9, 10, 11, 12, 13,A0,A1,A2,A3,A4,A5};// define output pins 

#if 0
  #define DEBUG_BUTTON16(a) (a)
#else
  #define DEBUG_BUTTON16(a)
#endif

#if 1
  #define DEBUG_STATUS(a) (a)
#else
  #define DEBUG_STATUS(a)
#endif


#pragma pack(push, 0)

// TBD: Replace with proper interrupt pin macros. It does not seem to be defined for atmega328p or I am incapable of finding it
#ifndef INT0_PIN
#ifdef __AVR_ATmega328P__
#define INT0_PIN 2
#else
  #warning Define INT0_PIN for this microcontroller to use interrupt
#endif
#endif

#ifndef INT1_PIN 
#ifdef __AVR_ATmega328P__
#define INT1_PIN 3
#else
  #warning Define INT1_PIN for this microcontroller to use interrupt
#endif
#endif

uint32_t g_intCount = 0;

struct CTtp229ButtonEvent
{
  uint8_t ButtonNumber : 5;         // ButtonNumber != 0 : Event is present. if equals 0, no event is received
  uint8_t IsButtonReleased : 1;     // True = Button is pressed. False = Button is released
};

class CTtP229TouchButton
{
  struct CTtp229Prop
  {
    uint16_t  SclPin : 6;
    uint16_t  SdoPin : 6;
    uint16_t  Is16Button : 1;
#if defined(INT0_PIN) || defined(INT1_PIN)
    uint16_t  HasPendingInterrupt : 1;
    uint16_t  IgnoreNextEvent : 1;            // When reading 16th key and if it is pressed, SDO stays low for 2ms.
                                              // If we enable interrupt before that, then it will trigger after 2ms, only to find the same condition.
                                              // To make things worse, at the end of reading the pin will stay low and generate another interrupt.
                                              // TBD: One possible fix is to send more pulses to make it roll over to HIGH. Have to find out if all 16 keys can be pressed in multi-key scenario (NOT supported yet).    
    uint16_t UnhandledButtonPresses;
#endif
    uint16_t PreviousButtonValue;
  };
  
  static CTtp229Prop g_prop;

  //
  //    Internal function that captures the data from TTP229 on which key is pressed.
  //  Currently, this function only supports one key being pressed. Multi-key press needs to be added later.
  // 
  //  Return Value : Bit field of buttons pressed
  //
  static uint16_t GetPressedButton()
  {
    DEBUG_BUTTON16(Serial.println("GetPressedButton : Enter "));
    uint16_t buttonsPressed = 0;
    // Need to generate the LOW and then HIGH on the clock and read the value from data when clock is back high.
    // As per the specification, the TTP229 chip can support 512Khz. This translates to approximately 2us for a cycle. So introducing clock with fall and raise each of 1us.
    uint8_t maxCnt = g_prop.Is16Button ? 16 : 8;
    for(uint8_t ndx = 0; ndx < maxCnt; ndx++ )
    {
      digitalWrite(g_prop.SclPin, LOW);
      delayMicroseconds(1);
      digitalWrite(g_prop.SclPin, HIGH);
      
      int val = digitalRead(g_prop.SdoPin);

      delayMicroseconds(1);  // Technically this can be moved after the if for most atmel microcontrollers. But if there is a really fast one (now/future) and the next call to GetPressedButton made immediately, we might overclock TTP229. Being safe here

      if( LOW == val )
      {
        buttonsPressed |= (1 << ndx);
      }      
    }
    
    DEBUG_BUTTON16(Serial.print("GetPressedButton : Exit. Return Value : ")); 
    DEBUG_BUTTON16(Serial.println(buttonsPressed));

    return buttonsPressed;
  }
  
#if defined(INT0_PIN) || defined(INT1_PIN)
  // Detaching the interrupt after receiving the data can cause problem in sleeping. If the interrupt is not properly dispatched, it can lead to permanent sleep and can't wake up from button
  static void HandleButtonEvent()
  {
    if( g_prop.IgnoreNextEvent )
    {
      // We ignored an event. Now we will accept the event
      g_prop.IgnoreNextEvent = false;
    }
    else
    {
      g_prop.HasPendingInterrupt = true;
      g_intCount++;
    }
  }
  
  static void SetInterruptHandler()
  {
#ifdef INT0_PIN    
    if( INT0_PIN == g_prop.SdoPin ) 
    {
      DEBUG_BUTTON16(Serial.println("Configure : With interrupt 0"));
      EIFR = 0x01; // Clear INTF0 flag
      attachInterrupt(0, HandleButtonEvent, RISING); // The pin goes down for 93us and then raises that is when the device is ready (technically after 10us)      
    }
#endif 

#ifdef INT1_PIN    
    if( INT1_PIN == g_prop.SdoPin ) 
    {
      DEBUG_BUTTON16(Serial.println("Configure : With interrupt 1"));
      EIFR = 0x02; // Clear INTF1 flag
      attachInterrupt(1, HandleButtonEvent, RISING); // The pin goes down for 93us and then raises that is when the device is ready (technically after 10us)      
    }
#endif 
  }
  
  static void RemoveInterruptHandler()
  {
#ifdef INT0_PIN
    if( INT0_PIN == g_prop.SdoPin ) 
    {
      detachInterrupt(0);
    }
#endif

#ifdef INT1_PIN 
    if( INT1_PIN == g_prop.SdoPin ) 
    {
      detachInterrupt(1);
    }
#endif
  }
#endif

  //
  //    Returns button number being pressed. High bit indicates more changes present
  //
  static uint8_t GetButtonNumberFromFlag(uint16_t buttonsChanged)
  {
    uint16_t flag = 1;
    for(uint8_t ndx = 1; ndx <=16; ndx++, flag <<= 1)
    {
      if( (buttonsChanged & flag) != 0 )
      {
        if( (buttonsChanged & ~flag) != 0 )
        {
          // Some other bit is present
          ndx |= 0x80;
        }
        
        return ndx;
      }
    }
    
    return 0;
  }
  
  public:
  //
  //    Setup the TTP229 Touch button on this input.
  //
  // Inputs:
  //     sclPin  - Clock Pin of the button (3rd from left on button, connected to arduino's digital pin number)
  //     sdoPin  - Data pin to read from the button (4th pin from left on button, connected to arduino's digital pin number)
  //     is16Button - true = 16 buttons board. false = 8 button board
  //
  static void Configure(int sclPin, int sdoPin, bool is16Button = true)
  {
    DEBUG_BUTTON16(Serial.println("Configure : Enter")); 
    
    g_prop.SclPin = sclPin;
    g_prop.SdoPin = sdoPin;
    g_prop.Is16Button = is16Button;

    g_prop.PreviousButtonValue = 0;

    // Configure clock as output and hold it high
    pinMode( sclPin, OUTPUT ); 
    digitalWrite(sclPin, HIGH);    
    
    // Configure data pin as input
    pinMode( sdoPin, INPUT);
    
    DEBUG_BUTTON16(Serial.print("Button Configuration

SCL Pin : "));
    DEBUG_BUTTON16(Serial.println(sclPin));
    DEBUG_BUTTON16(Serial.print("SDO Pin : "));
    DEBUG_BUTTON16(Serial.println(sdoPin));
    DEBUG_BUTTON16(Serial.print("Number of Keys : "));
    DEBUG_BUTTON16(Serial.println(is16Button ? 16 : 8));

#if defined(INT0_PIN) || defined(INT1_PIN)
    g_prop.UnhandledButtonPresses = 0;
    g_prop.HasPendingInterrupt = false;
    g_prop.IgnoreNextEvent = false;
    SetInterruptHandler();
#endif

    DEBUG_BUTTON16(Serial.println("Configure : Exit"));
  }
  
  //
  //    Get the current status from the 16 button touch device
  //
  //   Return Value : Returns the bitflag of the keys pressed. returns 0, if no key is pressed.
  //
  static uint16_t GetButtonStatus()
  {
#if defined(INT0_PIN) || defined(INT1_PIN)
    g_prop.HasPendingInterrupt = 0;
#endif

    uint16_t returnValue = GetPressedButton();
    
#if defined(INT0_PIN) || defined(INT1_PIN)
    returnValue |= g_prop.UnhandledButtonPresses;    // and also include any data that was received that we have not sent yet.
    g_prop.UnhandledButtonPresses = 0;
#endif

    g_prop.PreviousButtonValue = returnValue;

    return returnValue; 
  }
  
  //
  //    Gets the event from the button. This is useful for monitoring press and release only. 
  // Each button press will generate max 2 events, one for press and another for release. When the button is press and held, this method will return no event.
  // If the calls were not made often enough, the events could be missed. For instance, you might get 2 pressed, followed by 4 pressed, which automatically means 2 released in single key mode.
  //
  // Return Value : if ButtonNumber is 0, then no event
  //
  static CTtp229ButtonEvent GetButtonEvent()
  {
    CTtp229ButtonEvent returnValue = {0, 0};
    uint8_t buttonNumber;

    DEBUG_BUTTON16(Serial.print("Old Value  : "));
    DEBUG_BUTTON16(Serial.println(g_prop.PreviousButtonValue));


#if defined(INT0_PIN) || defined(INT1_PIN)
    if(
#if defined(INT0_PIN)
    INT0_PIN == g_prop.SdoPin 
#endif
#if defined(INT0_PIN) && defined(INT1_PIN)
    ||
#endif
#if defined(INT1_PIN)
    INT1_PIN == g_prop.SdoPin 
#endif
    ) 
    {
      // Interrupts are used. Check if we have interrupt
      if( g_prop.HasPendingInterrupt )
      {
        RemoveInterruptHandler();                 // From this point upto SetInterruptHandler is called, ensure there is no return path that will leave without SetInterruptHandler
      }
      else
      {
        DEBUG_BUTTON16(Serial.println("GetButtonEvent: No interrupt pending"));
        return returnValue;
      }
    }
#endif

    uint16_t currValue = GetPressedButton();

#if defined(INT0_PIN) || defined(INT1_PIN)
    currValue |= g_prop.UnhandledButtonPresses; // Get any previously returned but not returned now values also into the mix
#endif

    uint16_t changes = g_prop.PreviousButtonValue ^ currValue;
    uint16_t pressed = (changes & currValue);
    uint16_t released = (changes & g_prop.PreviousButtonValue);

    // First check if any key is that is pressed and generate press event
    if( 0 != pressed )
    {
      buttonNumber = GetButtonNumberFromFlag(pressed);
      returnValue.ButtonNumber = (buttonNumber & 0x7F);
      
      uint16_t mask = (1 << (returnValue.ButtonNumber -1));
      // set the new notified button into prev
      g_prop.PreviousButtonValue |= mask;
      
#if defined(INT0_PIN) || defined(INT1_PIN)
      g_prop.UnhandledButtonPresses = currValue;
      g_prop.UnhandledButtonPresses = currValue & ~g_prop.PreviousButtonValue;    // clear unhandled for this bit, just in case
#endif
    }
    else if(0 != released)
    {
      buttonNumber = GetButtonNumberFromFlag(released);
      returnValue.ButtonNumber = (buttonNumber & 0x7F);

      // The unmatching bit whose previous value of 1 means, it is released
      returnValue.IsButtonReleased = true;
      
      // clear the notified release button
      g_prop.PreviousButtonValue &= ~(1 << (returnValue.ButtonNumber -1));
    }

    
#if defined(INT0_PIN) || defined(INT1_PIN)
    
    if(((!returnValue.IsButtonReleased || (0 == pressed))   // We handle release but no pending press
          && ((buttonNumber & 0x80) == 0 )) // or more button changes are detected
        || (returnValue.ButtonNumber == 0) )    // safety in case interrupt and data mismatch or code bug
    {
      // No more button notification pending
      g_prop.HasPendingInterrupt = false;
    }
    else
    {
      DEBUG_BUTTON16(Serial.println("not Clearing interrupt"));
    }

    g_prop.IgnoreNextEvent = digitalRead(g_prop.SdoPin) == LOW; // If the pin is still low at the end of reading, ignore next event which is for data finished raise
    DEBUG_BUTTON16(Serial.print(g_prop.IgnoreNextEvent ? "Ignoring next event

" : "Not ignoring

"));
    
    // All the data has been read. Now reactivate the interrupt
    SetInterruptHandler();
#endif
    
    DEBUG_BUTTON16(Serial.print("currValue : "));
    DEBUG_BUTTON16(Serial.println(currValue));
    DEBUG_BUTTON16(Serial.print("Changes    : "));
    DEBUG_BUTTON16(Serial.println(changes));
    DEBUG_BUTTON16(Serial.print("Button N   : "));
    DEBUG_BUTTON16(Serial.println(buttonNumber));
    DEBUG_BUTTON16(Serial.print("Unhandled  : "));
    DEBUG_BUTTON16(Serial.println(g_prop.UnhandledButtonPresses));
    DEBUG_BUTTON16(Serial.print("ButtonRelease : "));
    DEBUG_BUTTON16(Serial.println(returnValue.IsButtonReleased));
    DEBUG_BUTTON16(Serial.print("buttonNumber : "));
    DEBUG_BUTTON16(Serial.println(buttonNumber));
    DEBUG_BUTTON16(Serial.print("Pending interrupts :"));
    DEBUG_BUTTON16(Serial.println(g_prop.HasPendingInterrupt));
    
    return returnValue;
  }
  
#if defined(INT0_PIN) || defined(INT1_PIN)
  static bool HasEvent()
  {
#if defined(INT0_PIN)
    if( INT0_PIN == g_prop.SdoPin )
    {
      return g_prop.HasPendingInterrupt;
    }
#endif

#if defined(INT1_PIN)
    if( INT1_PIN == g_prop.SdoPin )
    {
      return g_prop.HasPendingInterrupt;
    }
#endif
    
    return true;
  }
#endif

};

CTtP229TouchButton::CTtp229Prop CTtP229TouchButton::g_prop;
CTtP229TouchButton g_ttp229Button;

#define TTP16Button g_ttp229Button
#pragma pack(pop)

void setup()
{
  // Robojax TTP229 4x4 (16 button) touch pad
  Serial.begin(9600);

   for (int i=0; i<16; i++)
   {
    pinMode(outputPins[i], OUTPUT);// set pins as output
   }
  
  DEBUG_STATUS(Serial.println("===================================================================="));
  DEBUG_STATUS(Serial.println("Robojax 16 button Touch Test"));  
  DEBUG_STATUS(Serial.println("===================================================================="));
  
  TTP16Button.Configure(SCLpin, SDOpin);
}

void TestStatus()
{
  uint8_t buttonNumber = TTP16Button.GetButtonStatus();
  
  if( 0 != buttonNumber )
  {
    DEBUG_STATUS(Serial.print("Button Pressed : "));
    DEBUG_STATUS(Serial.println(buttonNumber));
  }

  delayMicroseconds(2500); // TTP229 document says it will reset the output if 2ms idle + little bit safety
}

void TestEvent()
{
#if defined(INT0_PIN) || defined(INT1_PIN)
  if( TTP16Button.HasEvent())
#endif
  {
    CTtp229ButtonEvent buttonEvent = TTP16Button.GetButtonEvent();
    
    if( 0 != buttonEvent.ButtonNumber )
    {
      if( buttonEvent.IsButtonReleased )
      {
        DEBUG_STATUS(Serial.print("Button Released: "));
        digitalWrite(outputPins[buttonEvent.ButtonNumber -1], HIGH);
      }
      else
      {
        DEBUG_STATUS(Serial.print("Button Pressed : "));
        digitalWrite(outputPins[buttonEvent.ButtonNumber -1], LOW);
      }
      DEBUG_STATUS(Serial.print(buttonEvent.ButtonNumber));
      DEBUG_STATUS(Serial.print(" pin: "));
      DEBUG_STATUS(Serial.println(outputPins[buttonEvent.ButtonNumber -1]));
    }
    else
    {
#if defined(INT0_PIN) || defined(INT1_PIN)
        DEBUG_STATUS(Serial.println("Are you not using interrupt? Should never come here for interrupt based system."));
#endif
    }
    
    //Serial.print("CurrentTime : "); Serial.println(millis());
    delayMicroseconds(2500); // TTP229 document says it will reset the output if 2ms idle + little bit safety. Not required if using interrupts
  }
  
}

void loop()
{
  //TestStatus();
  TestEvent();
}
 
