#include "MyString.h"
#include <cstring> // for strcpy, strlen, etc.
#include <utility> // for std::swap
#include <vector>

// TrieNode constructor and destructor
TrieNode::TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 26; ++i) {
        if (children[i]) {
            delete children[i];
        }
    }
}

// Trie class
Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    deleteTrieNode(root);
}

void Trie::deleteTrieNode(TrieNode* node) {
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            deleteTrieNode(node->children[i]);
        }
    }
    delete node;
}

int Trie::charToIndex(char c) {
    return c - 'a';
}

// Insert a word into the trie
void Trie::insert(const std::string &word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = charToIndex(c);
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

// Search for a word in the trie
bool Trie::search(const std::string &word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = charToIndex(c);
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
    }
    return node && node->isEndOfWord;
}

// Check if there is any word in the trie that starts with the given prefix
bool Trie::startsWith(const std::string &prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        int index = charToIndex(c);
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
    }
    return true;
}


// Default constructor
MyString::MyString() : data(new char[1]), length(0)
{
    data[0] = '\0';
}

// Parameterized constructor
MyString::MyString(const char *str) : data(new char[strlen(str) + 1]), length(strlen(str))
{
    strcpy(data, str);
}

// Copy constructor
MyString::MyString(const MyString &other) : data(new char[other.length + 1]), length(other.length)
{
    strcpy(data, other.data);
}

// Destructor
MyString::~MyString()
{
    delete[] data;
}

// Assignment operator
MyString &MyString::operator=(const MyString &other)
{
    if (this == &other)
    {
        return *this; // Return *this to deal with self-assignment
    }

    // Free existing resources
    delete[] data;

    // Copy data from other string
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);

    return *this;
}

// Concatenation (+=) operator
MyString &MyString::operator+=(const MyString &other)
{
    char *newData = new char[length + other.length + 1];
    strcpy(newData, data);
    strcat(newData, other.data);

    // Free old memory and assign new data
    delete[] data;
    data = newData;
    length += other.length;

    return *this;
}

// Subscript ([]) operator
char &MyString::operator[](size_t index)
{
    if (index >= length)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Get size of the string
size_t MyString::size() const
{
    return length;
}

// Check if string is empty
bool MyString::empty() const
{
    return length == 0;
}

// Return C-style string
const char *MyString::c_str() const
{
    return data;
}

// Append string
void MyString::append(const MyString &other)
{
    *this += other;
}

// Overload insertion operator (<<) for easy output
std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.c_str();
    return os;
}

// Find substring
int MyString::find(const MyString& substr) const {
    if (substr.length > length) return -1;

    for (size_t i = 0; i <= length - substr.length; ++i) {
        size_t j;
        for (j = 0; j < substr.length; ++j) {
            if (data[i + j] != substr.data[j]) {
                break;
            }
        }

        // If the inner loop ran fully, that means we found our string.
        if (j == substr.length) {
            return i;
        }
    }
    return -1;
}

// Erase substring
void MyString::erase(size_t pos, size_t len) {
    if (pos >= length) {
        throw std::out_of_range("Position out of range");
    }
    
    if (len == 0) {
        return;
    }
    
    if (len > length - pos) {
        len = length - pos; // Erase till the end if len exceeds the string length from pos
    }

    // Calculate new length
    size_t newLength = length - len;
    
    // Create new data array
    char *newData = new char[newLength + 1];
    
    // Copy characters before 'pos'
    strncpy(newData, data, pos);
    
    // Copy characters after 'pos + len'
    strcpy(newData + pos, data + pos + len);
    
    // Null-terminate the new string
    newData[newLength] = '\0';
    
    // Delete old data and replace with new data
    delete[] data;
    data = newData;
    
    // Update length
    length = newLength;
}

// string reversing w/0 affecting original string
MyString MyString::reverse() const{
    MyString reversedStr;
    reversedStr.length = length;
    reversedStr.data = new char[length + 1];

    for(size_t i = 0; i < length; i++) {
        // add chars in reversed order
        reversedStr.data[i] = data[length - i - 1];
    }

    reversedStr.data[length] = '\0'; // end with string terminator
    return reversedStr;
}

// insert substring at given position
void MyString::insert(size_t pos, const MyString &str) {
    // out of bounds check
    if (pos > length) {
        throw std::out_of_range("Insert position out of range");
    }

    char *newData = new char[length + str.length + 1];
    
    // characters before position
    strncpy(newData, data, pos);
    
    // make modifications
    strcpy(newData + pos, str.data);
    
    // remaining characters
    strcpy(newData + pos + str.length, data + pos);
    
    delete[] data;
    data = newData;
    length += str.length;
}


// replace substring with given substring at all occurrences
void MyString::replace(const MyString &target, const MyString &replacement) {
    int pos = find(target);
    size_t lastPos = 0;
    while (pos != -1 && lastPos < length) {
        erase(pos, target.size());
        insert(pos, replacement);
        lastPos = pos + replacement.length;
        pos = find(target);
    }
}

// word count
size_t MyString::word_count() const {
    size_t count = 0;
    bool inWord = false;
    for (size_t i = 0; i < length; ++i) {
        if (isspace(data[i])) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            ++count;
        }
    }
    return count;
}

// check palindrome
bool MyString::check_palindrome() const {
    size_t start = 0;
    size_t end = length - 1;

    while (start < end) {
        // Ignore spaces
        while (start < end && data[start] == ' ') {
            start++;
        }
        while (start < end && data[end] == ' ') {
            end--;
        }

        // Compare characters ignoring case
        if (tolower(data[start]) != tolower(data[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// password encrypt
void MyString::password_encrypt(const char* key) {
    size_t key_len = strlen(key);
    for (size_t i = 0; i < length; ++i) {
        data[i] ^= key[i % key_len];  // XOR each character with the key
    }
}

// decrypt password
void MyString::password_decrypt(const char* key) {
    password_encrypt(key); // XOR again with the same key decrypts the string
}

// minimum number of edits (insertions, deletions, or substitutions) required to transform one string into another.
int MyString::levenshtein_distance(const MyString &other) const {
    size_t m = length;
    size_t n = other.length;

    // create dp
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // initial state
    for (size_t i = 0; i <= m; ++i) {
        dp[i][0] = i;  // i deletions to transform to an empty string
    }
    for (size_t j = 0; j <= n; ++j) {
        dp[0][j] = j;  // j insertions to transform an empty string
    }

    // Compute the minimum cost (tabulation)
    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            int cost = (data[i - 1] == other.data[j - 1]) ? 0 : 1;

            dp[i][j] = std::min(dp[i - 1][j] + 1,   // Deletion
                                  std::min(dp[i][j - 1] + 1,   // Insertion
                                  dp[i - 1][j - 1] + cost) ); // Substitution
        }
    }

    return dp[m][n];
}
