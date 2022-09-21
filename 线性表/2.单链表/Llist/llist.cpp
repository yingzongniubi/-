#include <iostream>
#include "llist.hpp"

using namespace std;

void llist::init_llist(int n,int arr[]){
    node *_cur = _head;//注册辅助指针，指向头结点
    for(int i=0;i<n;i++){
        //node node;循环里面实例化对象。。？函数里面实例化的类和int n一样全是局部变量
        node *_node = new node;//函数里面用指针申请内存，一样是实例化，这里的接收指针_node是局部类型，函数结束就会消失，但是申请的内存不会消失
        _node->data = arr[i];
        _cur->_next = _node;//用辅助指针操作，输入新注册节点的地址进入其前驱节点
        _cur = _cur->_next;//移动辅助指针至新注册节点
    }
    length = n;
}

void llist::is_empty(){
    node *_cur = _head->_next;//注册辅助指针，指向头结点的指针域
    int count = 0;
    while (_cur){count++;_cur = _cur->_next;}
    if(count){
        cout<<"此表长为"<<count<<endl;
    }else{
        cout<<"此表为空";
    }
}

void llist::getlength(){
    llist::is_empty();
}

void llist::show(){
    node *_cur = _head->_next;
    if (_cur == 0)
    {
        cout<<"此表为空"<<endl;
    }else{
        cout<<"此表为";
        while (_cur)
        {
            cout<<_cur->data<<" -> ";
            _cur = _cur->_next;
        }
        cout<<endl;
    }
}

void llist::make_empty(){
    node *_cur,*_d = _head->_next;//申请两个辅助指针，_cur做引导，_d释放内存,先全部放在首元节点
    while (_cur)
    {
        _cur = _cur->_next;
        delete _d;
        _d = _cur;
    }
    _cur = NULL;
    _d = NULL;
    _head->_next = nullptr;//头结点指针域赋空
}

void llist::find_x(int x){
    node *_cur = _head->_next;
    int count,i = 0;
    while(_cur){
        count++;
        if(_cur->data == x){
            i++;
            cout<<"找到了第"<<i<<"个"<<x<<"位于"<<count<<"处"<<endl;
        }
        _cur = _cur->_next;
    }
    if(!i){
        cout<<"链表中没有该值"<<endl;
    }
}

void llist::find_i(int i){
    node *_cur = _head->_next;
    int count = 0;
    if(i > length){
        cout<<"索引超出链表长度"<<endl;
    }else{
        while(_cur){
        count++;
        if(count == i){
            cout<<"第"<<i<<"索引的值为"<<_cur->data<<endl;
        }
        _cur = _cur->_next;
        }
    }
}

void llist::insertnode(int i,int data){//插入data节点至索引为i的节点后面
    node *_cur = _head;//这里为什么将_cur指向头结点而不是首元节点，画图推演一下即可
    int count = 0;
    if (i > length)
    {
        cout<<"索引超出链表长度";
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
    node *_cur = _head;//这里为什么将_cur指向头结点而不是首元节点，画图推演一下即可
    int count = 0;
    if (i > length)
    {
        cout<<"索引超出链表长度";
    }else{
        while (_cur && (count != (i-1)))//为了信息完整，需要将_cur放在i-1的位置上
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