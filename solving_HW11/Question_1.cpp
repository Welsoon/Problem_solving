#include "Question_1.h"

void boat::input()
{
    flag = "ok";
    boat_num = 0;

    cin>>weight_max>>people_num;
    int num;
    while (cin>>num)
    {
        people.push_back(num);
        if ("ok"==flag)
        {
            if (num<=0)
                flag = "error";
            else if (num>weight_max)
                flag = "out";
        }
        else if ("out"==flag)
        {
            if (num<=0)
                flag = "error";
        }
        if('\n'==cin.get())
            break;
    }
}

void boat::fun()
{
    if ("ok"==flag)
    {
        sort(people.begin(), people.end());
        while (people.size()>0)
        {
            boat_num = boat_num+1;
            if (people.size()>1)
            {
                bool out = false;
                for (int i=1; i<people.size();)
                {
                    if (people[0]+people[i]>weight_max)
                    {
                        out = true;
                        people.erase(people.begin()+i-1);
                        if (i!=1)
                            people.erase(people.begin());
                        break;
                    }
                    i = i+1;
                }
                if (false==out)
                {
                    people.erase(people.begin());
                    people.pop_back();
                }
            }
            else
            {
                break;
            }
            
        }
    }
}

void boat::myprintf()
{
    if ("ok"==flag)
    {
        cout<<boat_num<<endl;
    }
    else
    {
        cout<<flag<<endl;
    }
}
