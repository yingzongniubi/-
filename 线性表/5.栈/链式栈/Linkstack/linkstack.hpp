#include <iostream>

using namespace std;

class node{
public:
    node(){data = 0,_next = NULL;};
    node(int data,node* p) : data(data),_next(p){};//有参构造函数
    int data;
    node *_next;
};

class linkstack{
public:
    linkstack(){
        _head = nullptr;
    }//构造函数里面初始化头指针。空的链式栈就只有一个指向空的头指针，而且链式栈不带头结点。

    ~linkstack(){
        node *_d = _head;
        while (_head)
        {
            _head = _head->_next;
            delete _d;
            _d = _head;
        }
        _head = nullptr;
        _d = nullptr;
    }//析构函数里面逐一删除节点释放内存

    void show();//栈不应该有这个遍历输出函数，但是方便验证，还是加上
    void push(int data);//压栈
    void pop(int &data);//出栈

private:
node *_head;//头指针    
};