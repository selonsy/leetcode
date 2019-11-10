#ifndef LINKLIST_H
#define LINKLIST_H
#include "Node.h"
#include <vector>
#include <iostream>
template <class T>
//构建一个单链表类
class LinkList
{
public:
    //selonsy
    LinkList(std::vector<T> vec); //以指定数组构建一个单链表;

    LinkList();                            //构建一个单链表;
    ~LinkList();                           //销毁一个单链表;
    void CreateLinkList(int n);            //创建一个单链表
    void TravalLinkList();                 //遍历线性表
    int GetLength();                       //获取线性表长度
    bool IsEmpty();                        //判断单链表是否为空
    Node<T> *Find(T data);                 //查找节点
    void InsertElemAtEnd(T data);          //在尾部插入指定的元素
    void InsertElemAtIndex(T data, int n); //在指定位置插入指定元素
    void InsertElemAtHead(T data);         //在头部插入指定元素
    void DeleteElemAtEnd();                //在尾部删除元素
    void DeleteAll();                      //删除所有数据
    void DeleteElemAtPoint(T data);        //删除指定的数据
    void DeleteElemAtHead();               //在头部删除节点
private:
    Node<T> *head; //头结点
};

//selonsy
//以指定数组构建一个单链表;
template <class T>
LinkList<T>::LinkList(std::vector<T> vec) : LinkList()
{
    // LinkList();
    // for(int i=0;i<vec.size();i++)
    // {
    //     InsertElemAtEnd(vec[i]);
    // }
    if (vec.size() == 0)
        return;
    // LinkList();
    Node<T> *p = head, *temp;
    for (int i = 0; i < vec.size(); i++)
    {
        temp = new Node<T>;
        temp->data = vec[i];
        temp->next = nullptr;
        p->next = temp;
        p = temp;
        /* code */
    }
}

//初始化单链表
template <class T>
LinkList<T>::LinkList()
{
    head = new Node<T>;
    head->data = 0;    //将头结点的数据域定义为0
    head->next = NULL; //头结点的下一个定义为NULL
}

//销毁单链表
template <class T>
LinkList<T>::~LinkList()
{
    delete head; //删除头结点
}

//创建一个单链表
template <class T>
void LinkList<T>::CreateLinkList(int n)
{
    Node<T> *pnew, *ptemp;
    ptemp = head;
    if (n < 0)
    { //当输入的值有误时，处理异常
        std::cout << "输入的节点个数有误" << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
    { //将值一个一个插入单链表中
        pnew = new Node<T>;
        std::cout << "请输入第" << i + 1 << "个值: ";
        std::cin >> pnew->data;
        pnew->next = NULL;  //新节点的下一个地址为NULL
        ptemp->next = pnew; //当前结点的下一个地址设为新节点
        ptemp = pnew;       //将当前结点设为新节点
    }
}

//遍历单链表
template <class T>
void LinkList<T>::TravalLinkList()
{
    if (head == NULL || head->next == NULL)
    {
        std::cout << "链表为空表" << std::endl;
    }
    Node<T> *p = head;      //另指针指向头结点
    while (p->next != NULL) //当指针的下一个地址不为空时，循环输出p的数据域
    {
        p = p->next; //p指向p的下一个地址
        std::cout << p->data << " ";
    }
}

//获取单链表的长度
template <class T>
int LinkList<T>::GetLength()
{
    int count = 0;           //定义count计数
    Node<T> *p = head->next; //定义p指向头结点
    while (p != NULL)        //当指针的下一个地址不为空时，count+1
    {
        count++;
        p = p->next; //p指向p的下一个地址
    }
    return count; //返回count的数据
}

//判断单链表是否为空
template <class T>
bool LinkList<T>::IsEmpty()
{
    if (head->next == NULL)
    {
        return true;
    }
    return false;
}

//查找节点
template <class T>
Node<T> *LinkList<T>::Find(T data)
{
    Node<T> *p = head;
    if (p == NULL)
    { //当为空表时，报异常
        std::cout << "此链表为空链表" << std::endl;
        return nullptr;
    }
    else
    {
        while (p->next != NULL) //循环每一个节点
        {
            if (p->data == data)
            {
                return p; //返回指针域
            }
            p = p->next;
        }
        return NULL; //未查询到结果
    }
}

//在尾部插入指定的元素
template <class T>
void LinkList<T>::InsertElemAtEnd(T data)
{
    Node<T> *newNode = new Node<T>; //定义一个Node结点指针newNode
    newNode->next = NULL;           //定义newNode的数据域和指针域
    newNode->data = data;
    Node<T> *p = head; //定义指针p指向头结点
    if (head == NULL)
    { //当头结点为空时，设置newNode为头结点
        head = newNode;
    }
    else //循环知道最后一个节点，将newNode放置在最后
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

//在指定位置插入指定元素
template <class T>
void LinkList<T>::InsertElemAtIndex(T data, int n)
{
    if (n < 1 || n > GetLength()) //输入有误报异常
        std::cout << "输入的值错误" << std::endl;
    else
    {
        Node<T> *ptemp = new Node<T>; //创建一个新的节点
        ptemp->data = data;           //定义数据域
        Node<T> *p = head;            //创建一个指针指向头结点
        int i = 1;
        while (n > i) //遍历到指定的位置
        {
            p = p->next;
            i++;
        }
        ptemp->next = p->next; //将新节点插入到指定位置
        p->next = ptemp;
    }
}

//在头部插入指定元素
template <class T>
void LinkList<T>::InsertElemAtHead(T data)
{
    Node<T> *newNode = new Node<T>; //定义一个Node<T>结点指针newNode<T>
    newNode->data = data;
    Node<T> *p = head; //定义指针p指向头结点
    if (head == NULL)
    { //当头结点为空时，设置newNode<T>为头结点
        head = newNode;
    }
    newNode->next = p->next; //将新节点插入到指定位置
    p->next = newNode;
}

//在尾部删除元素
template <class T>
void LinkList<T>::DeleteElemAtEnd()
{
    Node<T> *p = head;     //创建一个指针指向头结点
    Node<T> *ptemp = NULL; //创建一个占位节点
    if (p->next == NULL)
    { //判断链表是否为空
        std::cout << "单链表空" << std::endl;
    }
    else
    {
        while (p->next != NULL) //循环到尾部的前一个
        {
            ptemp = p;   //将ptemp指向尾部的前一个节点
            p = p->next; //p指向最后一个节点
        }
        delete p; //删除尾部节点
        p = NULL;
        ptemp->next = NULL;
    }
}

//删除所有数据
template <class T>
void LinkList<T>::DeleteAll()
{
    Node<T> *p = head->next;
    Node<T> *ptemp = new Node<T>;
    while (p != NULL) //在头结点的下一个节点逐个删除节点
    {
        ptemp = p;
        p = p->next;
        head->next = p;
        ptemp->next = NULL;
        delete ptemp;
    }
    head->next = NULL; //头结点的下一个节点指向NULL
}

//删除指定的数据
template <class T>
void LinkList<T>::DeleteElemAtPoint(T data)
{
    Node<T> *ptemp = Find(data); //查找到指定数据的节点位置
    if (ptemp == head->next)
    { //判断是不是头结点的下一个节点，如果是就从头部删了它
        DeleteElemAtHead();
    }
    else
    {
        Node<T> *p = head;       //p指向头结点
        while (p->next != ptemp) //p循环到指定位置的前一个节点
        {
            p = p->next;
        }
        p->next = ptemp->next; //删除指定位置的节点
        delete ptemp;
        ptemp = NULL;
    }
}

//在头部删除节点
template <class T>
void LinkList<T>::DeleteElemAtHead()
{
    Node<T> *p = head;
    if (p == NULL || p->next == NULL)
    { //判断是否为空表，报异常
        std::cout << "该链表为空表" << std::endl;
    }
    else
    {
        Node<T> *ptemp = NULL; //创建一个占位节点
        p = p->next;
        ptemp = p->next; //将头结点的下下个节点指向占位节点
        delete p;        //删除头结点的下一个节点
        p = NULL;
        head->next = ptemp; //头结点的指针更换
    }
}

#endif