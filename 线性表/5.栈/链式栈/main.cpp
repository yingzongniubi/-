#include "Linkstack/linkstack.hpp"
#include <iostream>

using namespace std;

void menu(){
    cout<<"**********************"<<endl;
    cout<<"        1.ѹջ        "<<endl;
    cout<<"        2.��ջ        "<<endl;
    cout<<"        3.����        "<<endl;
    cout<<"        4.�˳�        "<<endl;
    cout<<"**********************"<<endl;
}

int main(){
    linkstack stack;
    int x,data;

    while (1)
    {
        cout<<"     ���������        "<<endl;
        menu();
        cin>>x;
        switch (x)
        {
        case 1:
            cout<<"������ѹջ����"<<endl;
            int a;cin>>a;
            stack.push(a);
            system("pause");
            break;
        
        case 2:
            stack.pop(data);
            cout<<"ջ�������ѳ�ջ,ֵΪ"<<data<<endl;
            system("pause");
            break;

        case 3:
            stack.show();
            system("pause");
            break;

        case 4:
            return 0;
			break;

        default:
            break;
        }
    }
    return 0;
}