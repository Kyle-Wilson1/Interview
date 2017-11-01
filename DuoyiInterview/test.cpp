#include <iostream>
#include <string>
using namespace std;

class test1
{
public:
    test1(string s): m_value(s){
        
    }

    int getValue(){
        return stoi(m_value);
    }

private:
    string m_value;

};

class test2
{
public:
    test2(string s): m_value(s){
       
    }

    string getLongStrOfNumbers(){
        int len=m_value.size();
        int head=-1;
        int max=0,l_key;
        for (int i=0; i<len; i++)
        {
            if (!(m_value[i]>='0' && m_value[i]<='9'))
            {
                if (i-head-1>max)
                {
                    max=i-head-1;
                    l_key=head+1;
                }
                head=i; 
            }
        }
        cout<<"l="<<l_key<<"max="<<max<<endl;
        return m_value.substr(l_key,max);
    }
private:
    string m_value;
};

class test3
{
public:
    test3(int len,int s[]){
        m_len=len;
        for (int i=0; i<len; i++)
        {
            m_value[i]=s[i];
        }
    }
    int getCoreValue()
    {
        int value=m_value[0],count=1;
        for (int i=1; i<m_len; i++)
        {
            if (m_value[i]==value)
            {
                count++;
            }else{
                count--;
                if (count==0)
                {
                    value=m_value[i];
                    count=1;
                }
            }
            cout<<"i="<<i<<"  "<<"value="<<value<<"count="<<count<<endl;
        }
        cout<<"count="<<count<<endl;
        if (count>1)
        {
            return value;
        }else{
            return -1;
        }
    }
private:
    int m_value[1000];
    int m_len;
};

int main(int argc, char * argv[]){

    if (argc<2)
    {
        cout<<"Parameter is not enough"<<endl;
        return 0;
    }

    int num=stoi(argv[1]);
    switch(num)
    {
        case 1:
        {
            test1 t1("123");
            cout<<"string to int: "<<t1.getValue()<<endl;
        }break;

        case 2:
        {
            test2 t2("abcd123456789ed125ss1234567");
            test2 t2_1("1234ed125ss1234567abce");
            cout<<t2.getLongStrOfNumbers()<<endl;
            cout<<t2_1.getLongStrOfNumbers()<<endl;

        }break;

        case 3:
        {
            int l=8,arr[10]={0,5,5,3,5,7,5,5};
            test3 t3(l,arr);
            cout<<t3.getCoreValue()<<endl;
        }break;

        default:
            break;
    }

    return 0;
}