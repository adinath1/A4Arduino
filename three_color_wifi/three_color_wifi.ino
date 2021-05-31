#include <ESP8266WiFi.h>
 
const char* ssid = "adinath";
const char* password = "ajithkumar";
 
int blue = 13;
int green = 12;
int white = 11;

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
   delay(10);
   pinMode(blue, OUTPUT);
   pinMode(green, OUTPUT);
   
   
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  
 
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/BLUE=ON") != -1) {
    digitalWrite(blue, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/BLUE=OFF") != -1){
    digitalWrite(blue, LOW);
    value = LOW;
  }
 
 
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("<font color=darkblue>Led pin is now:</font> ");
 
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<font color=darkblue> Click <a href=\"/blue=ON\">here</a> Turn BLUE ON<br>");
  client.println("Click <a href=\"/blue=OFF\">here</a> Turn BLUE OFF<br></font>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
 
}
