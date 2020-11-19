#include "Huffman_Exercise_1.h"
#include "Huffman_Exercise_2.h"

using namespace std;

int main()
{
    bool exercise_1 = false;
    if (exercise_1)    
    {
        //--------------------------------------------------------------
        vector<string> text;
        string str;

        bool if_input_continue = true;
        while(if_input_continue)
        {
            getline(cin, str);
            if(str.empty())
            {
                if_input_continue = false;
            }
            else
            {
                text.push_back(str);
            }
        }

        // while(getline(cin, str))
        // {
        //     text.push_back(str);
        // }

        Huffman1 P;
        P.cutChar(text);
        P.newHuffmanTree();
        P.preOrder(P.root);
        P.deleteHuffmanTree();
        cout<<P.WPL;
    }
    else
    {
        //--------------------------------------------------------------
        vector<string> text;
        string str;

        bool if_input_continue = true;
        while(if_input_continue)
        {
            getline(cin, str);
            if(str.empty())
            {
                if_input_continue = false;
            }
            else
            {
                text.push_back(str);
            }
        }

        // while(getline(cin, str))
        // {
        //     text.push_back(str);
        // }

        Huffman2 P;
        P.cutWord(text);
        P.newHuffmanTree();
        P.preOrder(P.root);
        P.deleteHuffmanTree();
        cout<<P.WPL;
    }
    return 0;
}