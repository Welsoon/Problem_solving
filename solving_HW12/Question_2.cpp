#include "Question_2.h"

void sequ::input()
{
    cin>>num;
    int temp;
    flag = true;
    while (cin>>temp)
    {
        list.push_back(temp);
        if ((temp>1000)||(temp<-1000))
            flag = false;
        if('\n'==cin.get())
            break;
    }
    if ((num!=list.size())||(num<1)||(num>10000))
        flag = false;
    maxSum = list[0];
    pos1 = 1;
    pos2 = 1;
}

void sequ::fun()
{
    if (flag)
    {
        int sum = 0;
        int p1=1, p2=0;
        for (int i=0; i<list.size(); i++)
        {
            sum = sum+list[i];
            p2 = p2+1;

            if (sum>maxSum)
            {
                maxSum = sum;
                pos1 = p1;
                pos2 = p2;
            }
            if (sum<0)
            {
                sum = 0;
                p1 = i+2;
                p2 = i+1;
            }
        }
    }
}

void sequ::myprintf()
{
    if (flag)
        cout<<maxSum<<" "<<pos1<<" "<<pos2<<endl;
    else
        cout<<"error"<<endl;
    
}