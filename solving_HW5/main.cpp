#include "Token_Exercise_1.h"
#include "Code_Exercise_2.h"

using namespace std;
int main()
{
    bool exercise_1=false;
    if(exercise_1)    
    {
        //--------------------------------------------------------------
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        Token P(s1, s2);
        P.strcmp_sort();
        P.find();
        P.print();
    }
    else
    {
        vector<string> text;
        string str;

        // bool if_input_continue = true;
        // while(if_input_continue)
        // {
        //     getline(cin, str);
        //     if(str.empty())
        //     {
        //         if_input_continue = false;
        //     }
        //     else
        //     {
        //         text.push_back(str);
        //     }
        // }

        while(getline(cin, str))
        {
            text.push_back(str);
        }

        Code P(text);
        P.cutCode();
        P.mySort();
        P.wordScreen();
        P.print();
    }
    return 0;
}

