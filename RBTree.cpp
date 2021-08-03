#include"RBTree.h"
#include<iostream>

using namespace std;

template<typename T>
RBTree<T>::RBTree():root(nullptr) {}

template<typename T>
RBTree<T>::~RBTree() {}

template<typename T>
void RBTree<T>::Insert(T val)
{
    RBNode* node = new RBNode(val);
    if(!this->root)
    {
        this->root = node;
        this->root->_color = 0; //根节点为黑
        return;
    }
    //二叉树插入
    RBNode* curptr = this->root;
    RBNode* cur = nullptr;
    while(curptr)
    {
        if(curptr->_val > val)
        {
            cur = curptr;
            curptr = curptr->_left;
        }
        else
        {
            cur = curptr;
            curptr = curptr->_right;
        }
    }
    if(cur->_val > val)
    {
        cur->_left = node;
        node->_parent = cur;
    }
    else
    {
        cur->_right = node;
        node->_parent = cur;
    }

   
    
    
    //cout<<"fixing"<<endl;
    Fix(node);
        
    
   
        

}

template<typename T>
void RBTree<T>::Fix(RBNode* cur)
{
    RBNode* p_uncle = nullptr;
    int flag = 0;//当前节点为左 -1, 为右孩子 1
    int pflag = 0;//父节点为左 -1， 为右节点 1
    while(cur->_parent != nullptr && cur->_parent->_color){
        RBNode* cur_parent = cur->_parent;//父节点
        RBNode* gradparent = cur_parent->_parent;//祖父节点
        //确定flag
        if(cur_parent->_left == cur)
        {
            flag = -1;
        }
        else
        {
            flag = 1;
        }

        //确定pflag
        if(gradparent->_left == cur_parent)
        {
            pflag = -1;
        }
        else
        {
            pflag = 1;
        }

        //找到叔叔节点
        if(cur_parent->_parent->_left == cur_parent)
        {
            p_uncle = cur_parent->_parent->_right;
        }
        else
        {
            p_uncle = cur_parent->_parent->_left;
        }

        //当叔节点不为空，当叔节点为红时
        if(p_uncle)
        {
            if(p_uncle->_color)
            {
                cur_parent->_color = 0;//父节点涂黑
                p_uncle->_color = 0;//叔节点涂黑
                gradparent->_color = 1;//祖父节点涂红
                cur = gradparent;
            }
            else//叔节点为黑时,四种情况
            {
                if(flag == -1 && pflag == -1)//left left
                {
                    cur_parent->_color = 0;
                    gradparent->_color = 1;
                    cur = gradparent;
                    RRotate(cur);
                }
                else if(flag == -1 && pflag == 1)//left right
                {
                    cur = cur_parent;
                    LRotate(cur);
                }
                else if(flag == 1 && pflag == 1)//right right
                {
                    cur_parent->_color = 0;
                    gradparent->_color = 1;
                    cur = gradparent;
                    LRotate(cur);
                }
                else
                {
                    cur = cur_parent;
                    RRotate(cur);
                }
            }
        }
        else//叔节点为空时，认为是一个黑色节点
        {
            if(flag == -1 && pflag == -1)//left left
                {
                    cur_parent->_color = 0;
                    gradparent->_color = 1;
                    cur = gradparent;
                    RRotate(cur);
                }
                else if(flag == -1 && pflag == 1)//left right
                {
                    cur = cur_parent;
                    LRotate(cur);
                }
                else if(flag == 1 && pflag == 1)//right right
                {
                    cur_parent->_color = 0;
                    gradparent->_color = 1;
                    cur = gradparent;
                    LRotate(cur);
                }
                else
                {
                    cur = cur_parent;
                    RRotate(cur);
                }
        }
    }
    this->root->_color = 0;
}

template<typename T>
void RBTree<T>::LRotate(RBNode* cur)
{
    RBNode* Right_child = cur->_right;
    RBNode* cur_parent = cur->_parent;
    Right_child->_parent = cur_parent;
    cur->_right = Right_child->_left;

    

    if(!cur_parent)
        this->root = Right_child;
    else if(cur == cur_parent->_left)
    {
        cur_parent->_left = Right_child;
    }
    else
    {
        cur_parent->_right = Right_child;
    }
    Right_child->_left = cur;
    cur->_parent = Right_child;
    
        
}

template<typename T>
void RBTree<T>::RRotate(RBNode* cur)
{
    
    RBNode* p = cur->_left;
    RBNode* q = p->_right;
    RBNode* cur_parent = cur->_parent;
    p->_parent = cur_parent;
    cur->_left = q;

   

    if(!cur_parent)
        this->root = p;
    else if(cur == cur_parent->_left)
    {
        cur_parent->_left = p;
    }
    else
    {
        cur_parent->_right = p;
    }
    p->_right = cur;
    cur->_parent = p;
    
    
    
}