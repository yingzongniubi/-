#include <iostream>

using namespace std;

class node{
public:
    node(){data = 0,_next = NULL;};
    //node(int data,node* p) : data(data),_next(p){};//有参构造函数
    int data;
    node *_next;
};

class llist{
public:
    llist(){
        _head = new node;
        _head->data = 0;
        _head->_next = nullptr;
    };//构造函数里创建一个空的单链表
    ~llist(){
        node *_cur;
        _cur = _head;
        while (_cur)
        {
            _head = _head->_next;
            delete _cur;
            _cur = _head;
        }
        _cur = NULL;
        _head = NULL;
    };//析构函数里销毁链表,_cur释放内存，_head用作引导。此处的遍历操作是整个链表的核心。

    
    void init_llist(int n,int arr[]);//尾插法，创建节点，初始化链表
    void is_empty();//判断是否空表
    void show();//遍历全表
    void make_empty();//清空链表
    void getlength();//求链表长度
    void find_x(int x);//按值查找
    void find_i(int i);//按索引查找
    void insertnode(int i,int data);//插入节点至索引i节点之后
    void deletenode(int i);//删除索引为i的节点

private:
    node *_head;//链表头指针，创建了头指针就意味着有了一个头节点？是的，理论上“node *head”等价于“node node;node *head = &node;”只不过前者没有对象名，使用指针来访问。
    int length = 0;
};