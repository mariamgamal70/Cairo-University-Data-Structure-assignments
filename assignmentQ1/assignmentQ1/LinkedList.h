#ifndef _LINKEDLIST
#define _LINKEDLIST
#include "Node.h"
template <typename T>
class LinkedList
{
private:
    Node<T>* Head;    //Pointer to the head of the list
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
    int getDecimalValue(LinkedList* Binary, int ListSize) {
        int r = 0;
        int decimal = 0;
        while (Head && r != ListSize) {

            decimal = decimal + ((Head->getItem()) * pow(2, r));
            Head = Head->getNext();
            r++;
        }
        return decimal;
    }

};

#endif    
