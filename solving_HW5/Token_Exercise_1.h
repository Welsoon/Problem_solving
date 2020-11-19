// Date: 2020/10/19
// Author: Sun jiaze

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Token
{
    public:
        Token(string, string);
        void find();
        void strcmp_sort();
        void print();

    private:
        bool if_word(char);
        bool if_same(char, char);
        
        string input_str;
        string input_word;
        vector<string> str;
        vector<string> word;
        int num_word; 
        int count_word[10];
};