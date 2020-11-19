// Date: 2020/10/19
// Author: Sun jiaze

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Code
{
	public:
        Code(vector<string>);
        void cutCode();
        void mySort();
        void print();
        void wordScreen();

    private:
        static bool comp(string, string);
        static bool equa(string, string);
        bool if_word(char);

        vector<string> key_word;
        vector<string> code;
        vector<string> text;        // code input
};