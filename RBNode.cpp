#include"RBNode.h"

template<typename T>
RBNode<T>::RBNode(T value)
        : _left(nullptr)
        , _right(nullptr)
        , _parent(nullptr)
        , _val(value)
        , _color(1)
    {}

template<typename T>
RBNode<T>::~RBNode(){}