/*

MB_Queue_Delay

*/


// --------------------------------------------- WBus ---------------------------------------------

#include "Arduino.h"
#include "MB_Queue_Delay.h"

// --------------------------------------------- Setup ---------------------------------------------

MB_Queue_Delay::MB_Queue_Delay() {

  Clear();

} // MB_Queue_Delay

// --------------------------------------------- Queue ---------------------------------------------

void MB_Queue_Delay::Push(String Push_String, unsigned long Run_Time) {

  if (_Queue_Is_Empthy == true) {
    _Queue_Length = 1;
    _Queue_Is_Empthy = false;

    _Queue_Timing[0] = Run_Time;
    _Queue_String[0] = Push_String;
  }


  else if (_Queue_Length >= _Max_Queue_Length - 1) { // Queue full using last spot

    _Queue_Length = _Max_Queue_Length;
    _Queue_Is_Empthy = true;

    _Queue_Timing[_Max_Queue_Length - 1] = Run_Time;
    _Queue_String[_Max_Queue_Length - 1] = Push_String;

    // CHANGE ME - Error reporting !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }


  else {
    _Queue_Length++;
    _Queue_Is_Empthy = false;

    for (byte i = 0; i < _Max_Queue_Length; i++) { // Find the next free spot in the queue
      if (_Queue_Timing[i] == 0) {
        _Queue_Timing[i] = Run_Time;
        _Queue_String[i] = Push_String;
      } // if

    } // for

  } // else

} // End Marker for Push

String MB_Queue_Delay::Pop() {

  String Temp_String = Peek();

  if (Temp_String != "") {
    _Queue_Timing[Lowest_Timer_Number] = 0;
    _Queue_String[Lowest_Timer_Number] = "";

    if (_Queue_Length == 1) {
      _Queue_Length = 0;
      _Queue_Is_Empthy = true;
    }

    else _Queue_Length = _Queue_Length - 1;

    return Temp_String;
  }

  return "";

} // End Marker for POP

String MB_Queue_Delay::Peek() {

  if (_Queue_Is_Empthy == true) return ""; // Well nothing to do might as well quit

  unsigned long Lowest_Timer = 0;
  Lowest_Timer_Number = 255;

  for (byte i = 0; i < _Max_Queue_Length; i++) {

    if (_Queue_Timing[i] == 0) ; // Do nothing

    else if (Lowest_Timer == 0) { // First hit
      Lowest_Timer = _Queue_Timing[i];
      Lowest_Timer_Number = i;
    }

    else if (Lowest_Timer > _Queue_Timing[i]) {
      Lowest_Timer = _Queue_Timing[i];
      Lowest_Timer_Number = i;
    }

  } // for


  if (Lowest_Timer_Number == 255) return ""; // No match found

  if (Lowest_Timer < millis()) {
    return _Queue_String[Lowest_Timer_Number];
  }

  return "";

} // End Marker for Peek

int MB_Queue_Delay::Length() {
  return _Queue_Length;
}

int MB_Queue_Delay::Is_Empthy() {
  return _Queue_Is_Empthy;
}

void MB_Queue_Delay::Clear() {

  for (byte i = 0; i < _Max_Queue_Length; i++) {
    _Queue_Timing[i] = 0;
    _Queue_String[i] = "";
  } // for

  _Queue_Length = 0;
  _Queue_Is_Empthy = true;

} // MB_Queue_Delay::Clear()
