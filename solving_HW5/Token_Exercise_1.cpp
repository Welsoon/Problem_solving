#include "Token_Exercise_1.h"

using namespace std;

Token::Token(string s1, string s2)
{
    input_str = s1;
    input_word = s2;
    for(int i=0; i<10; i++)
    {
        count_word[i] = 0;
    }
}

void Token::find()
{
    for(int i=0; i<str.size(); i++)
    {
        for(int j=0; j<num_word; j++)
        {
            bool flag = false;
            int n_word = word[j].length();
            int n_str = str[i].length();
            if((n_word==n_str-1)||(n_word==n_str))
            {
                flag = true;
                for(int k=0; k<n_word; k++)
                {
                    if(!if_same(word[j][k], str[i][k]))
                        flag = false;
                }
            }
            if((n_word==n_str-1)&&(flag==true))
            {
                if((str[i][n_str-1]!='-')&&(str[i][n_str-1]!='_'))
                    flag = false;
            }
            if(flag)
                count_word[j] = count_word[j]+1;
        }
    }
}

void Token::strcmp_sort()
{
    // put input_str into vector str
    int p1 = 0, p2 = 0;
    for(int i=0; i<input_str.length();)
    {
        if(if_word(input_str[i]))
        {
            p1 = i;
            for(p2=p1+1; if_word(input_str[p2]); p2++){}
            str.push_back(input_str.substr(p1, p2-p1));
            i = p2;
        }
        else
        {
            i = i+1;
        }
    }
    // put input_word into vector str
    p1 = 0;
    p2 = 0;
    for(int i=0; i<input_word.length();)
    {
        if(if_word(input_word[i]))
        {
            p1 = i;
            for(p2=p1+1; if_word(input_word[p2]); p2++){}
            word.push_back(input_word.substr(p1, p2-p1));
            i = p2;
        }
        else
        {
            i = i+1;
        } 
    }
    num_word = word.size();
}

void Token::print()
{
    for(int i=0; i<num_word; i++)
    {
        cout<<"("<<word[i]<<","<<count_word[i]<<") ";
    }
    cout<<endl;
}

bool Token::if_word(char k)
{
    bool flag;
    int num_k = int(k);
    if((num_k>=48)&&(num_k<=57))    // number
        flag = true;
    else if((num_k>=65)&&(num_k<=90))   // A
        flag = true;
    else if((num_k>=97)&&(num_k<=122))  // a
        flag = true;
    else if((num_k==45)||(num_k==95))   // - _
        flag = true;
    else
        flag = false;
    return flag;
}

bool Token::if_same(char k1, char k2)
{
    bool flag;
    if(k1==k2)
        flag = true;
    else if((k1>=65)&&(k1<=90)&&(k2==k1+32))
        flag = true;
    else if((k1>=97)&&(k1<=122)&&(k2==k1-32))
        flag = true;
    else
        flag = false;
    return flag;
}
