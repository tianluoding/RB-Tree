#ifndef RBNODE_H
#define RBNODE_H

template<typename T>
struct RBNode
{
    RBNode* _left;
    RBNode* _right;
    RBNode* _parent;
    T _val;
    bool _color;//ºì 1 ºÚ 0
    RBNode(T value);
  
    ~RBNode();
};


#endif