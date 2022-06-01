#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedList <int> L;
	LinkedList <int> O;
	LinkedList <int> E;
	int ListSize,element;
	cin >> ListSize;
	if (ListSize >= 1 && ListSize <= 1000000)
	{
		for(int i=0;i<ListSize;i++)
		{
			cin >> element;
			L.InsertEnd(element);
		}
		
		L.split(&O,& E, ListSize);
		
	
			O.printList();
			E.printList();
		
	
		
			
		
		
		
	}
}