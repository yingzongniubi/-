/*
��Ҳ�����Ա��һ�֣�ֻ�������������������޵����Ա���ֻ�ܴ洢�ַ����͵����ݡ�ͬ���Ĵ�Ҳ��˳��洢����ʽ�洢������ʽ��
������ʽ�洢��ʽ�У�Ϊ����ߴ洢�ܶȣ����Խ�һ���ַ����洢��һ���ڵ��У�������ʽ�� ���� �ַ�����
�����ַ���һ��ʹ��˳��洢����Ϊ�ַ����漰��ɾ�����볡���Ƚ��٣������ϲ�ѯ�������ࡣ
���бȽ���Ҫ���������ַ���ƥ���㷨��BF�㷨�������ƽ�  KMP�㷨
YJJ*/

#include <iostream> 

using namespace std;

class sstring
{
public:
    sstring(){
        arr = new char[15];
    };//���캯����ʼ��һ��˳�����鳤Ϊ15
    ~sstring(){
        delete[] arr;
    };//���������ͷ�˳������

    char *arr;//����ͷָ��
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
    while ((i < a.length) && (j < b.length))//ע�ⳤ�ȴ�1��ʼ���±��0��ʼ
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


