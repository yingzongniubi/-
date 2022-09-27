/*
串也是线性表的一种，只不过串是数据类型受限的线性表。串只能存储字符类型的数据。同样的串也有顺序存储与链式存储两种形式。
串的链式存储形式中，为了提高存储密度，可以将一块字符串存储在一个节点中，这种形式叫 块链 字符串。
但是字符串一般使用顺序存储，因为字符串涉及的删除插入场景比较少，基本上查询操作更多。
串中比较重要的内容是字符串匹配算法。BF算法：暴力破解  KMP算法
YJJ*/

#include <iostream> 

using namespace std;

class sstring
{
public:
    sstring(){
        arr = new char[15];
    };//构造函数初始化一个顺序数组长为15
    ~sstring(){
        delete[] arr;
    };//析构函数释放顺序数组

    char *arr;//数组头指针
    int length;
    
    void init(){
        cout<<"pls input the chars"<<endl;
        cin>>arr;
        int i = 0;
        while (arr[i] != '\0'){ i++; }
        length = i;
    }
};


    

int main(){
    sstring a,b;
    a.init();b.init();
    
    int i,j = 0;
    while ((i < a.length) && (j < b.length))//注意长度从1开始，下标从0开始
    {
        if (a.arr[i] == b.arr[j])
        {
            ++i;++j;
        }else{
            i = i-j+1;
            j = 0;
        }
    }
    if (j >= b.length)
    {
        cout<<"match success,"<<i-b.length<<endl;
    }else{
        cout<<"match fail"<<endl;
    }
}


