#ifndef TOKEN_EXERCISE_1_H_INCLUDED
#define TOKEN_EXERCISE_1_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include<algorithm>

using namespace std;

class Token{
    public:
        Token(int n);
        void find(string paragraph);
        void strcmp_sort(vector<string> a);
        void print();
        vector<string> a;
    private:
        int count;
        //string sort[10];


};



#endif // TOKEN_EXERCISE_1_H_INCLUDED
