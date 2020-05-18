#pragma once
#include <iostream>
using namespace std;
class Objects{
public:
    virtual ~Objects() {}
    virtual float A() = 0;
    virtual ostream& print(ostream& os) = 0;
    friend ostream& operator<<(ostream& os, Objects& other){
        return other.print(os);
    }
    bool operator > (Objects& other){
        if (this->A() > other.A())
            return true;
        return false;
    }
    bool operator < (Objects& other){
        if (this->A() < other.A())
            return true;
        return false;
    }
};