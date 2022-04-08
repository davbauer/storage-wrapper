/*
  Storage.cpp - Library for easily storing data in Arduino's EEPROM
  Created by David Bauer, April 6, 2022.
*/

#include "Storage.h"
#include <EEPROM.h>

Storage::Storage(int start, int end) {
  _start = start;
  _end = end;
}

int Storage::getStart() {
  return _start;
}

int Storage::getEnd() {
  return _end;
}

String Storage::getCache() {
  return _cache;
}

void Storage::clear() {
  for (int i = _start; i < _end; i++) EEPROM.write(i, 0);
  EEPROM.commit();
  _cache = "";
}

void Storage::writeString(String text) {
  if (_cache != text) {
    _cache = text;
    for (int i = _start; i < _end; i++) EEPROM.write(i, 0); 
    for (int i = 0; ((i < text.length()) && (i < (_end - _start))); i++) EEPROM.write(i + _start, text[i]); 
    EEPROM.commit(); 
  }   
}

void Storage::write(String text) {
  writeString(text);
}

void Storage::write(int val) {
  writeString(String(val));
}

void Storage::write(double val) {
  writeString(String(val));
}

void Storage::write(float val) {
  writeString(String(val));
}

String Storage::readString() {
  String temp_read = ""; 
  if (_cache == NULL) {
    for (int i = _start; i < _end; i++) if (char(EEPROM.read(i)) != '\0') temp_read += char(EEPROM.read(i)); 
  } else {
    temp_read = _cache;
  }
  return temp_read; 
}

String Storage::read() {
  return readString(); 
}

int Storage::readInt() {
  return readString().toInt();
}

double Storage::readDouble() {
  return readString().toDouble(); 
}
