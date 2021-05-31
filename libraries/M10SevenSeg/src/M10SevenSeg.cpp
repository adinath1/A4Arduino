/*
###############################################################################
# Copyright (c) 2018, PulseRain Technology LLC 
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License (LGPL) as 
# published by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
# or FITNESS FOR A PARTICULAR PURPOSE.  
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
###############################################################################
*/

#include "M10SevenSeg.h"

static const uint8_t seven_seg_display_encoding [16] = {
   0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};


//----------------------------------------------------------------------------
// seven_seg_on_off()
//
// Parameters:
//      on_off_mask : mask for power on/off
//     
// Return Value:
//      None
//
// Remarks:
//      This function assumes power on/off control is in the lower 
//      two bits of Port 2
//----------------------------------------------------------------------------

static void seven_seg_on_off (uint8_t on_off_mask) __reentrant
{
  P2 &= 0xFC;
  P2 |= on_off_mask & 0x3;
} // End of seven_seg_on_off()

//----------------------------------------------------------------------------
// seven_seg_init()
//
// Parameters:
//      None
//     
// Return Value:
//      None
//
// Remarks:
//    This function assumes Port 0 and Port 1 are connected to 7-seg display,
//    and assumes on/off control is in the lower two bits of Port 2
//----------------------------------------------------------------------------

static void seven_seg_init() __reentrant
{
  P0_DIRECTION = 0xFF;
  P1_DIRECTION = 0xFF;
  P2_DIRECTION |= 0x3;

  seven_seg_on_off (3);
} // End of seven_seg_init()


//----------------------------------------------------------------------------
// seven_seg_dp()
//
// Parameters:
//      mask : mask for the decimal points
//     
// Return Value:
//      None
//
// Remarks:
//     This function assumes Port 0 and Port 1 are connected to 7-seg display,
//     and assumes decimal point is controlled by bit 7 in each port
//----------------------------------------------------------------------------

static void seven_seg_dp (uint8_t mask) __reentrant
{
  P0_7 = mask & 0x1;
  P1_7 = (mask >> 1) & 0x1;
} // End of seven_seg_dp()


//----------------------------------------------------------------------------
// seven_seg_display()
//
// Parameters:
//      number : hex number (0 ~ 15) to be displayed
//      index  : 0 or 1 for display position
//     
// Return Value:
//      None
//
// Remarks:
//     This function assumes Port 0 and Port 1 are connected to 7-seg display.
//----------------------------------------------------------------------------

static void seven_seg_display (uint8_t number, uint8_t index) __reentrant
{
   uint8_t t;

   t = number & 0xF;
   
   if (index == 0) {
      P0 &= 0x80;
      P0 |= seven_seg_display_encoding[t];
   } else if (index == 1) {
      P1 &= 0x80;
      P1 |= seven_seg_display_encoding[t];
   }
} // End of seven_seg_display()


//----------------------------------------------------------------------------
// seven_seg_hex_byte_display()
//
// Parameters:
//      number : hex number (0 ~ 255) to be displayed
//     
// Return Value:
//      None
//
// Remarks:
//     This function assumes Port 0 and Port 1 are connected to 7-seg display.
//----------------------------------------------------------------------------

static void seven_seg_hex_byte_display (uint8_t num) __reentrant
{
  seven_seg_display (num, 1);
  seven_seg_display (num >> 4, 0);
} // End of seven_seg_hex_byte_display()



const SEVEN_SEG_STRUCT SEVEN_SEG = {
  .init = seven_seg_init,
  .onOff = seven_seg_on_off,
  .byteHex = seven_seg_hex_byte_display,
  .decimalPoint = seven_seg_dp
};
