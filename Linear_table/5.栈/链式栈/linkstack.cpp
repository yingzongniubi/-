/*
ջ����������Ա�ֻ��һ�����ڣ����Ƚ�������ص㡣
��Ϊջ����ʹ�õ��ǲ���ɾ�����������һ��ʹ����ʽ�洢�ṹ��
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
    }//���캯�������ʼ��ͷָ�롣�յ���ʽջ��ֻ��һ��ָ��յ�ͷָ�룬������ʽջ����ͷ��㡣

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
    }//��������������һɾ���ڵ��ͷ��ڴ�

    void show();//ջ��Ӧ�����������������������Ƿ�����֤�����Ǽ���
    void push(T data);//ѹջ
    void pop(T &data);//��ջ
    bool isempty();//�ж��Ƿ�Ϊ��ջ��Ϊ�շ���1���ǿշ���0

private:
node<T> *_head;//ͷָ��    
};

template <class T>
void linkstack<T>::show(){
    node<T> *_cur = _head;
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

template <class T>
void linkstack<T>::push(T data){
    node<T> *_cur = new node<T>;
    _cur->data = data;
    _cur->_next = nullptr;
    
    _cur->_next = _head;//������Ľڵ�ָ����������ջ���Ľڵ�ĵ�ַ
    _head = _cur;//��ջ��ָ���ƶ���ѹջ�Ľڵ�
}

template <class T>
void linkstack<T>::pop(T &data){
    if (!_head)
    {
        cout<<"��ջΪ��"<<endl;
    }else{
        data = _head->data;//���ݳ�ջ
        node<T> *_d = _head;
        _head = _head->_next;//ջ�������ƶ�һ���ڵ�
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
