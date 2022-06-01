#include <iostream>
using namespace std;
#include "LinkedList.h"
int main()
{
	LinkedList<int> L;
	int SizeOfList;
	int KspacesToRotate;
	int element;
	cin >> SizeOfList;
	
	if (SizeOfList >= 1 && SizeOfList<= 100000)
	{
		cin >> KspacesToRotate;
		if(KspacesToRotate >= 1 && KspacesToRotate <=1000000000)
		{
			for (int i = 0; i < SizeOfList; i++)
			{
				cin >> element;
				L.InsertEnd(element);
			}
			KspacesToRotate = KspacesToRotate % SizeOfList;
			for(int j=0;j< KspacesToRotate;j++)
			{
			L.rotate(&L, SizeOfList/*, KspacesToRotate*/);
			}
			L.printList();
		}
	}

	




	/*L.rotate(&L, SizeOfList, KspacesToRotate);
	L.printList();
	L.rotate(&L, SizeOfList, KspacesToRotate);
	L.printList();
	L.rotate(&L, SizeOfList, KspacesToRotate);
	L.printList();*/

}