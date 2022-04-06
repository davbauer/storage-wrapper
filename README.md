# ESP8266 Library: Storage
An Arduino library for easily storing data on ESP8266´s EEPROM.
*Mostly based on https://github.com/PaulStoffregen/EEPROM*

 - **Importing the Library**
	+ Download the library
	+ Launch Arduino IDE and click *`[Sketch]`* *->* *`[Include Library]`* -> *`[Add .ZIP Library...]`* to import the library
- **Opening the example .ino file**
	+ I. In Arduino IDE click *`[File]`* *->* *`[Examples]`* -> *`[Storage]`* -> *`[basic]`* to open the example code
- **Finishing up**
	+ I. Make sure the library EEPROM is installed, if its not already installed you can download it [here](https://github.com/PaulStoffregen/EEPROM) and follow the steps from above to import it.
	---
- **Available Methods**
	>
	- int    getStart()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;returns start byte position
	- int    getEnd()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;returns end byte position
	- String getCache()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;returns what´s currently saved in cache
	>
	- void   clear()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;clears the Storage object (remove what´s saved)
	- void    write(String/int/float/double text)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;writes a string/int/float/double into Storage object
	>
	- String  readString()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;retrive saved data as string
	- String  read()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;retrive saved data as string
	- int     readInt()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;retrive saved data as int
	- double  readDouble()&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;retrive saved data as double
