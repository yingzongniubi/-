#include <iostream>
#include "llist.hpp"

using namespace std;

int main(){
    llist llist;
    cout<<"����������ڵ����"<<endl;
    int n;
    cin>>n;
    cout<<"������ڵ�����"<<endl;
    int *arr = new int[n];//��̬����
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
    cout<<"���������ѯ��ֵ"<<endl;
    int x;
    cin>>x;
    llist.find_x(x);
    cout<<"*******************"<<endl;
    cout<<"��������鿴������"<<endl;
    int i;
    cin>>i;
    llist.find_i(i);
    cout<<"*******************"<<endl;
    cout<<"������ڵ�������������ڵ�֮������������ֵ������"<<endl;
    int a,b;
    cin>>a;cin>>b;
    llist.insertnode(a,b);
    cout<<"*******************"<<endl;
    llist.show();
    cout<<"*******************"<<endl;
    cout<<"��ɾ����������ֵ�Ľڵ㣬������һ������ֵ"<<endl;
    int c;cin>>c;
    llist.deletenode(c);
    cout<<"*******************"<<endl;
    llist.show();
    cout<<"���������������"<<endl;
    llist.make_empty();
    cout<<"*******************"<<endl;
    llist.show();

    delete[] arr;
    return 0;
}