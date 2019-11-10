#include "List.h"
#include "List2.h"
using namespace std;
int main()
{
    // 双向链表
    List2<float> ls1;
    ls1.add(1.1);
    ls1.add(0.1);
    ls1.add(6);
    ls1.add(3.3);
    List2<float> ls2(ls1);
    ls2.resShow();
    std::cout << ls2.size() << std::endl;
    std::cout << ls2.find(00) << std::endl;
    ls2.remove(6);
    ls1.resShow();
    ls2.show();

    // 单向链表
    vector<int> vec = {9, 5, 2, 7};
    LinkList<int> list(vec);
    list.TravalLinkList();

    LinkList<int> l;
    int i;
    cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.获取节点\n";
    cout << "6.在尾部插入指定元素   7.在指定位置插入指定元素   8.在头部插入指定元素\n";
    cout << "9.在尾部删除元素   10.删除所有元素   11.删除指定元素   12.在头部删除元素   0.退出" << endl;
    do
    {
        cout << "请输入要执行的操作: ";
        cin >> i;
        switch (i)
        {
        case 1:
            int n;
            cout << "请输入单链表的长度: ";
            cin >> n;
            l.CreateLinkList(n);
            break;
        case 2:
            l.TravalLinkList();
            break;
        case 3:
            cout << "该单链表的长度为" << l.GetLength() << endl;
            break;
        case 4:
            if (l.IsEmpty() == 1)
                cout << "该单链表是空表" << endl;
            else
            {
                cout << "该单链表不是空表" << endl;
            }
            break;
        case 5:
            int data;
            cout << "请输入要获取节点的值: ";
            cin >> data;
            cout << "该节点的值为" << l.Find(data)->data << endl;
            break;
        case 6:
            int endData;
            cout << "请输入要在尾部插入的值: ";
            cin >> endData;
            l.InsertElemAtEnd(endData);
            break;
        case 7:
            int pointData;
            int index;
            cout << "请输入要插入的数据: ";
            cin >> pointData;
            cout << "请输入要插入数据的位置: ";
            cin >> index;
            l.InsertElemAtIndex(pointData, index);
            break;
        case 8:
            int headData;
            cout << "请输入要在头部插入的值: ";
            cin >> headData;
            l.InsertElemAtHead(headData);
            break;
        case 9:
            l.DeleteElemAtEnd();
            break;
        case 10:
            l.DeleteAll();
            break;
        case 11:
            int pointDeleteData;
            cout << "请输入要删除的数据: ";
            cin >> pointDeleteData;
            l.DeleteElemAtPoint(pointDeleteData);
            break;
        case 12:
            l.DeleteElemAtHead();
            break;
        default:
            break;
        }
    } while (i != 0);

    system("pause");
    return 0;
}