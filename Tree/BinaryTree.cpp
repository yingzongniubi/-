/*

树 与 二叉树
树的每一个节点为一对多的节点形式，即，每一个节点只有唯一前驱但是可能有许多后继，并且有且只有一个根节点。且树的子树之间互不相交。
树上某一节点的孩子数量称为度。树的层次即代数，称为树的高度。只有前驱没有后继的节点，称为树的叶子节点。
树有许多内在的公式和关系，就不展开说明。
******************************************************************************************************************************************************
二叉树不是树的特殊形式，而是与树并列的关系。二叉树是一种有序树，而树是一种无序树。
二叉树的每一个节点都只有唯一前驱与数量不大于二的后继节点，并且二叉树严格规定每一节点的孩子必须指定是左孩子还是右孩子，哪怕只有一个后继，也需要说明是
左边后继还是右边后继，而树的节点直接没有这种关系，因此树与二叉树不是包含关系。
二叉树的另一特性便是，已经规定了各个节点的序列，从上至下，从左至右规定了各个位置的序列号，可以该位置没有节点，但不能忽略序列的存在。节点之间的序列关系是
很重要的、无法忽略的便是有序树。

二叉树的结构是递归的，因此关于二叉树的操作很多都是递归的。

满二叉树：每一个节点均有且必须有两个后继。
完全二叉树：对一棵具有n个节点的二叉树按层序从左到右编序，二叉树树某个节点的编序与同样位置的满二叉树节点的编序相同如果所有节点都满足这个条件，则二叉树为完全二叉树。
满二叉树一定是完全二叉树；完全二叉树不一定是满二叉树。

二叉树的遍历：先序遍历 DLR,中序遍历 LDR,后续遍历 LRD。遍历操作是最核心的操作。
二叉树的存储结构：A.顺序存储：按照二叉树的规定序列先后存储在数组中，没有节点便置0。
                B.链式存储： 每一节点的指针域中有左孩子与右孩子的指针，叫做二叉链树。

二叉树的操作：A.先序递归遍历 B.中序非递归遍历（用栈来实现） C.层次遍历（用队列来实现）D.按先序递归，将空节点用 # 表示，建立二叉树 E.递归复制 二叉树
*/

#include<iostream>
#include "5.栈\链式栈\Linkstack.cpp"

using namespace std;

class btnode{
public:
    char data;
    btnode *_lchild,*_rchild;
};

class binarytree{//二叉链树
public:
    binarytree(){
        _root =nullptr;//构造函数里面初始化根指针
    };
    ~binarytree(){
        destroy(_root);//析构函数释放所有节点
    };

    void initbtree();//以_root参数 初始化二叉树
    void DLRroot();//从_root开始先序 遍历二叉树 
    void LDRroot();//从_root开始中序 非递归遍历二叉树


private:
    btnode *_root;//根指针
    void createbtree(btnode* &_p);//先序DLR递归 建立二叉树
    void destroy(btnode* &_p);//后序LRD递归 销毁二叉树
    void DLR(btnode* &_p);//先序DLR递归 遍历
    void LDR(btnode* &_p);//中序LDR非递归 遍历
};



void binarytree::initbtree(){//以_root参数初始化二叉树
    createbtree(_root);
}

void binarytree::createbtree(btnode* &_p){//先序DLR递归建立二叉树,参数为节点的一个指针变量,
    char input;                         //此处碰到一个简单的语法BUG：之前参数传参使用“（btnode* _p)”形式，但是仔细体会，
    cin>>input;                         //此处需要对指针变量本身进行赋值操作，因此需要加上 & 引用符来保证指针的传参顺利。
    if (input == '#')
    {
        _p = nullptr;
    }else{
        _p = new btnode;//若有值，便给该指针变量赋一个内存空间
        _p->data = input;
        createbtree(_p->_lchild);//递归，传入新造节点的左孩子指针变量
        createbtree(_p->_rchild);
    }
}

void binarytree::destroy(btnode* &_p){
    if (_p)//此指针变量非空
    {
        destroy(_p->_lchild);//此处递归只是一个引导作用，引导找到非空的叶子节点
        destroy(_p->_rchild);
        delete _p;
        _p = nullptr;
    } 
} 

void binarytree::DLRroot(){//从_root开始先序 遍历二叉树
    DLR(_root);
}

void binarytree::DLR(btnode* &_p){//DLR先序递归 遍历
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

void LDR(btnode* &_p){//中序LDR非递归 遍历，代码写起来有点晕，主要思想是
    btnode* _cur = _p;
    linkstack<btnode*> stack;//栈中存放的类型是 二叉树的节点的指针 类型
    while(_cur || !stack.isempty()){
        if(_cur != nullptr){//左孩子不为0，说明还有左节点，_cur沿着左链一直向下
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
    //     while(_cur != nullptr){//_cur沿着左链一直向下，循环结束时，栈内存放有所有左链节点
    //             stack.push(_cur);
    //             _cur = _cur->_lchild;
    //     }
    //     //到达最左叶子节点之后，开始从栈向外弹出元素
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






