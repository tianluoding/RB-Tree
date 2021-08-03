#ifndef RBTREE_H
#define RBTREE_H

#include"RBNode.h"
#include"RBNode.cpp"
#include<iostream>

using namespace std;

template<typename T>
class RBTree
{
    typedef RBNode<T> RBNode;
public:
    RBTree();
    ~RBTree();
    void Insert(T val);
    void Fix(RBNode* cur);
    void Delete();
    void erase();
    void LDR(RBNode* r)
    {
        if(!r)
            return;
        LDR(r->_left);
        cout<<"color:"<<r->_color<<" "<<r->_val<<" "<<endl;
        LDR(r->_right);
    }

    void PrintLDR()
    {
        LDR(this->root);
    }

    void PrintRoot()
    {
        cout<<"root color:"<<this->root->_color<<" "<<this->root->_val<<endl;
    }

private:
    void LRotate(RBNode* cur);
    void RRotate(RBNode* cur);
    RBNode* root;
};

#endif