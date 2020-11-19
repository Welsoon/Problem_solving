#include "NodeRecognition.h"
#include "TreeConstruct.h"

using namespace std;

int main()
{
    bool exercise_1 = true;
    if(exercise_1)
    {
        //-------------------------------------------------------------------------------
        NodeRecognition P;
        getline(cin, P.input);
        P.cutInPut();
        P.processNode();
        


        int a=0;
        // <2 6> <6> <3 1> <1 6>    <1 2> <2 3> <3 1>
        // <2 1> <3 2> <1 3> <5 4> <5 6>
    }
    else
    {
        //-------------------------------------------------------------------------------
        vector<int> a;
        a.push_back(0);
        a.push_back(1);
        a.push_back(2);
        auto it = a.begin();
        a.erase(it+1);
        cout<<a[0]<<a[1];

    }
    return 0;
}
