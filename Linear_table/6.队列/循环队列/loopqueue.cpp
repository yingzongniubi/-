#include <iostream>
#include "6.����/ѭ������/loopqueue.hpp"

using namespace std;

void loopqueue::push(int data){
    if ((end+1)%arrlen == head)
    {
        cout<<"��������"<<endl;
    }else{
        arr[end] = data;
        end = (end+1)%arrlen;//����ȡ����������ʣ������ѭ�����У�����ѭ�����еĺ��Ĳ���
    }  
}

void loopqueue::pop(int &out){
    if (end = head)
    {
        cout<<"�����ѿգ��޷�����Ԫ��"<<endl;
    }else{
        out = arr[head];
        head = (head+1)%arrlen;
    }
}

void loopqueue::empty_queue(){
    if (end = head)
    {
        cout<<"�����ѿ�"<<endl;
    }else{
        while (head != end)
        {
            pop(out);
        }
    }
}

void loopqueue::getlength(){
    
}