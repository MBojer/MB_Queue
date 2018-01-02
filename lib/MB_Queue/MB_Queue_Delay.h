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
      void Clear();
      String Show();

      bool Queue_Is_Empthy = true;


    private:
      // --------------------------------------------- Queue ---------------------------------------------
      #define _Max_Queue_Length 10
      byte _Queue_Length = 0;

      byte _Lowest_Timer_Number;

      unsigned long _Queue_Timing[_Max_Queue_Length];
      String _Queue_String[_Max_Queue_Length]; // ";" is used as seperators betweens the string in the queue

  };

#endif
