/*

 Eksample with two queues

*/


#include <Arduino.h>
#include <MB_Queue.h>

MB_Queue Send_Q(10);
MB_Queue Reci_Q(12);


void setup() {

  Serial.begin(115200);
  Serial.println("Boot");

  Reci_Q.Push("Reci_Q-1");
  Reci_Q.Push("Reci_Q-2");

  Send_Q.Push("Send_Q-1");
  Send_Q.Push("Send_Q-2");

  Serial.print("Send_Q.Peek_Queue(): ");
  Serial.println(Send_Q.Peek_Queue());

  Serial.print("Reci_Q.Peek_Queue(): ");
  Serial.println(Reci_Q.Peek_Queue());

}

void loop() {
    // put your main code here, to run repeatedly:
}
