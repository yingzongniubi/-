#include <iostream>

using namespace std;

class node{
public:
    node(){data = 0,_next = NULL;};
    node(int data,node* p) : data(data),_next(p){};//�вι��캯��
    int data;
    node *_next;
};

class linkstack{
public:
    linkstack(){
        _head = nullptr;
    }//���캯�������ʼ��ͷָ�롣�յ���ʽջ��ֻ��һ��ָ��յ�ͷָ�룬������ʽջ����ͷ��㡣

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
    }//��������������һɾ���ڵ��ͷ��ڴ�

    void show();//ջ��Ӧ�����������������������Ƿ�����֤�����Ǽ���
    void push(int data);//ѹջ
    void pop(int &data);//��ջ

private:
node *_head;//ͷָ��    
};