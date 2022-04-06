/*
  Basic example for Storage.h library
 
  IMPORTANT: 
  Everything will be stored as strings (even int´s or float´s) to make it as easy as possible to work with.
  Since the library caches everything you read and write, the library is touching the EEPROM as little as possible.
*/

#include <EEPROM.h> // https://github.com/PaulStoffregen/EEPROM
#include <Storage.h> // https://github.com/davbauer/Storage

// Create your Storage objects
// Storage obj_name(<start_byte>, <end_byte>);
// Amount of storage is defined in line 23
Storage name(0, 10);
Storage temperature(20, 30);

void setup() {
  Serial.begin(115200);
  Serial.println();

  // Set the amount of bytes you can store in your EEPROM
  EEPROM.begin(512);

  // Example of writing and reading data in various data types
  name.write("Lee Thomps");
  Serial.println(name.read());

  temperature.write(12.73);
  Serial.println(temperature.readString());
  Serial.println(temperature.readDouble());
  Serial.println(temperature.readInt());
}

void loop() {
  delay(10000);
}