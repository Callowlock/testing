#include "DoublyLinkedList.h"
#include <iostream>


// default no-argument constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    first = nullptr;
    last = nullptr;
    length = 0;
    std :: cout << "C ";

}


// destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    std :: cout << " D";

}

// copy constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &other){

}

// copy assignment operator
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &other){}



// returns true if the list is empty, false otherwise
template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return length == 0;
}

// returns the number of items in the list
template <class T>
int DoublyLinkedList<T>::getLength(){
    return length;
}

// inserts a new item to the beginning of the list
template <class T>
void DoublyLinkedList<T>::insertFirst(const T &item){
    Node<T>* newNode = new Node<T>;
    newNode->data = item;
    if(first == nullptr) {
        first = newNode;
        last = newNode;
        last->next = nullptr;
        length++;
    } else {
        newNode->next = first;
        first = newNode;
        newNode->next->prev = newNode;
        first->prev = nullptr;
        length++;
    }    
}

// inserts a new item at the end of the list
template <class T>
void DoublyLinkedList<T>::insertLast(const T &item){
    Node<T>* newNode = new Node<T>;
    newNode->data = item;
    newNode->next, newNode->prev = nullptr, nullptr;
    if(last == nullptr) {
        first = newNode;
        last = newNode;
        last->next = nullptr;
        length++;
    } else {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
        newNode->next = nullptr;
        length++;
    }

}

// deletes the first item from the list
template <class T>
void DoublyLinkedList<T>::deleteFirst(){
   // Node<T> *current = first->next;
    first = first->next;
    first->prev = nullptr;
    length--;

}

// deletes the last item in the list
template <class T>
void DoublyLinkedList<T>::deleteLast(){
    last = last->prev;
    last->next = nullptr;
    length--;
}

// destroys the list and makes it empty
template <class T>
void DoublyLinkedList<T>::clear(){
    length = 0;
    first = nullptr;
    last = nullptr;
}

// iterator functions
// sets the iterator to the beginning of the linked list
template <class T>
void DoublyLinkedList<T>::setIteratorFirst(){
    iterator = first;
}

// sets the iterator to the beginning of the linked list
template <class T>
void DoublyLinkedList<T>::setIteratorLast(){
    iterator = last;
}

// checks if the iterator has next
template <class T>
bool DoublyLinkedList<T>::hasNext(){
    return iterator->next != nullptr;
}

// checks if the iterator has prev
template <class T>
bool DoublyLinkedList<T>::hasPrev(){
    return iterator->prev !=nullptr;
}

// sets the iterator to the next node
template <class T>
void DoublyLinkedList<T>::next(){
    iterator = iterator->next;
}

// sets the iterator to the previous node
template <class T>
void DoublyLinkedList<T>::prev(){
    iterator = iterator->prev;
}

// returns true if the iterator is null
template <class T>
bool isIteratorNULL(){
}

// gets the data the iterator pointing at
template <class T>
T DoublyLinkedList<T>::getData(){
    return iterator->data;
}

// friend functions
// overloading operator<<
template <class U>
ostream& operator<<(ostream &out, const DoublyLinkedList<U> &){}

// overloading operator>>
template <class U>
istream& operator>>(istream &in, DoublyLinkedList<U> &){}


template <class T>
void DoublyLinkedList<T> :: printReverse() {
    Node<T>* curr = last;
    do {
        std::cout << curr->data << " ";
        curr = curr->prev;
    } while(curr!= nullptr);

}
template <class T>
void DoublyLinkedList<T> :: printForward() {
    
    Node<T>* curr = first;
    do{
        std::cout << curr->data << " ";
        curr = curr->next;
    }
     while(curr!= nullptr);

}