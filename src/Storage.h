/*
  Storage.h - Library for storing data as bytes in Arduino's EEPROM
  Created by David Bauer, April 6, 2022.
*/

#ifndef Storage_h
#define Storage_h
  #include <Arduino.h>
  class Storage {
    public:
      Storage(int start, int end);
      int getStart();
      int getEnd();
      String getCache();

      void clear();

      void writeString(String text);
      void write(String text);
      void write(int val);
      void write(float val);
      void write(double val);

      String readString();
      String read();
      int readInt();
      double readDouble();

    private:
      int _start;
      int _end;
      String _cache;
      
  };
#endif