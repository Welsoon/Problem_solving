#include "NodeRecognition.h"

using namespace std;

// --------NodeRecognition public function defination-------------------

NodeRecognition::NodeRecognition()
{

}

NodeRecognition::NODE::NODE()
{
    name = 0;
    weight = 0;
    sumWeight = 0;
    size = 0;
    state = 0;
}

void NodeRecognition::cutInPut()
{
    bool if_cut = true;
    while (if_cut)
    {
        int c1 = input.find('<');
        int c2 = input.find('>');
        string s = input.substr(c1+1, c2-c1-1);
        input.erase(0, c2+2);
        if (input.empty())
            if_cut = false;
        
        int n1, n2;     // node number
        int pos_space = s.find(' ');
        if (pos_space==-1)
        {
            n1 = 0;
            n2 = -1;
            for (int i=0; i<s.length(); i++)
            {
                n1 = n1+int(s[i]-'0')*int(pow(10, s.length()-i-1));
            }
        }
        else
        {
            int len1 = pos_space;
            int len2 = s.length()-pos_space-1;
            n1 = 0;
            n2 = 0;
            for (int i=0; i<len1; i++)
            {
                n1 = n1+int(s[i]-'0')*int(pow(10, len1-i-1));
            }
            for (int i=0; i<len2; i++)
            {
                n2 = n2+int(s[pos_space+1+i]-'0')*int(pow(10, len2-i-1));
            }
        }
        newNode(n1, n2);
    }
}

void NodeRecognition::processNode()
{
    // cut off the circle
    // for (int i=0; i<cenNode.size(); i++)
    // {
    //     if_cut = false;
    //     cutCircle(cenNode[i], 5);
    //     cutCircle(cenNode[i], -5);
    //     if (if_cut)
    //     {
    //         NODE* node = new NODE;
    //         node->name = -(cenNode[i]->name);
    //         node->childNode.push_back(cenNode[i]);
    //         cenNode[i] = node;
    //         nodeSet.push_back(node);
    //     }
    // }
    for (int i=0; i<cenNode.size(); i++)
    {
        cutCircle(cenNode[i], 5);
    }
    int maxNode = nodeSet.size();
    for (int i=0; i<maxNode; i++)
    {
        if (nodeSet[i]->state==0)
        {
            cutCircle(nodeSet[i], 5);
            NODE* node = new NODE;
            node->name = -(nodeSet[i]->name);
            node->childNode.push_back(nodeSet[i]);
            nodeSet.push_back(node);
            cenNode.push_back(node);
        }
    }

    // // change node name
    // for (auto it=cenNode.begin(); it!=cenNode.end(); it++)
    // {
    //     changeName(*it, (*it)->name);
    //     if (if_link)
    //     {
    //         changeName(*it, link_name);
    //         NODE* node = new NODE;
    //         int pos = ifNodeInSet(cenNode, link_name);
    //         node->childNode.push_back(node);
    //         node->childNode.push_back(*(cenNode.begin()+pos));
    //         if (link_name>0)
    //             link_name = -link_name;
    //         node->name = link_name;
    //         *(cenNode.begin()+pos) = node;
    //         nodeSet.push_back(node);
    //         cenNode.erase(it);
    //     }
    //     else
    //     {
    //         nodeName.push_back((*it)->name);
    //         it = it+1;
    //     }
    // }

}

// --------NodeRecognition private function defination-------------------

void NodeRecognition::newNode(int n1, int n2)
{
    if (n2==-1)
    {
        int pInSet = ifNodeInSet(nodeSet, n1);
        int PInCen = ifNodeInSet(cenNode, n1);
        NODE *node;
        if (pInSet==-1)
        {
            node = new NODE;
            node->name = n1;
            node->weight = n1;
            nodeSet.push_back(node);
            cenNode.push_back(node);
        }
        else
        {
            node = *(nodeSet.begin()+pInSet);
            if (PInCen==-1)
                cenNode.push_back(node);

        }
    }
    else
    {
        int p1InSet = ifNodeInSet(nodeSet, n1);
        int p2InSet = ifNodeInSet(nodeSet, n2);
        NODE *node1, *node2;

        if (p1InSet==-1)
        {
            node1 = new NODE;
            node1->name = n1;
            node1->weight = n1;
            nodeSet.push_back(node1);
        }
        else
        {
            node1 = *(nodeSet.begin()+p1InSet);
        }

        if (p2InSet==-1)
        {
            node2 = new NODE;
            node2->name = n2;
            node2->weight = n2;
            nodeSet.push_back(node2);
            cenNode.push_back(node2);
        }
        else
        {
            node2 = *(nodeSet.begin()+p2InSet);
        }
        
        node2->childNode.push_back(node1);
        int p1InCen = ifNodeInSet(cenNode, n1);
        int p2InCen = ifNodeInSet(cenNode, n2);
        if (p1InCen!=-1)
            cenNode.erase(cenNode.begin()+p1InCen);
    }
            
}

int NodeRecognition::ifNodeInSet(vector<NODE*> set, int name)
{
    int pos = -1;
    for (int i=0; i<set.size(); i++)
    {
        if (set[i]->name==name)
            pos = i;
    }
    return pos;
}

bool NodeRecognition::cutCircle(NODE* node, int c)
{
    if (node->childNode.size()==0)
    {
        node->state = node->state+c;
        return true;
    }
    else
    {
        for (int i=0; i<node->childNode.size();)
        {
            node->state = node->state+c;
            if (node->state==node->childNode[i]->state)
            {
                node->childNode.erase(node->childNode.begin()+i);
                if_cut = true;
                return true;
            }
            else
            {
                if (!cutCircle(node->childNode[i], c));
                {
                    return false;
                }
                i = i+1;
            }
        }
        return true;
    }
}

bool NodeRecognition::changeName(NODE* node, int name)
{
    if (node->childNode.size()==0)
    {
        node->name = name;
        return true;
    }
    else
    {
        for (int i=0; i<node->childNode.size();)
        {
            node->name = name;
            if_link = ifLink(node->childNode[i]->name);
            if (if_link)
            {
                link_name = node->childNode[i]->name;
                node->childNode.erase(node->childNode.begin()+i);
                return true;
            }
            else
            {
                if (!changeName(node->childNode[i], name));
                {
                    return false;
                }
                i = i+1;
            }
        }
        return true;
    }
}

bool NodeRecognition::ifLink(int name)
{
    bool flag = false;
    for (int i=0; i<nodeName.size(); i++)
    {
        if (name==nodeName[i])
            flag = true;
    }
    return flag;
}
