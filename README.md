# autosprinkler
Auto water sprinkler project for my back yard

## Prerequisites
- Raspberry pi
- Arduino
- Hose pipes
- T-pipe(optional)
- Solenoid valve(normally open)
- Raspberry pi 433mhz transmitter
- Arduino 433mhz reciever
- Connector pipes
- Tap valve
- Hose connector
- Relay

## To build
### Software
Download sprinklercontroller.ino and ???.py and upload respectively to Arduino and Raspberry pi. After installing these you should be ready to go.

### Hardware
Install the Solenoid valve and T-pipe to water source (T-pipe only required if you still want to use original tap). Then connect hose adapter and hose pipe before creating a sprinkler system around the needed parts of the garden. Connect switch to Solenoid valve and power supply.
Now the sprinkler system should be working, test by switching the switch on.

If you only require the sprinkler system without pi automation you can stop here.

### Pi automation
## wiring 433mhz transmitter to Raspberry Pi
1.Connect ATAD pin on 433mhz transmitter to 5V GPIO
2.Connect VCC pin on 433mhz transmitter to  GPIO pin 17
3.Connect GND pin on 433mhz transmitter to GND GPIO
## wiring 433mhz reciever to Arduino
1.Connect 5V pin on 433mhz reciever to 5V GPIO
2.Connect OUT pin on 433mhz reciever to GPIO 7
3.Connect GND pin on 433mhz reciever to GND GPIO
## setting up Raspberry pi and Arduino
Upload sprinklercontroller.ino to Arduino. Upload ???.py to Raspberry Pi and run to turn on sprinkler system, run ???.py again to turn off sprinkler system. 
