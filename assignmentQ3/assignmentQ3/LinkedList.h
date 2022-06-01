#pragma once
#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
#include <cstddef>
using namespace std;

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

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}


	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}
	void InsertEnd(const T& data) //Create new node at the end of the list
	{
		Node<T>* R = new Node<T>(data);
		Node<T>* curr = Head;
		if (!Head)
		{
			Head = R;
			R->setNext(NULL);
		}
		else
		{
			while (curr->getNext() != nullptr)
			{
				curr = curr->getNext();
			}
			curr->setNext(R);
			R->setNext(NULL);
		}
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void printList()
	{
		Node<T>* curr = Head;
		while (curr != nullptr)
		{
			cout << curr->getItem() << " ";
			curr = curr->getNext();

		}
		cout << endl;

	}

	void split(LinkedList<T>* Odd, LinkedList<T>* Even, int ListSize)
	{
		int OddListSize;
		/*int EvenListSize;*/
		if (ListSize % 2 != 0)
		{
			OddListSize = (ListSize / 2) + 1; /*ciel(ListSize / 2)*/
			/*EvenListSize = ListSize - OddListSize;*/
		}
		else
		{
			OddListSize = ListSize / 2;
			/*EvenListSize = ListSize - OddListSize;*/

		}
		Node<T>* curr = Head;
		
		int count = 0;
		while (curr)
		{
			count++;
			if (count <= OddListSize)
			{
				Odd->InsertEnd(curr->getItem());
			}
			else
			{
				Even->InsertEnd(curr->getItem());
			}
			curr = curr->getNext();
			
		}

	}


};

#endif	
