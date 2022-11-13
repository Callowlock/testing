#ifndef BIGINTEGER_CPP_
#define BIGINTEGER_CPP_

#include "BigInteger.h"
#include <iostream>
using namespace std;


//constructor with string, throws error if invalid input
BigInteger::BigInteger(string input){
    int i = 0;
    sign = false;
    storage = new DoublyLinkedList<int>();
    if (input[0]=='-') {
        sign = true;
        i++;
    }
    for(i; i < input.length(); i++) {
        if((int)input[i] < 48 || (int)input[i] > 57) {
            storage->clear();
            throw IllegalArgumentException();
        } else {
            storage->insertLast((int)input[i] - '0');
        }
    } 

}

//default constructor
BigInteger::BigInteger(){
    storage = new DoublyLinkedList<int>();
    sign = false;
}

BigInteger::~BigInteger() {
}

//returns true if negative
bool BigInteger::isNegative(){ //true is negative
    return sign;
}

//sets sign variable
void BigInteger::setSign(bool input){
    sign = input;
}

//returns size
int BigInteger::getSize(){
    return this->storage->getLength();
}

//returns size -- left in because it is used by client
int BigInteger::getLength(){
    return this->getSize();
}

//addition operator - handles different combinations of +/-
BigInteger BigInteger::operator+(BigInteger item){
    BigInteger temp = BigInteger();
    if (this->isNegative() && item.isNegative()){
        temp = this->plus(item);
        temp.setSign(true);
        return temp;
    }
    else if (!this->isNegative() && !item.isNegative()){
        temp = this->plus(item);
        return temp;
    }
    else if (!this->isNegative() && item.isNegative()){
        temp = this->minus(item);
        return temp;
    }
    else {
        temp = this->minus(item);
        return temp;
    }
}

//minus operator -- handles different combinations of +/-
BigInteger BigInteger::operator-(BigInteger item){
    BigInteger temp = BigInteger();
    if (this->isNegative() && item.isNegative()){
        temp = this->minus(item);
        temp.print();
        temp.setSign(true);
        return temp;
    }
    else if (!this->isNegative() && !item.isNegative()){
        temp = this->minus(item);
        return temp;
    }
    else if (!this->isNegative() && item.isNegative()){
        temp = this->plus(item);
        return temp;
    }
    else {
        temp = this->plus(item);
        temp.setSign(true);
        return temp;
    }
}

//helper method to add two BigIntegers together
BigInteger BigInteger::plus(BigInteger item){
    BigInteger temp = BigInteger();
    if (this->storage == item.storage){ //handles if the same object is being added to itself
        this->storage->setIteratorLast();
        int i;
        int remainder = 0;
        for (i = 0; i < this->getSize(); i++){
            int thisCurrent = this->storage->getData();
            int newCurrent = (thisCurrent * 2) + remainder;
            remainder = 0;
            if (newCurrent > 9){
                remainder = 1;
                newCurrent = newCurrent % 10;
            }
            temp.storage->insertFirst(newCurrent);
            this->storage->prev();
        }
        if (remainder == 1){
            temp.storage->insertFirst(remainder);
        }
        return temp;
    }
    item.storage->setIteratorLast();
    this->storage->setIteratorLast(); 
    if (this->getSize() > item.getSize()) { //item is smaller
        int i;
        int remainder = 0;
        for (i = 0; i < item.getSize(); i++){
            int itemCurrent = item.storage->getData();
            int thisCurrent = this->storage->getData();
            int newCurrent = itemCurrent + thisCurrent + remainder;
            remainder = 0;
            if (newCurrent > 9){
                remainder = 1;
                newCurrent = newCurrent % 10;
            }
            temp.storage->insertFirst(newCurrent);
            item.storage->prev();
            this->storage->prev();
        }
        for (int z = i; z < this->getSize(); z++){
            int newCurrent = this->storage->getData() + remainder;
            remainder = 0;
            if (newCurrent > 9){
                remainder = 1;
                newCurrent = newCurrent % 10;
            }
            temp.storage->insertFirst(newCurrent);
            this->storage->prev();
        }
        if (remainder == 1){
            temp.storage->insertFirst(remainder);
        }
        return temp;
    }
    else if (this->getSize() < item.getSize()) { //item is bigger
        int i;
        int remainder = 0;
        for (i = 0; i < this->getSize(); i++){
            int itemCurrent = item.storage->getData();
            int thisCurrent = this->storage->getData();
            int newCurrent = itemCurrent + thisCurrent + remainder;
            remainder = 0;
            if (newCurrent > 9){
                remainder = 1;
                newCurrent = newCurrent % 10;
            }
            temp.storage->insertFirst(newCurrent);
            item.storage->prev();
            this->storage->prev();
        }
        for (int z = i; z < item.getSize(); z++){
            int newCurrent = item.storage->getData() + remainder;
            remainder = 0;
            if (newCurrent > 9){
                remainder = 1;
                newCurrent = newCurrent % 10;
            }
            temp.storage->insertFirst(newCurrent);
            item.storage->prev();
        }
        if (remainder == 1) {
            temp.storage->insertFirst(remainder);
        }
        return temp;
    }
    else { //if this & item are the same size
        int i;
        int remainder = 0;
        for (i = 0; i < this->getSize(); i++){
            int itemCurrent = item.storage->getData();
            int thisCurrent = this->storage->getData();
            int newCurrent = itemCurrent + thisCurrent + remainder;
            remainder = 0;
            if (newCurrent > 9){
                remainder = 1;
                newCurrent = newCurrent % 10;
            }
            temp.storage->insertFirst(newCurrent);
            item.storage->prev();
            this->storage->prev();
        }
        if (remainder == 1){
            temp.storage->insertFirst(remainder);
        }
        return temp;
    }
}

//helper method to subtract two BigIntegers
BigInteger BigInteger::minus(BigInteger item){
    BigInteger temp = BigInteger();
    if (this->storage == item.storage){
        temp.storage->insertFirst(0);
        return temp;
    }
    item.storage->setIteratorLast();
    this->storage->setIteratorLast();
    if (this->getSize() > item.getSize()){
        int i;
        int remainder = 0;
        for (i = 0; i < item.getSize(); i++){
            int thisCurrent = this->storage->getData() + remainder; 
            int itemCurrent = item.storage->getData();
            remainder = 0;
            int newCurrent;
            if (thisCurrent >= itemCurrent){
                newCurrent = thisCurrent - itemCurrent;
            }
            else {
                newCurrent = (thisCurrent + 10) - itemCurrent;
                remainder = -1;
            }
            temp.storage->insertFirst(newCurrent);
            item.storage->prev();
            this->storage->prev();
        }
        for (int z = i; z < this->getSize() - 1; z++){
            int thisCurrent = this->storage->getData() + remainder;
            remainder = 0;
            if (thisCurrent == -1){
                thisCurrent = 9;
                remainder = -1;
            }
            temp.storage->insertFirst(thisCurrent);
            this->storage->prev();
        }
        int finCurrent = this->storage->getData() + remainder;
        if (finCurrent != 0){
            temp.storage->insertFirst(finCurrent);
        }
        return temp;
    }
    else if (this->getSize() < item.getSize()){
        int i;
        int remainder = 0;
        for (i = 0; i < this->getSize(); i++){
            int itemCurrent = item.storage->getData() + remainder;
            int thisCurrent = this->storage->getData(); 
            remainder = 0;
            int newCurrent;
            if (itemCurrent >= thisCurrent){
                newCurrent = itemCurrent - thisCurrent;
            }
            else {
                newCurrent = (itemCurrent + 10) - thisCurrent;  
                remainder = -1;
            }
            temp.storage->insertFirst(newCurrent);
            item.storage->prev();
            this->storage->prev();
        }
        for (int z = i; z < item.getSize(); z++){
            int thisCurrent = item.storage->getData() + remainder;
            remainder = 0;
            if (thisCurrent == -1){
                thisCurrent = 9;
                remainder = -1;
            }
            temp.storage->insertFirst(thisCurrent);
            item.storage->prev();
        }
        if (remainder != 0){
            temp.storage->insertFirst(1);
        }
        temp.setSign(true); //temp is now less than zero
        return temp;
    }
    else {
        if (this->checkGreaterThan(item) || this->checkEquality(item)){ //relies on >= operator
            int i;
            int remainder = 0;
            for (i = 0; i < item.getSize(); i++){
                int thisCurrent = this->storage->getData() + remainder; 
                int itemCurrent = item.storage->getData();
                remainder = 0;
                int newCurrent;
                if (thisCurrent >= itemCurrent){
                    newCurrent = thisCurrent - itemCurrent;
                }
                else {
                    newCurrent = (thisCurrent + 10) - itemCurrent;
                    remainder = -1;
                }
                temp.storage->insertFirst(newCurrent);
                item.storage->prev();
                this->storage->prev();
            }
        }
        else {
            int i;
            int remainder = 0;
            for (i = 0; i < item.getSize(); i++){
                int itemCurrent = item.storage->getData() + remainder;
                int thisCurrent = this->storage->getData(); 
                remainder = 0;
                int newCurrent;
                if (thisCurrent >= itemCurrent){
                    newCurrent = itemCurrent - thisCurrent;
                }
                else {
                    newCurrent = (thisCurrent + 10) - itemCurrent;
                    remainder = -1;
                }
                temp.storage->insertFirst(newCurrent);
                item.storage->prev();
                this->storage->prev();
            }
            if (temp.checkZero()){
                BigInteger temp2 = BigInteger("0");
                return temp2; 
            }
            temp.trimZero();
            temp.setSign(true); //temp is now less than 0
            return temp;
        }
    }
}

//this deletes leading zeros. ex: 000004568 -> 4568
void BigInteger::trimZero(){
    this->storage->setIteratorFirst();
    while (this->storage->getData() == 0){
        this->storage->next();
        this->storage->deleteFirst();
    }
}

//checks if the BigInteger == 0
bool BigInteger::checkZero(){
    this->storage->setIteratorFirst();
    while (this->storage->hasNext()){
        if (this->storage->getData() != 0){
            return false;
        }
        this->storage->next();
    }
    if (this->storage->getData() != 0){
        return false;
    }
    return true;
}

//evaluates if this is less than a BigInteger
bool BigInteger::checkLessThan(BigInteger item){
    /*Two positive numbers*/
    if (!this->isNegative() && !item.isNegative()) {
        if (this->getSize() < item.getSize()){
            return true;
        }
        else if (this->getSize() > item.getSize()){
            return false;

        }
        else {
            this->storage->setIteratorFirst();
            item.storage->setIteratorFirst();
            for (int i = 0; i < this->getSize(); i++){
                if (this->storage->getData() < item.storage->getData()){
                    return true;
                }
                else if (this->storage->getData() > item.storage->getData()){
                    return false;
                }
                this->storage->next();
                item.storage->next();
            }
            return false;
        }
    }
    else if (this->isNegative() && !item.isNegative()){ //left side negative
        return true;
    }
    else if (!this->isNegative() && item.isNegative()){ //right side negative
        return false;
    }
    else { //both negative
        if (this->getSize() < item.getSize()){
            return false;
        }
        else if (this->getSize() > item.getSize()){
            return true;
        }
        else {
            this->storage->setIteratorFirst();
            item.storage->setIteratorFirst();
            for (int i = 0; i < this->getSize(); i++){
                if (this->storage->getData() < item.storage->getData()){
                    return false;
                }
                else if (this->storage->getData() > item.storage->getData()){
                    return true;
                }
                this->storage->next();
                item.storage->next();
            }
            return false;
        }
    }
}

//evaluates if this is greater than a BigInteger
bool BigInteger::checkGreaterThan(BigInteger item){
    /*both positive*/
    if (!this->isNegative() && !item.isNegative()) {
        if (this->getSize() > item.getSize()){
            return true;
        }
        else if (this->getSize() < item.getSize()){
            return false;
        }
        else {
            this->storage->setIteratorFirst();
            item.storage->setIteratorFirst();
            
            while (!this->storage->isIteratorNULL() && !item.storage->isIteratorNULL()){
                if (this->storage->getData() > item.storage->getData()){
                    return true;
                }
                else if (this->storage->getData() < item.storage->getData()){
                    return false;
                }
                this->storage->next();
                if (this->storage->isIteratorNULL()){
                    return false;
                }
                item.storage->next();
            }
            return false;
        }
    }
    else if (!this->isNegative() && item.isNegative()){ //right side negative
        return true;
    }
    else if (this->isNegative() && !item.isNegative()){ //left side negative
        return false;
    }
    else { //both negative
        if (this->getSize() < item.getSize()){
            return true;
        }
        else if (this->getSize() > item.getSize()){
            return false;
        }
        else {
            this->storage->setIteratorFirst();
            item.storage->setIteratorFirst();
            for (int i = 0; i < this->getSize(); i++){
                if (this->storage->getData() < item.storage->getData()){
                    return true;
                }
                else if (this->storage->getData() > item.storage->getData()){
                    return false;
                }
                this->storage->next();
                item.storage->next();
            }
            return false;
        }
    }
}

//checks if this is equal to item ex: 100 == 100 evaluates TRUE
bool BigInteger::checkEquality(BigInteger item){
    if (this->getSize() != item.getSize()) {
        return false;
    }
    else {
        if ((this->isNegative() && !item.isNegative()) || (!this->isNegative() && item.isNegative())){
            return false;
        }
        else {
            this->storage->setIteratorFirst();
            item.storage->setIteratorFirst();
            while (!this->storage->isIteratorNULL()){
                if (this->storage->getData() != item.storage->getData()){
                    return false;
                }
                this->storage->next();
                item.storage->next();
                
            }
            return true;
        }
    }
}

//overload > operator
bool BigInteger::operator>(BigInteger item){
    return this->checkGreaterThan(item);
}

//overload < operator
bool BigInteger::operator<(BigInteger item){
    return this->checkLessThan(item);
}

//overload == operator
bool BigInteger::operator==(BigInteger item){
    return this->checkEquality(item);
}

//overload >= operator
bool BigInteger::operator>=(BigInteger item){
    if (this->checkGreaterThan(item) || this->checkEquality(item)){
        return true;
    }
    else {
        return false;
    }
}

//overload <= operator
bool BigInteger::operator<=(BigInteger item){
    if (this->checkLessThan(item) || this->checkEquality(item)){
        return true;
    }
    else {
        return false;
    }
}

//overload assignment = operator
BigInteger BigInteger::operator=(BigInteger item){
    storage = item.storage;
    sign = item.sign;
}

//overload << operator
ostream& operator<<(ostream& out, BigInteger item){
    if (item.isNegative()){
        out << '-';
    }
    item.storage->setIteratorFirst();
    while (!item.storage->isIteratorNULL()){
        out << item.storage->getData();
        item.storage->next();
    }
    return out;
}

/*TODO overload >> operator*/
istream& operator>>(istream& in, BigInteger item){
    bool tempBool = false;
        while(in.good()) {
            char c = in.get();
            if(c == '\n' || in.good() == false){
                break;
            } else if(c == '-'){
                item.setSign(true);
            } else if ((int)c < 48 || (int)c > 57) {
                item.storage->clear();
                throw IllegalArgumentException();
            } else {
                item.storage->insertLast((int)c - '0');
            }
        }
   return in;

}

//helper print method for testing
void BigInteger::print(){
    this->storage->setIteratorFirst();
    while (!this->storage->isIteratorNULL()){
        int s = this->storage->getData();
        cout << s;
        this->storage->next();
    }
    cout << endl;
}
#endif