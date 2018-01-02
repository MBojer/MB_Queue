/*

 Eksample with two queues

*/


#include <Arduino.h>
#include <MB_Queue.h>
#include <MB_Queue_Delay.h>

MB_Queue Send_Q(10);
MB_Queue Reci_Q(12);

MB_Queue_Delay Delay_Queue;

#define Check_In_Ms 750
unsigned long Check_In;


void setup() {

  Serial.begin(115200);
  Serial.println("Boot");

  { // MB_Queue
    Reci_Q.Push("Reci_Q-1");
    Reci_Q.Push("Reci_Q-2");

    Send_Q.Push("Send_Q-1");
    Send_Q.Push("Send_Q-2");

    Serial.print("Send_Q.Peek_Queue(): ");
    Serial.println(Send_Q.Peek_Queue());

    Serial.print("Reci_Q.Peek_Queue(): ");
    Serial.println(Reci_Q.Peek_Queue());
  }

  { // MB_Queue_Delay

    Delay_Queue.Push("Test Setup", 1000);
    Delay_Queue.Push("Test Setup1", 1500);
    Delay_Queue.Push("Test Setup2", 2000);
    Delay_Queue.Push("Test Setup3", 2500);

    delay(500);
  }


}

void loop() {

  if (Check_In < millis()) {

    Serial.println("Delay_Queue.Show(): ");
    Serial.println(Delay_Queue.Show());
    if (Delay_Queue.Peek() != "") {

      Serial.print("Delay_Queue.Pop(): ");
      Serial.println(Delay_Queue.Pop());
    }

    Check_In = millis() + Check_In_Ms;
  }

  Delay_Queue.Push("T2N1V100", 500);
  // Delay_Queue.Push("T2N1V100", 1000);

  delay(100);

    // put your main code here, to run repeatedly:
}
