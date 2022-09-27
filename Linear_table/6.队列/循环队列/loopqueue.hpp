/*
队列是线性表的一种，因此也可以有顺序实现与链式实现两种基础结构。
队列的顺序结构有以下几个特点：
1.队列先进先出，后进后出。
2.尾结点进，头节点出。
3.普通的数组顺序实现有假溢出的弊端，即队头出列之后，在不移动所有元素的前提下，队列的前方有数组空间无法利用。
  为解决这一问题引入循环队列。将后来元素插入数组前方的空白空间，构成逻辑上“首尾相接”的“环形”数组存储结构，而实现这一点，核心是取余“%”运算。
4.引入循环队列后的另一问题是判空与判溢问题无法像普通队列一样使用“队头指针 == 队尾指针”的判断条件，可以用三种方法解决这一问题：A.int count = 元素数量；B.另设一标志位来区分满与空；C.将数组
  空间中空出一格。其中C方法最为方便。 
YJJ*/

#include <iostream>

using namespace std;

class loopqueue
{
public:
    loopqueue(){
    arr = new int[arrlen];
    };//初始化一个空的动态数组

    loopqueue(int n){
    arrlen = n;
    arr = new int[arrlen];
    };//有参构造函数，允许初始化一个默认长度不为5的动态数组

    ~loopqueue(){
    delete[] arr;
    };//析构函数销毁数组

    void push(int data);//数据队尾入队
    void pop(int &out);//队头出队
    void empty_queue();//清空队列
    void getlength();//求队列长度    

private:
    int arrlen = 5;//初始化的数组长度
    int out = 0;//出队元素存储
    int *arr;//数组指针，用来存储之后动态申请的数组首地址
    int head = 0;//队头指针，不是指针变量是因为数组只用索引来访问即可
    int end = 0;//队尾指针    
};

