/* contains declaration and libraries used */
#ifndef MYSTRING_H  // if not defined then define it
#define MYSTRING_H

#include <iostream> 

class myString {
    private:
        char* data; // pointer to first element of char array
        int length;  // to store the length of myString

    public:
        // default ctor
        myString();

        // parametrized ctor
        myString(const char* str);

        // copy ctor
        myString(const myString& src);

        // default dtor
        ~myString();

        int size() const;  // data modification isn't possible inside const functions

        bool empty() const; // empty string check

        const char* c_str() const; // for string printing

        char operator[](int index); // for char at given index

        int find(const myString& subStr) const; // to find a substring in string (if exists then index will be returned)

        myString &operator+=(const myString& other); // string concatenation

        void erase(int pos, int len); // erase substring from string

// overloading "<<" (insertion operator) for o/p (operator overloading)
        friend std::ostream& operator<<(std::ostream&os, const myString&str); // asking os to print str whenever "cout << str" is called.

    
};

#endif
