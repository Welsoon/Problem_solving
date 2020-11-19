#include "question1.h"

// void boat::input()
// {
//     flag = "ok";
//     boat_num = 0;

//     cin>>weight_max>>boat_num;
//     int num;
//     while (cin>>num)
//     {
//         people.push_back(num);
//         if ("ok"==flag)
//         {
//             if (num<=0)
//                 flag = "error";
//             else if (num>weight_max)
//                 flag = "out";
//         }
//         else if ("out"==flag)
//         {
//             if (num<=0)
//                 flag = "error";
//         }
//         if('\n'==cin.get())
//             break;
//     }
// }

// void boat::fun()
// {
//     if ("ok"==flag)
//     {
//         sort(people.begin(), people.end());
//         while (people.size()>0)
//         {
//             boat_num = boat_num+1;
//             if (people.size()>1)
//             {
//                 bool out = false;
//                 for (int i=1; i<people.size();)
//                 {
//                     if (people[0]+people[i]>weight_max)
//                     {
//                         out = true;
//                         people.erase(people.begin()+i);
//                         break;
//                     }
//                 }
//                 if (false==out)
//                     people.pop_back();
//                 people.erase(people.begin());
//             }
//         }
//     }
// }

// void boat::myprintf()
// {
//     if ("ok"==flag)
//     {
//         cout<<boat_num<<endl;
//     }
//     else
//     {
//         cout<<flag<<endl;
//     }
//     cout<<"right"<<endl;
// }

void myprintf()
{
    cout<<"test ok"<<endl;
}


// 15
// w 80-200  n 1-300