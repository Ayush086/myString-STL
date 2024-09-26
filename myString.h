/* contains declaration and libraries used */
#ifndef MYSTRING_H  // if not defined then define it
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <vector>

class TrieNode {
public:
    TrieNode* children[26]; // Assuming lowercase alphabet letters
    bool isEndOfWord;

    TrieNode();
    ~TrieNode();
};

class Trie {
private:
    TrieNode* root;
    void deleteTrieNode(TrieNode* node);

    // Helper function to convert a character to index
    int charToIndex(char c);

public:
    Trie();
    ~Trie();

    // Insert a word into the trie
    void insert(const std::string &word);

    // Search for a word in the trie
    bool search(const std::string &word);

    // Check if there is any word in the trie that starts with the given prefix
    bool startsWith(const std::string &prefix);
};

class MyString {
private:
    char *data;    // Pointer to store string data
    size_t length; // Size of the string

public:
    // Default constructor
    MyString();

    // Parameterized constructor
    MyString(const char *str);

    // Copy constructor
    MyString(const MyString &other);

    // Destructor
    ~MyString();

    // Assignment operator
    MyString &operator=(const MyString &other);

    // Concatenation (+=) operator
    MyString &operator+=(const MyString &other);

    // Subscript ([]) operator
    char &operator[](size_t index);

    // Get size of the string
    size_t size() const;

    // Check if string is empty
    bool empty() const;

    // Return C-style string
    const char *c_str() const;

    // Append string
    void append(const MyString &other);

    // Find substring
    int find(const MyString& substr) const;

    // Erase substring
    void erase(size_t pos, size_t len);

    // Overload insertion operator for easy output
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);

    // string reversing w/0 affecting original string
    MyString reverse() const;

    // insert substring at given position
    void insert(size_t pos, const MyString &str);

    // replace substring with given substring at all occurrences
    void replace(const MyString &target, const MyString &replacement);

    // word count
    size_t word_count() const;

    // check palindrome
    bool check_palindrome() const;

    // password encrypt
    void password_encrypt(const char* key);

    // decrypt password
    void password_decrypt(const char* key);

    // minimum number of edits (insertions, deletions, or substitutions) required to transform one string into another.
    int levenshtein_distance(const MyString &other) const;
};

#endif // MYSTRING_H


    
};

#endif
