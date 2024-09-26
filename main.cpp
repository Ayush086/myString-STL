#include "MyString.h"
#include <iostream>

int main() {
    MyString str1("new");
    MyString str2("learning");
    MyString str3("hello world");

    // += operator
    str1 += str2;
    std::cout << "Concatenation: " << str1 << std::endl;

    //  find
    std::cout << "Find 'new': " << str1.find("new") << std::endl;

    //  reverse
    MyString reversed = str3.reverse();
    std::cout << "Reversed: " << reversed << std::endl;

    //  insert
    str1.insert(5, " ");
    std::cout << "After insertion: " << str1 << std::endl;

    //  replace
    str3.replace("learning", "learnings");
    std::cout << "After replace: " << str3 << std::endl;

    //  word count
    std::cout << "Word count: " << str3.word_count() << std::endl;

    //  palindrome check
    MyString palindrome("madam");
    std::cout << "Is palindrome: " << palindrome.check_palindrome() << std::endl;

    //  password encryption and decryption
    MyString password("mypassword");
    const char* key = "key123";
    password.password_encrypt(key);
    std::cout << "Encrypted password: " << password << std::endl;
    password.password_decrypt(key);
    std::cout << "Decrypted password: " << password << std::endl;

    //  Levenshtein distance
    MyString strA("kitten");
    MyString strB("sitting");
    std::cout << "Levenshtein distance: " << strA.levenshtein_distance(strB) << std::endl;

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
