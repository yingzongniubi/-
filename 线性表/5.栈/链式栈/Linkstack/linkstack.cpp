#include "linkstack.hpp"
#include <iostream>

using namespace std;

void linkstack::show(){
    node *_cur = _head;
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

void linkstack::push(int data){
    node *_cur = new node;
    _cur->data = data;
    _cur->_next = nullptr;
    
    _cur->_next = _head;//新申请的节点指针域里面存放栈顶的节点的地址
    _head = _cur;//将栈顶指针移动到压栈的节点
}

void linkstack::pop(int &data){
    if (!_head)
    {
        cout<<"此栈为空"<<endl;
    }else{
        data = _head->data;//数据出栈
        node *_d = _head;
        _head = _head->_next;//栈顶向下移动一个节点
        delete _d;
        _d = nullptr;
    }
}