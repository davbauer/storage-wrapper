# ESP8266 Wrapper Library: Storage
An Arduino wrapper library for making it easier to store or retrieve data for beginners.
*Mostly based on https://github.com/PaulStoffregen/EEPROM*

 - **Importing the Library**
	+ I. Download the library [[.ZIP]](https://github.com/davbauer/storage-wrapper/archive/refs/heads/main.zip)
	+ II. Launch Arduino IDE and click *`[Sketch]`* *->* *`[Include Library]`* -> *`[Add .ZIP Library...]`* to import the library
- **Opening the example .ino file**
	+ I. In Arduino IDE click *`[File]`* *->* *`[Examples]`* -> *`[Storage]`* -> *`[basic]`* to open the example code
- **Finishing up**
	+ I. Make sure the library EEPROM is installed, if its not already installed you can download it [here](https://github.com/PaulStoffregen/EEPROM) and follow the steps from above to import it.
	---
	
	
	
- **Available Methods**

| Method-Name | Return-Type | What it does |
| ----------- | ----------- | ----------- |
| getStart()      			| int       | return start byte position |
| getEnd()   				| int        | return end byte position |
| getCache()   				| String        | return cached store value |
| clear()   				| void        | clear data from store|
| write(String/int/float/double)   	| void        | write data to store |
| readString()   			| String        | read data as string |
| read()   				| String        | read data as string |
| readInt()				| int        | read data as int |
| readDouble()   			| double        | read data as double |

- **Example Code**
	
	```C++
	#include <EEPROM.h> // https://github.com/PaulStoffregen/EEPROM
	#include <Storage.h> // https://github.com/davbauer/Storage

	Storage my_object(0, 20); // Define your Storage objects and from which
	Storage other_obj(20, 30); // byte to start and end writing

	void setup(void) {
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

	void loop(void) {
	  delay(1000);
	}
	```
	Final Output (Serial Monitor):
	
	``` text
	Data to save
	19
	19.86
	```
