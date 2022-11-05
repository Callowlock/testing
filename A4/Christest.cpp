#include "DoublyLinkedList.cpp"
//#include "BigInteger.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    DoublyLinkedList<int> list;
    for(int i=0; i<10; i++){
        list.insertLast(i);
    }
    list.clear();
    list.printForward();
    cout << endl;
    list.printReverse();
    return 0;
}