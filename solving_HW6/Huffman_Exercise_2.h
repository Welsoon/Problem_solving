// Date 2020/10/25
// Author Sun jiaze

#ifndef _HUFFMAN_EXERCISE_2
#define _HUFFMAN_EXERCISE_2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Huffman2
{
    public:
        typedef struct treeNode
        {
            string word;
            int weight;
            string code;
            treeNode *left;
            treeNode *right;

            treeNode()
            {
                word = "";
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

        void cutWord(vector<string>);                   // cut input string, creat treenode
        void newHuffmanTree();                          // creat huffman tree
        void deleteHuffmanTree();                       // free node memory
        bool preOrder(treeNode*);
        static bool myComp(treeNode*, treeNode*);
        bool ifWord(char);
        Huffman2();
};
#endif