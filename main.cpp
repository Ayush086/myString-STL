#include <iostream>
#include "myString.h"
using namespace std;


int main() {
    // myString s("new learning");
    myString s = "new learning";
    cout << s << endl;
    cout << s[4] << endl;
    cout << s.find("learn") << endl;
    s.erase(4, 8);
    cout << s << endl;
    
    myString s1 = "ayush";
    s1 += " uttarwar";
    cout << s1 << endl;
    return 0;
}

/* Execution process (one-time process)*/
/*
.o file creation
    - g++ -c myString.cpp
    - g++ -c main.cpp
    - g++ -o main myString.o main.o
*/
// ./main (to execute main.exe file)
