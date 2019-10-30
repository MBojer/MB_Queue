/*
MB Queue
Version 0.3

Changelog
-- 0.03
- Added Set_Marker()

-- 0.02
- Added SetQueueLength()
*/

#ifndef MB_Queue_h
  #define MB_Queue_h

  #include "Arduino.h"

  class MB_Queue {

    public:
      // --------------------------------------------- Setup ---------------------------------------------
      MB_Queue(int Max_Queue_Length);


      // --------------------------------------------- Queue ---------------------------------------------
      void Push(String Push_String, bool Add_To_Front_Of_Queue);
      void Push(String Push_String);
      String Pop();
      String Peek();
      String Peek_Queue();
      int Length();
      void Clear();
      String Search_Peek(String Search_String);
      String Search_Pop(String Search_String, bool Delete_All_Matches);

      bool Queue_Is_Empthy = true;

      void SetMarker(String Queue_Marker);
      void SetQueueLength(byte Queue_Length);


    private:
      // --------------------------------------------- Queue ---------------------------------------------
      String _Queue_Marker = ";";
      int _Max_Queue_Length;
      int _Queue_Length = 0;
      // ";" normally is used as seperators betweens the string in the queue
      String _Queue_String = _Queue_Marker; 
  };

#endif
