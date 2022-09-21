#include <iostream>
#include "llist.hpp"

using namespace std;

void llist::init_llist(int n,int arr[]){
    node *_cur = _head;//ע�Ḩ��ָ�룬ָ��ͷ���
    for(int i=0;i<n;i++){
        //node node;ѭ������ʵ�������󡣡�����������ʵ���������int nһ��ȫ�Ǿֲ�����
        node *_node = new node;//����������ָ�������ڴ棬һ����ʵ����������Ľ���ָ��_node�Ǿֲ����ͣ����������ͻ���ʧ������������ڴ治����ʧ
        _node->data = arr[i];
        _cur->_next = _node;//�ø���ָ�������������ע��ڵ�ĵ�ַ������ǰ���ڵ�
        _cur = _cur->_next;//�ƶ�����ָ������ע��ڵ�
    }
    length = n;
}

void llist::is_empty(){
    node *_cur = _head->_next;//ע�Ḩ��ָ�룬ָ��ͷ����ָ����
    int count = 0;
    while (_cur){count++;_cur = _cur->_next;}
    if(count){
        cout<<"�˱�Ϊ"<<count<<endl;
    }else{
        cout<<"�˱�Ϊ��";
    }
}

void llist::getlength(){
    llist::is_empty();
}

void llist::show(){
    node *_cur = _head->_next;
    if (_cur == 0)
    {
        cout<<"�˱�Ϊ��"<<endl;
    }else{
        cout<<"�˱�Ϊ";
        while (_cur)
        {
            cout<<_cur->data<<" -> ";
            _cur = _cur->_next;
        }
        cout<<endl;
    }
}

void llist::make_empty(){
    node *_cur,*_d = _head->_next;//������������ָ�룬_cur��������_d�ͷ��ڴ�,��ȫ��������Ԫ�ڵ�
    while (_cur)
    {
        _cur = _cur->_next;
        delete _d;
        _d = _cur;
    }
    _cur = NULL;
    _d = NULL;
    _head->_next = nullptr;//ͷ���ָ���򸳿�
}

void llist::find_x(int x){
    node *_cur = _head->_next;
    int count,i = 0;
    while(_cur){
        count++;
        if(_cur->data == x){
            i++;
            cout<<"�ҵ��˵�"<<i<<"��"<<x<<"λ��"<<count<<"��"<<endl;
        }
        _cur = _cur->_next;
    }
    if(!i){
        cout<<"������û�и�ֵ"<<endl;
    }
}

void llist::find_i(int i){
    node *_cur = _head->_next;
    int count = 0;
    if(i > length){
        cout<<"��������������"<<endl;
    }else{
        while(_cur){
        count++;
        if(count == i){
            cout<<"��"<<i<<"������ֵΪ"<<_cur->data<<endl;
        }
        _cur = _cur->_next;
        }
    }
}

void llist::insertnode(int i,int data){//����data�ڵ�������Ϊi�Ľڵ����
    node *_cur = _head;//����Ϊʲô��_curָ��ͷ����������Ԫ�ڵ㣬��ͼ����һ�¼���
    int count = 0;
    if (i > length)
    {
        cout<<"��������������";
    }else{
        while (_cur && (count != i))
    {
        count++;
        _cur = _cur->_next;
    }
    node *_node = new node;
    _node->data = data;
    _node->_next = _cur->_next;
    _cur->_next = _node;
    }  
}

void llist::deletenode(int i){
    node *_cur = _head;//����Ϊʲô��_curָ��ͷ����������Ԫ�ڵ㣬��ͼ����һ�¼���
    int count = 0;
    if (i > length)
    {
        cout<<"��������������";
    }else{
        while (_cur && (count != (i-1)))//Ϊ����Ϣ��������Ҫ��_cur����i-1��λ����
    {
        count++;
        _cur = _cur->_next;
    }  
    }  
    
    node *_d = _cur->_next;
    _cur->_next = _d->_next;
    delete _d; 
    _d = nullptr;
}