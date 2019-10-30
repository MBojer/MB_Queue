/*

MB_Queue

*/


// --------------------------------------------- WBus ---------------------------------------------

#include "Arduino.h"
#include "MB_Queue.h"

// --------------------------------------------- Setup ---------------------------------------------

MB_Queue::MB_Queue(int Max_Queue_Length) {

  _Max_Queue_Length = Max_Queue_Length;

} // Setup

// --------------------------------------------- Queue ---------------------------------------------

void MB_Queue::Push(String Push_String, bool Add_To_Front_Of_Queue) {

  if (Queue_Is_Empthy == true) {
    _Queue_String = Push_String + _Queue_Marker;
    _Queue_Length = 1;
    Queue_Is_Empthy = false;
  }

  else {
    _Queue_String = _Queue_String + Push_String + _Queue_Marker;
    _Queue_Length++;
    Queue_Is_Empthy = false;
  }

  if (_Queue_Length >= _Max_Queue_Length) {
    // CHANGE ME - Error reporting !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    _Queue_String = _Queue_Marker;
    _Queue_Length = 0;
    Queue_Is_Empthy = true;
  }

} // End Marker for Push

void MB_Queue::Push(String Push_String) { // Refferance only
  Push(Push_String, false);
}

String MB_Queue::Pop() {

  String Pop_String;

  if (Queue_Is_Empthy == true) {
    return _Queue_Marker;
  }

  else {
    Pop_String = _Queue_String.substring(0, _Queue_String.indexOf(_Queue_Marker));

    _Queue_String.remove(0, _Queue_String.indexOf(_Queue_Marker) + 1);
    _Queue_Length--;

    if (_Queue_String.length() <= 3 || _Queue_Length < 1) {
      _Queue_String = _Queue_Marker;
      _Queue_Length = 0;
      Queue_Is_Empthy = true;
    }

    return Pop_String;

  } // End Marker for Else
} // End Marker for POP

String MB_Queue::Peek() {

  if (_Queue_String == _Queue_Marker) {
    return _Queue_Marker;
  }

  else {
    return _Queue_String.substring(0, _Queue_String.indexOf(_Queue_Marker));
  }

} // End Marker for Peek

String MB_Queue::Peek_Queue() {
  return _Queue_String;
}

int MB_Queue::Length() {
  return _Queue_Length;
}

void MB_Queue::Clear() {
  _Queue_String = _Queue_Marker;
  _Queue_Length = 0;
  Queue_Is_Empthy = true;
}

String MB_Queue::Search_Peek(String Search_String) {

  if (_Queue_String.indexOf(Search_String) >= 0) {

    String Search_Peek_String = _Queue_String.substring(0, _Queue_String.indexOf(Search_String) + Search_String.length());

    if (Search_Peek_String.indexOf(_Queue_Marker) <= 0) {
      return Search_Peek_String;
    }

    else {
      Search_Peek_String = Search_Peek_String.substring(Search_Peek_String.lastIndexOf(_Queue_Marker) + 1, Search_Peek_String.length());
      return Search_Peek_String;
    }
  }

  return _Queue_Marker;
}

String MB_Queue::Search_Pop(String Search_String, bool Delete_All_Matches) {

  if (_Queue_String.indexOf(Search_String) >= 0) {
    String Search_Pop_String = _Queue_String.substring(0, _Queue_String.indexOf(Search_String) + Search_String.length());

    if (Search_Pop_String.indexOf(_Queue_Marker) <= 0) {
      _Queue_String = _Queue_String.substring(Search_Pop_String.length() + 1);
    }


    else {
      Search_Pop_String = Search_Pop_String.substring(Search_Pop_String.lastIndexOf(_Queue_Marker) + 1, Search_Pop_String.length());

      _Queue_String = _Queue_String.substring(0, _Queue_String.indexOf(Search_Pop_String)) + _Queue_String.substring(_Queue_String.indexOf(Search_Pop_String) + Search_Pop_String.length() + 1 , _Queue_String.length());
    }

    _Queue_Length--;


    if (Delete_All_Matches == true) {
      _Queue_String.replace(Search_Pop_String + _Queue_Marker, "");

      _Queue_Length = _Queue_String.indexOf(_Queue_Marker) + 1;
    }


    if (_Queue_String.length() <= 3 || _Queue_Length < 1) {
      _Queue_String = _Queue_Marker;
      _Queue_Length = 0;
      Queue_Is_Empthy = true;
    }

    return Search_Pop_String;
  }

  return _Queue_Marker;
}

void MB_Queue::SetQueueLength(byte Queue_Length) {

  // Clear queue for good measure
  Clear();
  // Set new queue length
  _Max_Queue_Length = Queue_Length;

}

void MB_Queue::SetMarker(String Queue_Marker) {

  // Clear queue for good measure
  Clear();
  // Set queue Marker
  _Queue_Marker = Queue_Marker;

}
