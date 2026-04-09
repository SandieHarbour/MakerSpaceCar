The electronics for this project consist of a WeMos D1 Mini microcontroller and a DRV8833 dual motor driver.

![](<images/Electronics Board.png>)
Components mounted on a perf board
Power to the board is provided through the USB-C port on the D1 mini.

The connections between the two devices are shown in the table below:

| WeMos D1 Mini | DRV8833 |         |
| ------------- | ------- | ------- |
| 5V            | VCC     |         |
| GND           | GND     |         |
| D3            | IN4     |         |
| D4            | IN3     |         |
| D7            | IN1     |         |
| D8            | IN2     |         |
|               | OUT1    | Motor 1 |
|               | OUT2    | Motor 1 |
|               | OUT3    | Motor 2 |
|               | OUT4    | Motor 2 |
![677](<images/Wiring Diagram.png>)
Wiring diagram



#### WeMos D1 Mini:
Makersportal.com describes the WeMos D1 Mini as:
	The WeMos D1 Mini is an inexpensive ESP8266-based WiFi board that is low-profile but just as powerful as any NodeMCU or ESP8266-based microcontroller. The D1 Mini is incredibly versatile because it is inexpensive, WiFi-enabled, and fully compatible with the Arduino platform. In this tutorial, the ESP8266 library and board manager will be introduced in order to get the D1 Mini acting as an Arduino board. Then, a simple web page will be introduced with the intention of harnessing the WiFi capabilities of the module. The D1 Mini will act as a web server, allowing any WiFi-connected device to interact with the board and control its pins wirelessly.

 ![](https://lastminuteengineers.com/wp-content/uploads/iot/WeMos-D1-Mini-Pinout.png)


#### DRV8833:
According to Google AI: 
	The **DRV8833** is a dual H-bridge motor driver integrated circuit (IC) from Texas Instruments designed to control either **two brushed DC motors** or one bipolar stepper motor. It is a popular, high-efficiency alternative to the older L298N driver, especially for low-voltage, battery-powered projects like small robots and toys.

This animation from Last Minute Engineers demonstrates how an H-Bridge changes polarity:
	![](<images/H-Bridge-Working-Motor-Direction-Control-Animation.gif>)


## Notes:
1. The DRV8833 driver is "disabled" when it comes from the factory.  There are two ways to "enable" it.  
	1. Close the J2 jumper with a solder bridge.  
	2. Pull the EEP pin on the DRV8833 to HIGH by connecting it either to the 3.3 volt pin on the D1 mini or to any GPIO pin and setting it to HIGH.