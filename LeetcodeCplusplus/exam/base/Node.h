#ifndef NODE_H
#define NODE_H
template <class T>
class Node2
{
public:
    Node2<T> *next;
    Node2<T> *prev;
    T data;
};

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
};
#endif
