/*

�� �� ������
����ÿһ���ڵ�Ϊһ�Զ�Ľڵ���ʽ������ÿһ���ڵ�ֻ��Ψһǰ�����ǿ���������̣���������ֻ��һ�����ڵ㡣����������֮�以���ཻ��
����ĳһ�ڵ�ĺ���������Ϊ�ȡ����Ĳ�μ���������Ϊ���ĸ߶ȡ�ֻ��ǰ��û�к�̵Ľڵ㣬��Ϊ����Ҷ�ӽڵ㡣
����������ڵĹ�ʽ�͹�ϵ���Ͳ�չ��˵����
******************************************************************************************************************************************************
��������������������ʽ�������������еĹ�ϵ����������һ����������������һ����������
��������ÿһ���ڵ㶼ֻ��Ψһǰ�������������ڶ��ĺ�̽ڵ㣬���Ҷ������ϸ�涨ÿһ�ڵ�ĺ��ӱ���ָ�������ӻ����Һ��ӣ�����ֻ��һ����̣�Ҳ��Ҫ˵����
��ߺ�̻����ұߺ�̣������Ľڵ�ֱ��û�����ֹ�ϵ�����������������ǰ�����ϵ��
����������һ���Ա��ǣ��Ѿ��涨�˸����ڵ�����У��������£��������ҹ涨�˸���λ�õ����кţ����Ը�λ��û�нڵ㣬�����ܺ������еĴ��ڡ��ڵ�֮������й�ϵ��
����Ҫ�ġ��޷����Եı�����������

�������Ľṹ�ǵݹ�ģ���˹��ڶ������Ĳ����ܶ඼�ǵݹ�ġ�

����������ÿһ���ڵ�����ұ�����������̡�
��ȫ����������һ�þ���n���ڵ�Ķ���������������ұ��򣬶�������ĳ���ڵ�ı�����ͬ��λ�õ����������ڵ�ı�����ͬ������нڵ㶼��������������������Ϊ��ȫ��������
��������һ������ȫ����������ȫ��������һ��������������

�������ı������������ DLR,������� LDR,�������� LRD����������������ĵĲ�����
�������Ĵ洢�ṹ��A.˳��洢�����ն������Ĺ涨�����Ⱥ�洢�������У�û�нڵ����0��
                B.��ʽ�洢�� ÿһ�ڵ��ָ���������������Һ��ӵ�ָ�룬��������������

�������Ĳ�����A.����ݹ���� B.����ǵݹ��������ջ��ʵ�֣� C.��α������ö�����ʵ�֣�D.������ݹ飬���սڵ��� # ��ʾ������������ E.�ݹ鸴�� ������
*/

#include<iostream>
#include "5.ջ\��ʽջ\Linkstack.cpp"

using namespace std;

class btnode{
public:
    char data;
    btnode *_lchild,*_rchild;
};

class binarytree{//��������
public:
    binarytree(){
        _root =nullptr;//���캯�������ʼ����ָ��
    };
    ~binarytree(){
        destroy(_root);//���������ͷ����нڵ�
    };

    void initbtree();//��_root���� ��ʼ��������
    void DLRroot();//��_root��ʼ���� ���������� 
    void LDRroot();//��_root��ʼ���� �ǵݹ����������


private:
    btnode *_root;//��ָ��
    void createbtree(btnode* &_p);//����DLR�ݹ� ����������
    void destroy(btnode* &_p);//����LRD�ݹ� ���ٶ�����
    void DLR(btnode* &_p);//����DLR�ݹ� ����
    void LDR(btnode* &_p);//����LDR�ǵݹ� ����
};



void binarytree::initbtree(){//��_root������ʼ��������
    createbtree(_root);
}

void binarytree::createbtree(btnode* &_p){//����DLR�ݹ齨��������,����Ϊ�ڵ��һ��ָ�����,
    char input;                         //�˴�����һ���򵥵��﷨BUG��֮ǰ��������ʹ�á���btnode* _p)����ʽ��������ϸ��ᣬ
    cin>>input;                         //�˴���Ҫ��ָ�����������и�ֵ�����������Ҫ���� & ���÷�����ָ֤��Ĵ���˳����
    if (input == '#')
    {
        _p = nullptr;
    }else{
        _p = new btnode;//����ֵ�������ָ�������һ���ڴ�ռ�
        _p->data = input;
        createbtree(_p->_lchild);//�ݹ飬��������ڵ������ָ�����
        createbtree(_p->_rchild);
    }
}

void binarytree::destroy(btnode* &_p){
    if (_p)//��ָ������ǿ�
    {
        destroy(_p->_lchild);//�˴��ݹ�ֻ��һ���������ã������ҵ��ǿյ�Ҷ�ӽڵ�
        destroy(_p->_rchild);
        delete _p;
        _p = nullptr;
    } 
} 

void binarytree::DLRroot(){//��_root��ʼ���� ����������
    DLR(_root);
}

void binarytree::DLR(btnode* &_p){//DLR����ݹ� ����
    if(_p){
        cout<<_p->data<<" ";
        DLR(_p->_lchild);
        DLR(_p->_rchild);
    }else{
        cout<<"#"<<" ";
    }
}

void binarytree::LDRroot(){
    LDR(_root);
}

void LDR(btnode* &_p){//����LDR�ǵݹ� ����������д�����е��Σ���Ҫ˼����
    btnode* _cur = _p;
    linkstack<btnode*> stack;//ջ�д�ŵ������� �������Ľڵ��ָ�� ����
    while(_cur || !stack.isempty()){
        if(_cur != nullptr){//���Ӳ�Ϊ0��˵��������ڵ㣬_cur��������һֱ����
            stack.push(_cur);
            _cur = _cur->_lchild; 
        }else{
            stack.pop(_cur);
            cout<<_cur->data<<" ";
            _cur = _cur->_rchild;
           }
        }
    }
    // if(!_cur){
    //     cout<<"empty binarytree"<<endl;
    // }else{
    //     while(_cur != nullptr){//_cur��������һֱ���£�ѭ������ʱ��ջ�ڴ�������������ڵ�
    //             stack.push(_cur);
    //             _cur = _cur->_lchild;
    //     }
    //     //��������Ҷ�ӽڵ�֮�󣬿�ʼ��ջ���ⵯ��Ԫ��
    //     while(!stack.isempty()){
    //         stack.pop(_cur);
    //         cout<<_cur->data<<" ";
    //         if(_cur->_rchild != nullptr){
    //             _cur = _cur->_rchild;
    //         }
    //     }
    // }
    





int main(){
    binarytree btree;
    cout<<"please input DLR data order"<<endl;
    btree.initbtree();
    btree.DLRroot();
    btree.LDRroot();
}






