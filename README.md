# Ground-Station
This projects teaches you how to build a ground station for your drone system or CanSat using esp8266 and Lora Module and track real time data on display.
 Introduction

In this blog post, I will walk you through how I built a ground station to transmit and receive data from a CanSat or your Drone. Using an ESP8266 microcontroller, LoRa SX1278 RA02 module, and an OLED display, this ground station allows real-time data reception and display. This setup is essential for tracking and monitoring the sensor data sent from the CanSat or Drone during its flight.



Components Used

- ESP8266: A Wi-Fi-enabled microcontroller, ideal for IoT projects.

- LoRa SX1278 RA02: A long-range, low-power communication module.

- OLED Display: A small, low-power display for showing received data.

- Antenna: Enhances signal reception for long-distance communication.

- Breadboard, Jumper Wires, and Connectors: For prototyping and connecting components.



Circuit Design

The heart of the ground station is the ESP8266, which communicates with the LoRa module to receive the sensor data transmitted from the CanSat. The OLED display provides a visual interface for monitoring the data. Here's how I connected the components:

ESP8266 to LoRa SX1278 RA02:

  - MOSI to GPIO13(D7)

  - MISO to GPIO12(D6)

  - SCK to GPIO14(D5)

  - NSS to GPIO15(D8)

  - RST to GPIO16(D0)

  - DIO0 to GPIO5(D0)

ESP8266 to OLED Display:

  - SDA to GPIO4(D2)

  - SCL to GPIO5(D1)




 Code Implementation

I wrote a simple program using the Arduino framework on PlatformIO to transmit and receive the data from the LoRa module and display it on the OLED screen. Here’s a brief breakdown of the code:

Transmitter Code

Get the code for the receiver from my GitHub repository:https://github.com/amirphiladam2/Ground-Station/blob/main/Transmitter.cpp

- LoRa Initialization: I initialized the LoRa module to operate at 433 MHz frequency.

- Data Transmission: The ESP8266 constantly send packets from the ground station to the intended receiver.

- OLED Display: Once a packet is received, the data is parsed and displayed on the OLED in real-time.

Receiver Code

Get the code for the receiver from my GitHub repository:https://github.com/amirphiladam2/Ground-Station/blob/main/Receiver.cpp

- LoRa Initialization: I initialized the LoRa module to operate at 433 MHz frequency.

- Data Reception: The ESP8266 constantly listens for incoming packets from the CanSat/Drone.

- OLED Display: Once a packet is received, the data is parsed and displayed on the OLED in real-time.



Testing and Results

During testing, the ground station successfully received sensor data transmitted by the CanSat via LoRa. The data was displayed in real-time on the OLED, making it easy to monitor. With the LoRa module's long-range capabilities, I was able to maintain communication over considerable distances.



 Conclusion

This ground station setup is a simple yet powerful way to monitor data from a CanSat or other remote devices. By using LoRa for communication, I was able to achieve long-range data transmission, and the OLED display provided a convenient interface for real-time monitoring.
