#ifndef _NODE
#define _NODE

//First let's declare a single node in the list
template<typename T>
class Node
{
private:
	T item;	// A data item (can be any complex sturcture)
	Node<T>* next;	// Pointer to next node
public:

	Node() //default constructor
	{
		next = nullptr;
	}

	Node(T newItem) //non-default constructor
	{
		item = newItem;
		next = nullptr;

	}

	void setItem(T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} // end setNext

	T getItem() const
	{
		return item;
	} // end getItem

	Node<T>* getNext() const
	{
		return next;
	}
}; // end Node

#endif	
#include <cmath>
#ifndef _LINKEDLIST
#define _LINKEDLIST
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:
	LinkedList()
	{
		Head = nullptr;
	}
	~LinkedList()//List is being desturcted ==> delete all items in the list
	{
		DeleteAll();
	}
	void InsertBeg(const T& data)//Creates a new node and adds it to the beginning of a linked list,
	//data : The value to be stored in the new node.

	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}

	void DeleteAll()//Deletes all nodes of the list.
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}
	int getDecimalValue(LinkedList* Binary,int ListSize) {
		int r = 0;
		int decimal = 0;
		while (Head && r!=ListSize) {

			decimal = decimal + ((Head->getItem()) * pow(2,r));
			Head = Head->getNext();
			r++;
		}
		return decimal;
	}

	};

#endif	


#include<iostream>
	using namespace std;
	int main()
	{
		LinkedList<int>B;
		int ListSize;
		int ListElement;
		int decimal;
		
		cin >> ListSize;
		if (ListSize <= 60 && ListSize >= 1)
		{
			for (int i = 0; i < ListSize; i++)
			{
				
				cin >> ListElement;
				if (ListElement == 1 || ListElement == 0)
				{
					B.InsertBeg(ListElement);
				}
				else 
				{
					break;
				}
			}

		}
		 decimal=B.getDecimalValue(&B,ListSize);
		cout <<decimal<< endl;
	}
