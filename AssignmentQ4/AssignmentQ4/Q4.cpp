#include "LinkedQueue.h"
#include "ArrayStack.h"
#include <iostream>
using namespace std;
int main()
{
	int StackSize, QueueSize, stackelement, Queueelement;

	cin >> StackSize;
	if (StackSize >= 1 && StackSize <= 1000)
	{
		cin >> QueueSize;
		if (QueueSize >= 1 && QueueSize <= 1000)
		{	
			ArrayStack <int> stackinput(StackSize);
			ArrayStack <int> stackaltforstack(StackSize);
			ArrayStack <int> stackaltforqueue(QueueSize);
			ArrayStack <int> stacknew(QueueSize);
			LinkedQueue<int> Queueinput;
			LinkedQueue<int> Queuenew;
			for (int i = 0; i < StackSize; i++)
			{
				cin >> stackelement;
				stackinput.push(stackelement);
			}
			for (int j = 0; j < QueueSize; j++)
			{
				cin >> Queueelement;
				Queueinput.enqueue(Queueelement);
			}
		
			for (int i = 0; i <= StackSize; i++)
			{
				int reverse;
				stackinput.pop(reverse);
				stackaltforstack.push(reverse);
				
			}
			for (int i = 0; i <= StackSize; i++)
			{
				int popped;
				stackaltforstack.pop(popped);
				Queuenew.enqueue(popped);
			}
			for (int j = 0; j < QueueSize; j++)
			{
				int dequeued;
				Queueinput.dequeue(dequeued);
				stackaltforqueue.push(dequeued);
			}
			for (int j = 0; j < QueueSize; j++)
			{
				int exchange;
				stackaltforqueue.pop(exchange);
				stacknew.push(exchange);
			}
			stacknew.printstack();
			Queuenew.printqueue();
		}
	}

}