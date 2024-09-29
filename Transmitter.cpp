//This a transmitter code for your ground station,however there will be a need to adjust the codes based on the function you like to perform
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <LoRa.h>
#include <SPI.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET -1    
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define ss 15
#define rst 16
#define dio0 2

int counter = 0;

void setup() {
  Serial.begin(9600);

 
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }


  LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("LoRa Transmitter");
  display.display();
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

 
  LoRa.beginPacket();
  LoRa.print("Packet No:");
  LoRa.println(counter);
  LoRa.endPacket();

  
  Serial.print("TransmittedValue:"); 
  Serial.println(counter);           


  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("Sending \npacket: \n");
  display.println(counter);
  display.display();

  counter++;
  delay(5000); 
}
