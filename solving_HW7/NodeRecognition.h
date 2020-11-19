#ifndef noderecognition_h_
#define noderecognition_h_

#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// enum{node, binTree, tree, graph};

class NodeRecognition
{
    public:
        NodeRecognition();
        void cutInPut();
        void processNode();

        string input;

        typedef struct NODE
        {
            int name;
            int weight;
            int sumWeight;
            int size;
            int state;
            vector<NODE*> childNode;

            NODE();
        }NODE;
        
        private:
        void newNode(int childNode, int fatherNode);
        int ifNodeInSet(vector<NODE*>, int);
        bool cutCircle(NODE* node, int state_change);
        bool changeName(NODE* node, int name);
        bool ifLink(int name);      // if cenNode link with former cenNode

        vector<NODE*> cenNode;
        vector<NODE*> nodeSet;
        bool if_cut;    // if cut circle in fun "cutCircle"
        bool if_link;   // if cenNode link with former cenNode
        int link_name;  // the former cenNode name linked
        vector<int> nodeName;       // the node named
};




#endif