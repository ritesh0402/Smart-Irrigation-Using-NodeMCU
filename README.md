# Smart-Irrigation-Using-NodeMCU

## Introduction:
        
Welcome to the Smart-Irrigation-Using-NodeMCU project! This repository was created by [ritesh0402](https://github.com/ritesh0402) to provide a solution for automating irrigation systems using the NodeMCU microcontroller. This project aims to simplify the irrigation process, reduce water wastage, and optimize plant growth.

## Features:
        
- Automated irrigation control based on moisture levels of the soil.
- Real-time monitoring and control of irrigation through a web interface.
- Adjustable settings for irrigation periods and moisture thresholds.
- Low power consumption and cost-effective solution.

## Installation:

To install the Smart-Irrigation-Using-NodeMCU project, please follow these steps:

1. Ensure that you have a NodeMCU board, a soil moisture sensor, a water pump, and associated wires.
2. Connect the NodeMCU board to your PC using a USB cable.
3. Download and install the Arduino IDE if you do not have it already.
4. Open the IDE, go to File > Preferences and enter the following URL in the "Additional Board Manager URLs" section: ```http://arduino.esp8266.com/stable/package_esp8266com_index.json```
5. Go to Tools > Board > Boards Manager and search for "esp8266". Click on "esp8266 by ESP8266 Community" and click on "Install".
6. Once installed, select "NodeMCU 1.0 (ESP-12E Module)" from the Tools > Board menu.
7. Download the project's source code by clicking on the green "Code" button and selecting "Download ZIP".
8. Extract the ZIP file to a convenient location on your computer.
9. Open the extracted folder and double-click on the "Smart_Irrigation_using_NodeMCU.ino" file. This will open it in the Arduino IDE.
10. Configure the Wi-Fi and MQTT settings according to your network setup by editing the "config.h" file.
11. Connect the soil moisture sensor and the water pump to the designated pins on the NodeMCU board.
12. Click on the "Upload" button to upload the code to the NodeMCU board.

## Usage:

To use the Smart-Irrigation-Using-NodeMCU project, follow these steps:

1. Connect the NodeMCU board to a power source and turn it on.
2. Make sure the Wi-Fi and MQTT settings
