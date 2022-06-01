#include "LinkedQueue.h"
#include "ArrayStack.h"
#include <iostream> 
using namespace std;

template <typename T>
ArrayStack<T> Reverse(ArrayStack<T> S)
{
	ArrayStack<T> Rev(S.getCapacity());	//First creat a stack 
	T Item;
	while (S.pop(Item))	//pop from S
		Rev.push(Item); //push into Rev

	return Rev;
}
/*template <typename T>
void PrintStack(ArrayStack<T> S)
{
	T x;
	while (S.pop(x))
		cout << x << " ";

	cout << endl;
}*/
int main()
{
	int NumberOfStudents;
	bool InvalidStudentsInput = false;
	bool InvalidSandwichInput = false;
	cin >> NumberOfStudents;
	if (NumberOfStudents >= 1 && NumberOfStudents <= 100)
	{
		LinkedQueue <int> Students;
		int StudentPreference;
		for (int i = 0; i < NumberOfStudents; i++)
		{
			cin >> StudentPreference;
			if (StudentPreference == 1 || StudentPreference == 0)
			{
				Students.enqueue(StudentPreference);
			}
			else
			{
				InvalidStudentsInput = true;
				break;
			}
		}
		if (!InvalidStudentsInput)
		{
			//cout << "students" << endl;
			//Students.printqueue();
			//cout << endl;
		
			ArrayStack <int> Sandwichs(NumberOfStudents);
			int FoodType;
			for (int j = 0; j < NumberOfStudents; j++)
			{
				cin >> FoodType;
				if (FoodType == 1 || FoodType == 0)
				{
					Sandwichs.push(FoodType);
				}
				else
				{
					InvalidSandwichInput = true;
					break;
				}
			}
			if (!InvalidSandwichInput)
			{
				/*cout << "sandwichs" << endl;*/
				/*PrintStack(Sandwichs);*/

				ArrayStack <int> Sandwichsreversed = Reverse(Sandwichs);

				//cout << "reversed sandwichs" << endl;
				//PrintStack(Sandwichsreversed);

				int SandVal, PrefVal, eaten, taken;
				int starving = NumberOfStudents;
				int traversalcounter=0;
				while (Sandwichsreversed.peek(SandVal) && Students.peek(PrefVal))
				{
					
					if (SandVal == PrefVal)
					{
						Sandwichsreversed.pop(eaten);
						/*PrintStack(Sandwichsreversed);*/
						Students.dequeue(taken);
						/*Students.printqueue();*/
						starving--;
						NumberOfStudents--;
						traversalcounter = 0;
					}
					else
					{
						if (traversalcounter == NumberOfStudents)
						{
							break;
						}
						Students.TraverseCircular();
						traversalcounter++;
						/*Students.printqueue();*/
					}
				}
				cout << starving;
			}
		}
	}
}