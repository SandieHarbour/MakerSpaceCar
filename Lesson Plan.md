### Preparations
- Open my GitHub repo https://github.com/DonaldPotbury/RemoteXY-Car
- Open the RemoteXY website (https://remotexy.com/en/) in a new tab
- Open ([https://github.com/RemoteXY/RemoteXY-Arduino-library](https://github.com/RemoteXY/RemoteXY-Arduino-library)) in a new tab
- Start the Arduino IDE
	- Configure the IDE for ESP8266 (if needed)
		- Go to File/Preferences and paste the following string in text box labeled "Additional Boards Manager URL's"
		- http://arduino.esp8266.com/stable/package_esp8266com_index.json
		- See https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/ for detailed instructions
	- Load the RemoteXY library
		- Download RemoteXY library which can be found at [https://github.com/RemoteXY/RemoteXY-Arduino-library](https://github.com/RemoteXY/RemoteXY-Arduino-library)
		- Download the zip file.
		- Under Sketch/Include Library choose "Add .ZIP file"
		- Browse the where you saved the zip file and select it
### Create the GUI in RemoteXY
- Expand Configuration section along the right
- Click the top item (might be Bluetooth)
- You are presented with a configuration window.
- Under Connection choose "Wi-Fi Access point"
- Under Board choose "ESP8266 based board"
- Under Module choose "Integrated WiFi"
- Under IDE choose "Arduino"
- Click Apply
- We are back in the App editor
- Expand Connection
- Change the SSID to MakerCar__. (Where __ is your car number)
- Check Open point
- leave port at 6377
- Expand Settings
- Set Device name in app to "Maker Car"
- Access password is blank
- Expand View
- Click Add under Screen formats
- Add a horizontal screen format
- The left side of the editor screen has the controls
- Drag a "Joystick" control to the screen
- Joystick has been added to the configuration section on the right
- Check the Automatically center checkbox
- Set G-sensor button to "Bottom left" 
	
### Generate the Code
- Click on the "Get source code button"
- A source code page is presented.
- Click "Copy code"
- Copy the code to the Arduino IDE
- Open the Arduino IDE
- A blank sketch stub should appear.  If not, click File/New Sketch
- Delete the code in the sketch stub and paste in the code generated from above
- Delete the setup and loop functions
	- We will be replacing them with our own.
- Copy the code below and paste it in at the bottom of code in the IDE
![Code Stub](Sketches/Code%20Stub.md) 
- Double check to insure the WiFi SSID to something unique
- Upload it to the WeMos D1 Mini
### On the phone
- Load the App
- Connect to your access point
