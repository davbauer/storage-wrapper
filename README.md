# ESP8266 Library: Storage
An Arduino library for easily storing data on ESP8266´s EEPROM.
*Mostly based on https://github.com/PaulStoffregen/EEPROM*

 - **Importing the Library**
	> I. Download the library
	> II. Launch Arduino IDE and click *`[Sketch]`* *->* *`[Include Library]`* -> *`[Add .ZIP Library...]`* to import the library
- **Opening the example .ino file**
	> I. In Arduino IDE click *`[File]`* *->* *`[Examples]`* -> *`[Storage]`* -> *`[basic]`* to open the example code
- **Finishing up**
	> I. Make sure the library EEPROM is installed, if its not already installed you can download it [here](https://github.com/PaulStoffregen/EEPROM) and follow the steps from above to import it.
	---
- **Available Methods**
	>
	- int getStart()
	- int getEnd()
	- String getCache()
	>
	- void clear()
	- void writeString(String text)
	- void write(String text)
	- void write(int val)
	- void write(float val)
	- void write(double val)
	>
	- String  readString()
	- String  read()
	- int  readInt()
	- double  readDouble()
