#include <iostream>
#include "llist.hpp"

using namespace std;

int main(){
    llist llist;
    cout<<"请输入链表节点个数"<<endl;
    int n;
    cin>>n;
    cout<<"请输入节点数据"<<endl;
    int *arr = new int[n];//动态数组
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    llist.init_llist(n,arr);
    
    cout<<"*******************"<<endl;
    llist.is_empty();
    cout<<"*******************"<<endl;
    llist.show();
    cout<<"*******************"<<endl;
    cout<<"请输入想查询的值"<<endl;
    int x;
    cin>>x;
    llist.find_x(x);
    cout<<"*******************"<<endl;
    cout<<"请输入想查看的索引"<<endl;
    int i;
    cin>>i;
    llist.find_i(i);
    cout<<"*******************"<<endl;
    cout<<"将插入节点在输入的索引节点之后，请输入索引值与数据"<<endl;
    int a,b;
    cin>>a;cin>>b;
    llist.insertnode(a,b);
    cout<<"*******************"<<endl;
    llist.show();
    cout<<"*******************"<<endl;
    cout<<"将删除输入索引值的节点，请输入一个索引值"<<endl;
    int c;cin>>c;
    llist.deletenode(c);
    cout<<"*******************"<<endl;
    llist.show();
    cout<<"接下来将清空链表"<<endl;
    llist.make_empty();
    cout<<"*******************"<<endl;
    llist.show();

    delete[] arr;
    return 0;
}