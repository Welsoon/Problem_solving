//本关任务：编写一个成绩转换程序，对于输入的成绩 n，转换规则如下：A档为 90-100，B 档是 80-89，C 档是 70-79，D 档是 60-69，E 档是 0-59。

#include <iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    if(x>=90)
        cout<<"A";
    else if(x>=80&&x<90)
        cout<<"B";
    else if(x>=70&&x<80)
        cout<<"C";
        
    return 0;
}