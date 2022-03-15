// man-in-the-middle with uart
// Arduino MEGA-2560
unsigned int RX = 0; // RX count
unsigned int TX = 0; // TX count

void setup() {
  Serial.begin(1000000); // Debug
  Serial1.begin(115200); // Interface 1
  Serial2.begin(115200); // Interface 2
}

void loop() {
  if(Serial1.available()){
    RX++; // Increment count
    byte temp = Serial1.read();
    Serial2.write(temp);
    delayMicroseconds(10);
    Serial.print("RX ");
    Serial.println(temp, HEX); // Print the recieve value
  }
  
  if(Serial2.available()){
    TX++; // Increment count
    byte temp = Serial2.read();
    Serial1.write(temp);
    delayMicroseconds(10);
    Serial.print("TX ");
    Serial.println(temp, HEX); // Print the recieve value
  }
  
  if(Serial.available()) { // Print a recap
    while(Serial.available()) Serial.read();
    Serial.print("Receive :");
    Serial.print(RX);
    Serial.println(" bits");
    Serial.print("Transmit :");
    Serial.print(TX);
    Serial.println(" bits");
    // Reset variables:
    RX = 0;
    TX = 0;
  }
}
