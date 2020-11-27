#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Question1
{
    public:
        void input();
        void fun();
        void myprintf();
    private:
        struct Thread{
            int num;
            int rank;
            int startTime;
            int endTime;
            vector<int> cut;
        };
        vector<Thread> P;
};