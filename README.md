# SimRacingDashboard
SimRacingDashboard is an Arduino-based project designed to create a custom dashboard for sim racing games. This dashboard displays essential game data such as speed, RPM, gear, and lap times, enhancing the racing simulation experience.
 

## Features

- **Display:**
  - Speed
  - RPM
  - Current Gear
  - Current Lap Time
  - Best Lap Time
  - Microsector Delta

- **Additional Features (Limited to certain games):**
  - KERS Charge Status
  - DRS Activation

<img title="test" src="doc/test(cut).jpg">

## How it works
The dashboard uses an Arduino as the main controller, connected to a TFT screen and 15 LEDs. Data is received from SimHub, which captures game telemetry and sends it via serial communication. A custom protocol (defined in `protocol.js`) manages the data exchange, ensuring accurate display of information.


<img title="test" src="doc/arduino.jpg" >

## Requirements

### Hardware
- Arduino
- TFT Screen
- 15 LEDs
- 2 x 74HC595 Shift Registers

### Libraries
- `Adafruit_GFX`
- `Adafruit_ST7735`

(All necessary libraries are included in the `libs` folder.)

### Software
- [SimHub](https://www.simhubdash.com/)

## Installation

1. Clone the repository.
2. Upload the Arduino code (`SimRacingDashboard.ino`) to your Arduino board.
3. Connect the hardware components as per the wiring diagram.
4. Install the required libraries.
5. Run SimHub and configure it to send data to the Arduino.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
