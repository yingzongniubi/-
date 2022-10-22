/*
栈是特殊的线性表，只有一个出口，有先进后出的特点。
因为栈更多使用的是插入删除操作，因此一般使用链式存储结构。
*/

#include <iostream>

using namespace std;

template <class T>
class node{
public:
    node(){data = 0,_next = NULL;};
    T data;
    node<T> *_next;
};

template <class T>
class linkstack{
public:
    linkstack(){
        _head = nullptr;
    }//构造函数里面初始化头指针。空的链式栈就只有一个指向空的头指针，而且链式栈不带头结点。

    ~linkstack(){
        node<T> *_d = _head;
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
    void push(T data);//压栈
    void pop(T &data);//出栈
    bool isempty();//判断是否为空栈，为空返回1，非空返回0

private:
node<T> *_head;//头指针    
};

template <class T>
void linkstack<T>::show(){
    node<T> *_cur = _head;
    if(!_cur){
        cout<<"此栈为空"<<endl;
    }else{
        cout<<"该栈为";
        while (_cur)
        {
            cout<<_cur->data<<"->";
            _cur = _cur->_next;
        }
    }
}

template <class T>
void linkstack<T>::push(T data){
    node<T> *_cur = new node<T>;
    _cur->data = data;
    _cur->_next = nullptr;
    
    _cur->_next = _head;//新申请的节点指针域里面存放栈顶的节点的地址
    _head = _cur;//将栈顶指针移动到压栈的节点
}

template <class T>
void linkstack<T>::pop(T &data){
    if (!_head)
    {
        cout<<"此栈为空"<<endl;
    }else{
        data = _head->data;//数据出栈
        node<T> *_d = _head;
        _head = _head->_next;//栈顶向下移动一个节点
        delete _d;
        _d = nullptr;
    }
}

template <class T>
bool linkstack<T>::isempty(){
    if(_head){
        return 0
    }else{
        return 1
    }
}
