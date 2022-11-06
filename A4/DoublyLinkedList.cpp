#include "DoublyLinkedList.h"
#include <iostream>


//default no-argument constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    first = nullptr;
    last = nullptr;
    length = 0;

}


// destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while(!isEmpty()) {
        deleteLast();
    }

}

// copy constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &other){
    if (other.length > 0) {
        Node<T> *oth = other.first;
        Node<T> *newNode = new Node<T>;
        newNode->data = oth->data;
        first = newNode;
        first->next = nullptr;
        length = 1;

        oth = oth->next;
        Node<T> *curr = first;

        while(oth!=nullptr) {
            Node<T> *temp = new Node<T>;
            temp->data = oth->data;
            curr->next = temp;
            temp->prev = curr;
            curr = temp;
            oth = oth->next;
            length++;
        }
        last = curr;
        curr->next = nullptr;
    }    
}

// copy assignment operator
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &other){
    if(other.length > 0) {
        while(!isEmpty()) {
            deleteLast();
        }
            
        Node<T> *oth = other.first;
        Node<T> *newNode = new Node<T>;
        newNode->data = oth->data;
        first = newNode;
        first->next = nullptr;
        length = 1;

        oth = oth->next;
        Node<T> *curr = first;

        while(oth!=nullptr) {
            Node<T> *temp = new Node<T>;
            temp->data = oth->data;
            curr->next = temp;
            temp->prev = curr;
            curr = temp;
            oth = oth->next;
            length++;
        }
        last = curr;
        curr->next = nullptr;
        length = other.length();  
    }
}

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
    return iterator->prev != nullptr;
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
bool DoublyLinkedList<T>::isIteratorNULL(){
    return iterator == nullptr;
}

// gets the data the iterator pointing at
template <class T>
T DoublyLinkedList<T>::getData(){
    return iterator->data;
}

// friend functions
// overloading operator<<
template <class U>
ostream& operator<<(ostream &out, const DoublyLinkedList<U> &in){
    auto *curr = in.first;
    out << "NULL<-";
    while(curr->next!=nullptr) {
        out << curr->data << "<->";
        curr= curr->next;
    }
    out << curr->data << "->NULL";
    return out;

}

// overloading operator>>
template <class U>
istream& operator>>(istream &in, DoublyLinkedList<U> &dLinkedList){
    while(in.good()) {
        int c = in.get();
        if(c == '\n') {
            break;
        }
        dLinkedList.insertLast((int)c-'0');
    }
}

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