#include <iostream>
#include <string>
#include "MarbleString.hpp"

using namespace std;

class MarbleString {
private:
    int size;
public:
    char *msArr;
    
    MarbleString() {
        msArr = new char[10];
    }
    MarbleString(string str) {
        size = str.length();
        msArr = new char[size];
        for (int i = 0; i<size; i++) {
            msArr[i] = str[i] + 1;
        }
    }
    MarbleString(const MarbleString &other) {
        msArr = other.msArr;
    }
    ~MarbleString() {
        delete [] msArr;
    }
    int length() {
        return size;
    }
    void ReverseMarbleString() {
        for (int i = 0; i<size; i++) {
            msArr[i] = msArr[i] - 1;
        }
    }
};
