#include "Linkstack/linkstack.hpp"
#include <iostream>

using namespace std;

void menu(){
    cout<<"**********************"<<endl;
    cout<<"        1.压栈        "<<endl;
    cout<<"        2.出栈        "<<endl;
    cout<<"        3.遍历        "<<endl;
    cout<<"        4.退出        "<<endl;
    cout<<"**********************"<<endl;
}

int main(){
    linkstack stack;
    int x,data;

    while (1)
    {
        cout<<"     请输入序号        "<<endl;
        menu();
        cin>>x;
        switch (x)
        {
        case 1:
            cout<<"请输入压栈数据"<<endl;
            int a;cin>>a;
            stack.push(a);
            system("pause");
            break;
        
        case 2:
            stack.pop(data);
            cout<<"栈顶数据已出栈,值为"<<data<<endl;
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