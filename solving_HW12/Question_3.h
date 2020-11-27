#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class LPS
{
    public:
        void input();
        void fun();
        void myprintf();
    private:
        string text;
        int len;
        vector<vector<string> >lps;
};