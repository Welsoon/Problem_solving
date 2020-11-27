#include "Question_1.h"

void Question1::input()
{
    string s;
    while (getline(cin, s))
    {
        if (false==s.empty())
        {
            Thread T;
            s.pop_back();

            int p1 = s.find('P');
            int p2 = s.find(' ');
            int n = p2-p1-1;
            int res = 0;
            for (int i=0; i<n; i++)
            {
                res = res+pow(10, n-i)*int(s[p1+i+1]-'0');
            }
            T.num = res;
            s.erase(0, p2+1);

            p2 = s.find(' ');
            p1 = -1;
            n = p2-p1-1;
            res = 0;
            for (int i=0; i<n; i++)
            {
                res = res+pow(10, n-i)*int(s[p1+i+1]-'0');
            }
            T.rank = res;
            s.erase(0, p2+1);

            p2 = s.find(' ');
            p1 = -1;
            n = p2-p1-1;
            res = 0;
            for (int i=0; i<n; i++)
            {
                res = res+pow(10, n-i)*int(s[p1+i+1]-'0');
            }
            T.startTime = res;
            T.endTime = T.startTime;
            s.erase(0, p2+1);

            while (false==s.empty())
            {
                p2 = s.find(' ');
                p1 = -1;
                n = p2-p1-1;
                res = 0;
                for (int i=0; i<n; i++)
                {
                    res = res+pow(10, n-i)*int(s[p1+i+1]-'0');
                }
                T.cut.push_back(res);
                s.erase(0, p2+1);
            }
            
            P.push_back(T);
        }
        else
        {
            break;
        }
        
    }
}
