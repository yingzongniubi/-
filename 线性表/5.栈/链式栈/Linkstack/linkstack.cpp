#include "linkstack.hpp"
#include <iostream>

using namespace std;

void linkstack::show(){
    node *_cur = _head;
    if(!_cur){
        cout<<"��ջΪ��"<<endl;
    }else{
        cout<<"��ջΪ";
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
    
    _cur->_next = _head;//������Ľڵ�ָ����������ջ���Ľڵ�ĵ�ַ
    _head = _cur;//��ջ��ָ���ƶ���ѹջ�Ľڵ�
}

void linkstack::pop(int &data){
    if (!_head)
    {
        cout<<"��ջΪ��"<<endl;
    }else{
        data = _head->data;//���ݳ�ջ
        node *_d = _head;
        _head = _head->_next;//ջ�������ƶ�һ���ڵ�
        delete _d;
        _d = nullptr;
    }
}