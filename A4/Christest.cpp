//#include "DoublyLinkedList.cpp"
#include "BigInteger.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    DoublyLinkedList<int> c;
    for(int i = 0; i < 10; i++) {
        c.insertLast(i);
    }
    c.printForward();
    return 0;
}