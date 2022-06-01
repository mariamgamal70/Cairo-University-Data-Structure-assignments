#include "ArrayStack.h"
#include "StackADT.h"
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
template <typename T>
int checkscores(int NoOfOperations, string input[])
{
	string x;
	int count = 0;
	ArrayStack <int>* results=new ArrayStack<int>(count);
	for (int i = 0; i < NoOfOperations; i++)
	{
		if (input[i] != "+" && input[i] != "D")
		{
			int score=stoi(input[i]);
			results->push(score);
			count++;
		}
		else if (input[i] == "+" && count > 2)
		{
			int x, y, sum;
			results->pop(x);
			results->peek(y);
			sum = x + y;
			results->push(x);
			results->push(sum);
			count++;
		}
		else if (input[i] == "D" && count > 1)
		{
			int z;
			//int z2;
			results->pop(z);
			
		}
	}
	int sumscores = 0;
	for (int j = 0; j < count; j++)
	{
		int x;
		results->pop(x);
		sumscores += x;
	}
	return sumscores;
}
using namespace std;
int main()
{
	string x;
	int NoOfOperations;
	cin >> NoOfOperations;
	string* input = new string[NoOfOperations];
	if (NoOfOperations >= 1 && NoOfOperations <= 1000)
	{
		for (int i = 0; i < NoOfOperations; i++)
		{
			cin >> x;
			if (x == "+" || x == "D")
			{
				input[i]=x  ;
			}
			else if (stoi(x)>-1000 && stoi(x)< 1000)
			{
				input[i] =x ;
			}
			else
			{
				break;
			}
		}
		//int totalscore = checkscores<int>(NoOfOperations,input);
		int count = 0;
		int x, y, sum;
		int z;
		ArrayStack <int> results (1000);
		for (int j = 0; j < NoOfOperations; j++)
		{
			if (input[j] == "+" )
			{
				
				results.pop(x);
				results.peek(y);
				sum = x + y;
				results.push(x);
				results.push(sum);
			}
			else if (input[j] == "D" )
			{
				
				results.pop(z);

			}
			else
			{
				results.push(stoi(input[j]));
			}
			/*cout << totalscore << endl;*/
		}
		int sumscores = 0;
		while(!results.isEmpty())
		{
			results.pop(x);
			sumscores += x;
		}
		cout << sumscores<<endl;
	}
}

