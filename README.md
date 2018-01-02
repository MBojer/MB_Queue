# MB_Queue

MB_Queue "Queue Name"("Queue Size");

Push(Push_String, Add_To_Front_Of_Queue)
  Adds "Push_String" to the queue
    Add_To_Front_Of_Queue = true/false

Push(Push_String)
  Adds "Push_String" to the queue
    Action: Push(Push_String, Add_To_Front_Of_Queue = true)

Pop()
  Removed the first entry in the queue

Peek()
  Returns the first entry in the queue

Peek_Queue()
  Returns the entire queue

Length()
  Returns length of the queue

Is_Empthy()
  Returns true if the queue is empty

Clear()
  Clears the queue

Search_Peek(Search_String)
  Returns matching string if found

Search_Pop(Search_String, Delete_All_Matches)
  Returns matching string if found, and removes it from the queues
    Delete_All_Matches if true, all matches in the queue will be removed
