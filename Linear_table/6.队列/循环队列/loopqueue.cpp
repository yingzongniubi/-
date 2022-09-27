#include <iostream>
#include "6.队列/循环队列/loopqueue.hpp"

using namespace std;

void loopqueue::push(int data){
    if ((end+1)%arrlen == head)
    {
        cout<<"队列已满"<<endl;
    }else{
        arr[end] = data;
        end = (end+1)%arrlen;//利用取余运算的性质，来完成循环队列，这是循环队列的核心操作
    }  
}

void loopqueue::pop(int &out){
    if (end = head)
    {
        cout<<"队列已空，无法出列元素"<<endl;
    }else{
        out = arr[head];
        head = (head+1)%arrlen;
    }
}

void loopqueue::empty_queue(){
    if (end = head)
    {
        cout<<"队伍已空"<<endl;
    }else{
        while (head != end)
        {
            pop(out);
        }
    }
}

void loopqueue::getlength(){
    
}