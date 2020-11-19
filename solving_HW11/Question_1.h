#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class boat
{
    public:
        void input();
        void fun();
        void myprintf();
    private:
        string flag;
        int weight_max;
        int people_num;
        vector<int> people;
        int boat_num;
};