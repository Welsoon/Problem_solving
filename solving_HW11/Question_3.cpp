#include "Question_3.h"

void LPS::input()
{
    getline(cin, text);
    len = text.length();
}

void LPS::fun()
{
    for (int i=0; i<len; i++)
    {
        vector<string> row;
        for (int j=0; j<len; j++)
        {
            if (j<i)
            {
                row.push_back("");
            }
            else if (i==j)
            {
                row.push_back(text.substr(i, 1));
            }
        }
        lps.push_back(row); 
    }
    // lps[j-i][j]
    for (int i=1; i<len; i++)
    {
        for (int j=i; j<len; j++)
        {
            if (text[j-i]==text[j])
            {
                lps[j-i].push_back(text[j-i]+lps[j-i+1][j-1]+text[j]);
            }
            else
            {
                if (lps[j-i+1][j].length()>=lps[j-i][j-1].length())
                    lps[j-i].push_back(lps[j-i+1][j]);
                else 
                    lps[j-i].push_back(lps[j-i][j-1]);
            }
            
        }
    }
}

void LPS::myprintf()
{
    string out = lps[0][len-1];
    if ((out.length()%2)==1)
        out.erase(int(out.length()/2), 1);
    cout<<out<<endl;
}