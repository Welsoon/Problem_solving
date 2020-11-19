#include "Huffman_Exercise_1.h"

using namespace std;

Huffman1::Huffman1()
{
    WPL = 0;
    root = NULL;
}

void Huffman1::cutChar(vector<string> input)
{
    int charCount[256] = {0};
    charCount[13] = input.size()-1;
    for (int i=0; i<input.size(); i++)
    {
        for (int j=0; j<input[i].length(); j++)
        charCount[int(input[i][j])] = charCount[int(input[i][j])]+1;
    }
    for (int i=0; i<256; i++)
    {
        if (charCount[i]>0)
        {
            treeNode* temp_node = new treeNode;
            temp_node->word = char(i);
            temp_node->weight = charCount[i];
            temp_node->left = NULL;
            temp_node->right = NULL;

            // treeNode temp_node;
            // temp_node.word = char(i);
            // temp_node.weight = charCount[i];
            // temp_node.left = NULL;
            // temp_node.right = NULL;
            Queue.push_back(temp_node);
            NodeSet.push_back(temp_node);
            // cout<<temp_node->word<<"\t"<<temp_node->weight<<endl;
        }
    }
}

void Huffman1::newHuffmanTree()
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

void Huffman1::deleteHuffmanTree()
{
    for (auto it=NodeSet.begin(); it!=NodeSet.end(); it++)
    {
        delete *it;
    }
}

bool Huffman1::myComp(treeNode* N1, treeNode* N2)
{
    return N1->weight>N2->weight;
}

bool Huffman1::preOrder(treeNode *node)
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
        // cout<<node->word<<"\t"<<int(node->word)<<"\t"<<node->weight<<"\t"<<node->code<<endl;
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