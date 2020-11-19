#include "Code_Exercise_2.h"

using namespace std;

Code::Code(vector<string> input)
{
    text = input;

    // key word in c++
    key_word.push_back("alignas");          key_word.push_back("alignof");          key_word.push_back("and");              key_word.push_back("and_eq");
    key_word.push_back("asm");              key_word.push_back("atomic_cancel");    key_word.push_back("atomic_commit");    key_word.push_back("atomic_noexcept");
    key_word.push_back("auto");             key_word.push_back("bitand");           key_word.push_back("bitor");            key_word.push_back("bool");
    key_word.push_back("break");            key_word.push_back("case");             key_word.push_back("catch");            key_word.push_back("char");
    key_word.push_back("char8_t");          key_word.push_back("char16_t");         key_word.push_back("char32_t");         key_word.push_back("class");
    key_word.push_back("compl");            key_word.push_back("concept");          key_word.push_back("const");            key_word.push_back("consteval");
    key_word.push_back("constexpr");        key_word.push_back("constinit");        key_word.push_back("const_cast");       key_word.push_back("continue");
    key_word.push_back("co_await");         key_word.push_back("co_return");        key_word.push_back("co_yield");         key_word.push_back("decltype");
    key_word.push_back("default");          key_word.push_back("define");           key_word.push_back("defined");          key_word.push_back("delete");
    key_word.push_back("do");               key_word.push_back("double");           key_word.push_back("dynamic_cast");     key_word.push_back("elif");
    key_word.push_back("else");             key_word.push_back("error");            key_word.push_back("endif");            key_word.push_back("enum");
    key_word.push_back("explicit");         key_word.push_back("export");           key_word.push_back("extern");           key_word.push_back("false");
    key_word.push_back("final");            key_word.push_back("float");            key_word.push_back("for");              key_word.push_back("friend");
    key_word.push_back("goto");             key_word.push_back("if");               key_word.push_back("ifdef");            key_word.push_back("ifndef");
    key_word.push_back("import");           key_word.push_back("include");          key_word.push_back("inline");           key_word.push_back("int");
    key_word.push_back("line");             key_word.push_back("long");             key_word.push_back("module");           key_word.push_back("mutable");
    key_word.push_back("namespace");        key_word.push_back("new");              key_word.push_back("noexcept");         key_word.push_back("not");
    key_word.push_back("not_eq");           key_word.push_back("nullptr");          key_word.push_back("operator");         key_word.push_back("or");
    key_word.push_back("or_eq");            key_word.push_back("override");         key_word.push_back("pragma");           key_word.push_back("private");
    key_word.push_back("protected");        key_word.push_back("public");           key_word.push_back("reflexpr");         key_word.push_back("register");
    key_word.push_back("reinterpret_cast"); key_word.push_back("requires");         key_word.push_back("return");           key_word.push_back("short");
    key_word.push_back("signed");           key_word.push_back("sizeof");           key_word.push_back("static");           key_word.push_back("static_assert");
    key_word.push_back("static_cast");      key_word.push_back("struct");           key_word.push_back("switch");           key_word.push_back("synchronized");
    key_word.push_back("template");         key_word.push_back("this");             key_word.push_back("thread_local");     key_word.push_back("throw");
    key_word.push_back("xor_eq");           key_word.push_back("true");             key_word.push_back("try");              key_word.push_back("typedef");
    key_word.push_back("typeid");           key_word.push_back("typename");         key_word.push_back("undef");            key_word.push_back("union");
    key_word.push_back("unsigned");         key_word.push_back("using");            key_word.push_back("virtual");          key_word.push_back("void");
    key_word.push_back("volatile");         key_word.push_back("wchar_t");          key_word.push_back("while");            key_word.push_back("xor");
}

void Code::cutCode()
{
    string temp = "";
    // singleline comment
    for(vector<string>::iterator it=text.begin(); it!=text.end(); it++)
    {
        int t1 = (*it).find("//");
        if(t1==-1)
        {
            temp.append(*it);
            temp.append(" ");
        }
        else
        {
            int t3 = (*it).find("*/");
            if(t3>t1)
            {
                temp.append(*it, t3, (*it).length()-t3);
            }
            else
            {
                temp.append(*it, 0, t1);
                temp.append(" ");
            }
        }
    }

    // multiline comment
    bool if_multi = true;
    while(if_multi)
    {
        int t2 = temp.find("/*");
        if(t2==-1)
            if_multi = false;
        else
        {
            int t3 = temp.find("*/");
            temp[t2] = ' ';
            temp.erase(t2+1, t3-t2+1);
        }
    }

    // \n
    bool if_endline = true;
    while(if_endline)
    {
        int t4 = temp.find("\\n");      // \n save \\n in string
        if(t4==-1)
            if_endline = false;
        else
        {
            temp[t4] = ' ';
            temp[t4+1] = ' ';
            temp[t4+2] = ' ';
        }
    }

    // cut the code into str and save in 'code'
    int p1 = 0, p2 = 0;
    for(int i=0; i<temp.length();)
    {
        if(if_word(temp[i]))
        {
            p1 = i;
            for(p2=p1+1; if_word(temp[p2]); p2++){}
            code.push_back(temp.substr(p1, p2-p1));
            i = p2;
        }
        else
        {
            i = i+1;
        }
    }
}

void Code::mySort()
{
    // sort code elements with mydefine comp
    // the fun comp() must be declared static !!!!!!!!!!!!!!!!!
    sort(code.begin(), code.end(), comp);
    // delete the same elements using unique
    // the fun equa() must be declared static !!!!!!!!!!!!!!!!!
    code.erase(unique(code.begin(), code.end(), equa), code.end());
}

void Code::print()
{
    for(vector<string>::iterator it=code.begin(); it!=code.end(); it++)
    {
        cout<<*it<<" ";
    }
}

void Code::wordScreen()
{
    for(vector<string>::iterator it=code.begin(); it!=code.end();)
    {
        bool if_delete = false;
        // begin with number
        if(((*it)[0]>=48)&&((*it)[0]<=57))
            if_delete = true;
        // in key word table
        for(int i=0; i<key_word.size(); i++)    // using iterator here leads to error????
        {
            if(equa(*it, key_word[i]))
                if_delete = true;
        }

        if(if_delete)
            it = code.erase(it);
        else
            it++;
    }
}


bool Code::comp(string s1, string s2)
{
    bool flag;
    int res = s1.compare(s2);
    if(res<0)
        flag = true;
    else
        flag = false;
    return flag;
}

bool Code::equa(string s1, string s2)
{
    bool flag;
    int res = s1.compare(s2);
    if(res==0)
        flag = true;
    else
        flag = false;
    return flag;
}

bool Code::if_word(char k)
{
    bool flag;
    int num_k = int(k);
    if((num_k>=48)&&(num_k<=57))    // number
        flag = true;
    else if((num_k>=65)&&(num_k<=90))   // A 
        flag = true;
    else if((num_k>=97)&&(num_k<=122))  // a
        flag = true;
    else if(num_k==95)                  // _
        flag = true;
    else
        flag = false;
    return flag;
}