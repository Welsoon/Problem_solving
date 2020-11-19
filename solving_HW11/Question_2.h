#include <iostream>
#include <string>
#include <vector>

using namespace std;

class sequ
{
    public:
        void input();
        void fun();
        void myprintf();
    private:
        vector<int> list;
        int num;
        int maxSum;
        int pos1, pos2;
        bool flag;
};