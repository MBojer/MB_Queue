/*
MB Queue
Version 0.1
*/

#ifndef MB_Queue_Delay_h
  #define MB_Queue_Delay_h

  #include "Arduino.h"

  class MB_Queue_Delay {

    public:
      // --------------------------------------------- Setup ---------------------------------------------
      MB_Queue_Delay();


      // --------------------------------------------- Queue ---------------------------------------------
      void Push(String Push_String, unsigned long Run_Time);
      String Pop();
      String Peek();
      int Length();
      int Is_Empthy();
      void Clear();



    private:
      // --------------------------------------------- Queue ---------------------------------------------
      #define _Max_Queue_Length 10
      byte _Queue_Length = 0;
      bool _Queue_Is_Empthy = true;

      byte Lowest_Timer_Number;

      unsigned long _Queue_Timing[_Max_Queue_Length];
      String _Queue_String[_Max_Queue_Length]; // ";" is used as seperators betweens the string in the queue

  };

#endif
