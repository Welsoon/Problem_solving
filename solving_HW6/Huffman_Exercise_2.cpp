#include "Huffman_Exercise_2.h"

using namespace std;

Huffman2::Huffman2()
{
    WPL = 0;
    root = NULL;
}

void Huffman2::cutWord(vector<string> input)
{
    int char_other = input.size()-1;
    for (auto it=input.begin(); it!=input.end(); it++)
    {
        int p1 = 0, p2 = 0;
        for (int i=0; i<(*it).length();)
        {
            if (ifWord((*it)[i]))
            {
                p1 = i;
                for (p2=p1+1; ifWord((*it)[p2]); p2++){}
                string s = (*it).substr(p1, p2-p1);
                i = p2;

                bool flag = false;
                for (int k=0; k<Queue.size(); k++)
                {
                    if (Queue[k]->word==s)
                    {
                        Queue[k]->weight = Queue[k]->weight+1;
                        flag = true;
                    }
                }
                if (!flag)
                {
                    treeNode *temp_node = new treeNode;
                    temp_node->word = s;
                    temp_node->weight = 1;
                    temp_node->code = "";
                    temp_node->left = NULL;
                    temp_node->right = NULL;
                    Queue.push_back(temp_node);
                    NodeSet.push_back(temp_node);
                }
            }
            else
            {
                i = i+1;
                char_other = char_other+1;
            }
        }
    }
    WPL = WPL+char_other*8;
}

void Huffman2::newHuffmanTree()
{
    int num = Queue.size();
    for (int i=1; i<num; i++)
    {
        sort(Queue.begin(), Queue.end(), myComp);
        treeNode* temp_node = new treeNode;
        auto it = Queue.begin();
        temp_node->weight = Queue[num-i-1]->weight+Queue[num-i]->weight;
        temp_node->left = Queue[num-i-1];
        temp_node->right = Queue[num-i];
        Queue.pop_back();
        Queue.pop_back();
        Queue.push_back(temp_node);
        NodeSet.push_back(temp_node);
    }
    root = *(Queue.end()-1);
}

void Huffman2::deleteHuffmanTree()
{
    for (auto it=NodeSet.begin(); it!=NodeSet.end(); it++)
    {
        delete *it;
    }
}

bool Huffman2::myComp(treeNode* N1, treeNode* N2)
{
    return N1->weight>N2->weight;
}

bool Huffman2::preOrder(treeNode *node)
{
    if (NULL!=node->left)
    {
        (node->left)->code = node->code+"0";
        if (!preOrder(node->left))
        {
            return false;
        }
    }
    else
    {
        cout<<node->word<<"\t"<<node->weight<<"\t"<<node->code<<endl;
        WPL = WPL+node->weight*(node->code).length();
    }

    if (NULL!=node->right)
    {
        (node->right)->code = node->code+"1";
        if (!preOrder(node->right))
        {
            return false;
        }
    }

    return true;
}

bool Huffman2::ifWord(char k)
{
    bool flag;
    int num_k = int(k);
    if((num_k>=65)&&(num_k<=90))        // A 
        flag = true;
    else if((num_k>=97)&&(num_k<=122))  // a
        flag = true;
    else
        flag = false;
    return flag;
}