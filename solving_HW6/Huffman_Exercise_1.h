// Date 2020/10/25
// Author Sun jiaze

#ifndef _HUFFMAN_EXERCISE_1
#define _HUFFMAN_EXERCISE_1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Huffman1
{
    public:
        typedef struct treeNode
        {
            char word;
            int weight;
            string code;
            treeNode *left;
            treeNode *right;

            treeNode()
            {
                word = '\0';
                weight = 0;
                code = "";
                left = NULL;
                right = NULL;
            }
        }treeNode;

        treeNode* root;
        vector<treeNode*> Queue;
        vector<treeNode*> NodeSet;
        int WPL;

        void cutChar(vector<string>);                   // cut input string, creat treenode
        void newHuffmanTree();                          // creat huffman tree
        void deleteHuffmanTree();                       // free node memory
        bool preOrder(treeNode*);
        static bool myComp(treeNode*, treeNode*);
        Huffman1();
};
#endif