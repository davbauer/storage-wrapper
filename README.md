# ESP8266 Library: Storage
An Arduino library for easily storing data on ESP8266´s EEPROM.
*Mostly based on https://github.com/PaulStoffregen/EEPROM*

 - **Importing the Library**
	+ Download the library [[.ZIP]](https://github.com/davbauer/Storage/archive/refs/heads/main.zip)
	+ Launch Arduino IDE and click *`[Sketch]`* *->* *`[Include Library]`* -> *`[Add .ZIP Library...]`* to import the library
- **Opening the example .ino file**
	+ I. In Arduino IDE click *`[File]`* *->* *`[Examples]`* -> *`[Storage]`* -> *`[basic]`* to open the example code
- **Finishing up**
	+ I. Make sure the library EEPROM is installed, if its not already installed you can download it [here](https://github.com/PaulStoffregen/EEPROM) and follow the steps from above to import it.
	---
- **Available Methods**
	>
	- int    getStart()⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ *returns start byte position*
	- int    getEnd()⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀*returns end byte position*
	- String getCache()⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ *returns what´s currently saved in cache*
	>
	- void   clear()⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ *clears the Storage object (remove what´s saved)*
	- void    write(String/int/float/double text)⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ *writes a string/int/float/double into Storage object*
	>
	- String  readString()⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ *retrieve saved data as string*
	- String  read()⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ *retrieve saved data as string*
	- int     readInt()⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ *retrieve saved data as int*
	- double  readDouble()⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ ⠀ *retrieve saved data as double*

- **Example Code**
	
	``` C++
	#include <EEPROM.h> // https://github.com/PaulStoffregen/EEPROM
	#include <Storage.h> // https://github.com/davbauer/Storage

	Storage my_object(0, 20); // Define your Storage objects and from which
	Storage other_obj(20, 30); // byte to start and end writing

	void setup() {
	  Serial.begin(115200);
	  Serial.println();
	  EEPROM.begin(512); // Set the amount of bytes of your EEPROM

	  my_object.write("Data to save"); // Write data
	  String x = my_object.read(); // Read Data
	  Serial.println(x); // Prints ("Data to save")

	  other_obj.write(19.86);
	  int y = other_obj.readInt();
	  double z = other_obj.readDouble(); 

	  Serial.println(y); // Prints (19)
	  Serial.println(z); // Prints (19.86)
	}

	void loop() {
	  delay(10000);
	}
	```
	Final Output (Serial Monitor):
	
	``` text
	Data to save
	19
	19.86
	```
