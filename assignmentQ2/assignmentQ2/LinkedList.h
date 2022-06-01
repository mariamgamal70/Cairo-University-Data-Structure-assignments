#ifndef _LINKEDLIST
#define _LINKEDLIST
#pragma once
#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
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

	void InsertEnd(const T& data)
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
			while ( curr->getNext() != nullptr)
			{
				curr = curr->getNext();
			}
			curr->setNext(R);
			R->setNext(NULL);
		}
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

	void printList()
	{
		if (!Head)
		{
			return;
		}
		else
		{ 
		Node<T>* curr = Head;
		while (curr != nullptr)
		{
			cout << curr->getItem() << " ";
			curr = curr->getNext();

		}
		cout << endl;

		}
	}
	void rotate(LinkedList<T> *list,int n/*, int k*/)
	{
		if (!Head)
			return;	
		Node<T>* curr = Head;
		Node<T>* prev = NULL;
		while (curr->getNext() != nullptr)//traverse again to get tail and set its next to head
		{
			prev = curr;
			curr = curr->getNext();  
		}
		curr->setNext(Head); //set next of tail to head
		Head = curr; /*KthNode->getNext()*//*; *///head is now is the next of k-1 which is k
		prev->setNext(NULL);// set the next of k-1 to null to break the circular linked list;
	}
};

#endif	
