/* definations of all functions and methods declared in "myString.h" are implemented here */

#include "myString.h"
#include <cstring> // for strcpy, strlen

// default ctor
myString::myString() : data(new char[1]), length(0){
    data = '\0';
}

// parameterized ctor
myString::myString(const char* str ) {
    data = new char[strlen(str)+1];  // creating a data array of size = strlen(str)
    length = strlen(str);  // calculated it's length using strlen
    strcpy(data, str);  // copying entered string into data array  
} 

// copy ctor
myString::myString(const myString& src) {
    data = new char[src.length + 1];
    length = src.length; 
    strcpy(data, src.data);
}

// default dtor
myString::~myString() {
    delete[] data;
}

/* String Operations */
// string size
int myString::size() const {
    return length;
} 

// string empty check
bool myString::empty() const {
    return length == 0; // if length = 0 then true else false
}

// c-str print
const char* myString::c_str() const {
    return data;
}

// insertion operator overloading for o/p
std::ostream& operator<<(std::ostream&os, const myString&str){
    os << str.c_str(); // convert string to c_string (represents array of chars terminated by null character)
}

// [] (subscript) operator overloading for char at given index
char myString::operator[](int index) {
    if (index >= length){
        return '\0';
    }
    return data[index];
}

// to find sub-string
int myString::find(const myString& subStr) const {
    if(subStr.length > length){
        return -1;
    }

    for (int i = 0; i <= (length - subStr.length); i++) {
        int j;
        for ( j = 0; j < subStr.length; j++) {

            if (data[i + j] != subStr.data[j]) {
                break;
            }
        } 
        if (j == subStr.length) {
            return i;
        } 
    }
    return -1;
}

// erase substring from original string
void myString::erase(int pos, int len){
    if (pos >= length) {
        // throwing out of range error
        throw std::out_of_range("position out of bounds");
    }
    
    if (len == 0) {
        return;
    }

    if (len > length - pos) {
        len = length - pos; // erase till pos > len
    }
    

    int newLength = length - len; // new string length
    char* newData = new char[newLength + 1]; // new data array to store new string
    strncpy(newData, data, pos); // to copy before 'pos', from data to newData
    strcpy(newData + pos, data+pos+len); // copy chars after 'pos + len' 

    newData[newLength] = '\0'; // null terminate

    delete[] data; // deleting old data
    data = newData; // updating new data

    len = newLength; // updating length
}


// string concatenation using += operator overloading
myString &myString::operator+=(const myString& other){
    char* newData = new char[length + other.length + 1]; // concated string

    // data + other
    strcpy(newData, data);
    strcat(newData, other.data);

    // free old memory assigned to data and updated the length of data
    delete[] data;
    data = newData;
    length += other.length;
    
    return *this;
}
