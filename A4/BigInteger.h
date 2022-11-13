#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_
#include <stdexcept>
#include "DoublyLinkedList.h"

// Error class to deal with invalid inputs
class IllegalArgumentException : public exception {
    public:
        IllegalArgumentException() {
        }    
};


class BigInteger
{
private:

    bool sign;

    BigInteger plus(BigInteger item);

    BigInteger minus(BigInteger item);

    bool checkGreaterThan(BigInteger item);

    bool checkLessThan(BigInteger item);
    
    bool checkEquality(BigInteger item);

    int getSize();

    bool checkZero();

    void trimZero();
        

public:

    DoublyLinkedList<int>* storage;

    BigInteger(string input);

    BigInteger();


    void print();

    virtual ~BigInteger();

    int getLength();

    void setSign(bool input);

    bool isNegative();

    BigInteger operator+(BigInteger item);

    BigInteger operator-(BigInteger item);

    bool operator<=(BigInteger item);

    bool operator>=(BigInteger item);

    bool operator==(BigInteger item);

    bool operator>(BigInteger item);

    bool operator<(BigInteger item);

    BigInteger operator=(BigInteger item);

    friend ostream& operator<<(ostream& out, BigInteger item);

    friend istream& operator>>(istream& in, BigInteger item);

    
};

//#include "BigInteger.cpp"
#endif
