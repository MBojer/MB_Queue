/*

 Eksample with two queues

*/


#include <Arduino.h>
#include <MB_Queue.h>
#include <MB_Queue_Delay.h>

MB_Queue Send_Q(10);
MB_Queue Reci_Q(12);

MB_Queue_Delay Delay_Queue;


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

    Delay_Queue.Push("Test Setup", millis() + 1000);
    Delay_Queue.Push("Test Setup1", millis() + 1500);
    Delay_Queue.Push("Test Setup2", millis() + 2000);
    Delay_Queue.Push("Test Setup3", millis() + 2500);

    Serial.println(Delay_Queue.Show());

    delay(500);
  }


}

void loop() {

  if (Delay_Queue.Peek() != "") {
    Serial.print("Delay_Queue.Pop(): ");
    Serial.println(Delay_Queue.Pop());
  }

  delay(100);

    // put your main code here, to run repeatedly:
}
