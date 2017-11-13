#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <math.h>
using namespace std;
double v[10];
char opS[4]={'+','-','*','/'};
//根据操作符计算两个数  op：0:+ 1:- 2:* 3:/  
int N,M;
ifstream fin("cal24.in");
ofstream fout("cal24.out");
struct Node
{
   double value;
   string ex;
   int op;
};
//a,b两个数进行+,-,*,/的运算 
double calc(double a,double b,int op)
{
    switch(op)
      {
          case 0: return (a+b);
          case 1: return (a-b);
          case 2: return (a*b);      
      } 
    if (b==0.0)
       return (1000.0);
    else
       return (a/b);
}
//判断两个数是否相等 ，符点数，取两个数之差的绝对值与0.001进行比较 
bool IsEqual(double a,double b)
{
    double c=a-b;
    if (c<0)
        c=-c;
    return (c<=0.001);
}
//表达式外层增加括号 
string AddBracket(string st,int op)
{
  if (op==0 || op==1)
    return "("+st+")";
  else
    return st;
}
//递归进行分堆处理 
void solve(int NumOfSet,double set[],int *pNumOfCal,Node *pCal)
{
    int i,j,k;   
    char ch[10];
    
    //A,B集合 
    int NumOfASet=0,NumOfBSet=0;
    double ASet[10],BSet[10];
    
    //A,B计算结果 
    int NumOfACal=0,NumOfBCal=0;
    Node ACal[2500],BCal[2500];
    
    string AEx="",BEx="";
    
    //如果集合中只有一个数，则直接返回 
    if (NumOfSet==1)
    {
       sprintf(ch,"%.0f",set[0]);    
       *pNumOfCal=1;
       (*pCal).value=set[0];
       (*pCal).ex=ch;
       (*pCal).op=2;       
       return ;
    } 
    *pNumOfCal=0;
    //划分集合为A,B ,i 为枚举划分方案，0：A，1：B 
    for (i=1; i<pow(2,NumOfSet-1); i++)
      {              
        k=i;  
        NumOfASet=0; NumOfBSet=0;        
        for (j=0; j<NumOfSet; j++)        
          {
              if (k%2==0)
                 ASet[NumOfASet++]=set[j];
              else
                 BSet[NumOfBSet++]=set[j];
              k=k>>1;             
          }    
          
        //打印集合A，B      
           /*
        int k1,k2;   
        fout<<"NumOfASet="<<NumOfASet<<endl;
        for (k1=0; k1<NumOfASet; k1++)
          fout<<ASet[k1]<<" ";
        fout<<endl;
        
        fout<<"NumOfBSet="<<NumOfBSet<<endl;
        for (k2=0; k2<NumOfBSet; k2++)
          fout<<BSet[k2]<<" ";
        fout<<endl;*/
        
        //分别递归计算A，B集合的所有可能表达式
        
        solve(NumOfASet,ASet,&NumOfACal,ACal);
        solve(NumOfBSet,BSet,&NumOfBCal,BCal);
        
        //枚举A与B进行计算的组合，如A?B，?为+,-,*,/，对于-,/考虑换位，A-B，B-A，A/B，B/A
              
        int iA,iB;
        //fout<<"NumOfACal="<<NumOfACal<<endl;
        //fout<<"NumOfBCal="<<NumOfBCal<<endl;       
         
        for (iA=0; iA<NumOfACal; iA++)
          for (iB=0; iB<NumOfBCal; iB++)            
            {      
                 //  A+B             
                (*(pCal+*pNumOfCal)).value=calc(ACal[iA].value,BCal[iB].value,0);
                (*(pCal+*pNumOfCal)).op=0;                                 
                                           
                AEx=ACal[iA].ex;
                BEx=BCal[iB].ex;
                  
                (*(pCal+*pNumOfCal)).ex=AEx+'+'+BEx;  
                //fout<<"+ : "<<(*(pCal+*pNumOfCal)).ex<<"="<<(*(pCal+*pNumOfCal)).value<<endl; 
                *pNumOfCal=*pNumOfCal+1;   
                
                //  A*B
                (*(pCal+*pNumOfCal)).value=calc(ACal[iA].value,BCal[iB].value,2);
                (*(pCal+*pNumOfCal)).op=2;
                 
                AEx=AddBracket(ACal[iA].ex,ACal[iA].op);
                BEx=AddBracket(BCal[iB].ex,BCal[iB].op);
                                        
                (*(pCal+*pNumOfCal)).ex=AEx+'*'+BEx;   
                //fout<<"* : "<<(*(pCal+*pNumOfCal)).ex<<"="<<(*(pCal+*pNumOfCal)).value<<endl; 
                *pNumOfCal=*pNumOfCal+1;                  
                     
                //  A-B 
                (*(pCal+*pNumOfCal)).value=calc(ACal[iA].value,BCal[iB].value,1);
                (*(pCal+*pNumOfCal)).op=1; 
                             
                AEx=ACal[iA].ex;
                BEx=AddBracket(BCal[iB].ex,BCal[iB].op);
                
                (*(pCal+*pNumOfCal)).ex=AEx+'-'+BEx;
                //fout<<"- : "<<(*(pCal+*pNumOfCal)).ex<<"="<<(*(pCal+*pNumOfCal)).value<<endl;    
                *pNumOfCal=*pNumOfCal+1;   
                
                // B-A
                (*(pCal+*pNumOfCal)).value=calc(BCal[iB].value,ACal[iA].value,1);
                (*(pCal+*pNumOfCal)).op=1;                
               
                AEx=AddBracket(ACal[iA].ex,ACal[iA].op);
                BEx=BCal[iB].ex;
                            
                (*(pCal+*pNumOfCal)).ex=BEx+'-'+AEx;
                //fout<<"- : "<<(*(pCal+*pNumOfCal)).ex<<"="<<(*(pCal+*pNumOfCal)).value<<endl;    
                *pNumOfCal=*pNumOfCal+1;              
                
                //  A/B
                (*(pCal+*pNumOfCal)).value=calc(ACal[iA].value,BCal[iB].value,3);
                (*(pCal+*pNumOfCal)).op=3; 
                AEx=AddBracket(ACal[iA].ex,ACal[iA].op);
                BEx=AddBracket(BCal[iB].ex,BCal[iB].op);           
                (*(pCal+*pNumOfCal)).ex=AEx+'/'+BEx;
                *pNumOfCal=*pNumOfCal+1;       
                
                //  B/A
                (*(pCal+*pNumOfCal)).value=calc(BCal[iB].value,ACal[iA].value,3);
                (*(pCal+*pNumOfCal)).op=3;                                          
                AEx=AddBracket(ACal[iA].ex,ACal[iA].op);
                BEx=AddBracket(BCal[iB].ex,BCal[iB].op);          
                (*(pCal+*pNumOfCal)).ex=BEx+'/'+AEx; 
                *pNumOfCal=*pNumOfCal+1;   
          
            }          
       }  
    
}

int main()
{    
     
    int i,j=0;
    //n个数等m 
    fin>>N>>M;
    
    //fout.setf(ios::fixed, ios::floatfield); // 设定为 fixed 模式
    //fout.precision(4); // 精度 2
    
    for (i=0; i<N; i++)
        fin>>v[i];   
 
    int NumOfCal=0;
    Node Cal[100000];
    
    solve(N,v,&NumOfCal,Cal);
    
    fout<<"NumOfCal="<<NumOfCal<<endl;
    for (i=0; i<NumOfCal; i++)
      if (IsEqual(Cal[i].value,M))
      {
        j++;
        fout<<"Cal i="<<i<<" :"<<Cal[i].ex<<"="<<Cal[i].value<<endl;
      }
    if (j==0)
      fout<<"无解"<<endl;
    else  
      fout<<"Total="<<j<<endl;
    fin.close(); 
    fout.close();     
    return 0;
}
