#include "Token_Exercise_1.h"

Token::Token(int n)
{
    count=n;
    //for(int i=0;i<count;i++)
       //sort[i].assign(strs[i]);
}


// void Token::find(string  paragraph)
// {
//     int i,j;
//     for(int i=0;i<paragraph.length();i++)
//     {
//         if(paragraph[i]>='A'&&paragraph[i]<='Z')
//            paragraph[i]+=32;
//     }
//     i=0;
//     while(i<paragraph.length())
//     {
//         int pot;
//         string newstr;
//         if((paragraph[i]>=97&&paragraph[i]<=122)||(paragraph[i]>=48&&paragraph[i]<=58))
//         {
//             for(j=i; j<paragraph.length();j++)
//             {
//                 if(!((paragraph[j]>=97&&paragraph[j]<=122)||(paragraph[j]>=48&&paragraph[j]<=58)))
//                    pot=j;
//                 break;
//             }
//             newstr.assign(paragraph,i,pot-i+1);
//             a.push_back(newstr);
//             //a.push_back(paragraph+i,paragraph+dot-1);
//             i=i+pot+1;
//         }
//         else
//             i+=1;
//     }
// }
// int number[10]={0};
// void Token::strcmp_sort(vector<string> a)
// {
//     for(int i=0;i<count;i++)
//     {
//         for(int j=0;j<a.size();j++)
//         {
//             if (strcmp(sort[i],a[j]) == 0)
//                 number[i]+=1;
//         }
//     }
// }

// void Token::print()
// {
//     for(int i=0;i<count-1;i++)
//        cout<<"("<<sort[i]<<","<<number[i]<<")"<<" ";
//     cout<<"("<<sort[count-1]<<","<<number[count-1]<<")"<<endl;
// }


