#!/usr/bin/env python
#coding=utf8

import sys

class Test1():
    def __init__(self,s):
        self.value=s

    def getValue(self):
        return int(self.value)

class Test2():
    def __init__(self,s):
        self.value=s
    def getLongStrOfNumbers(self):
        l=len(self.value)
        head=-1
        max_len=0
        l_key=0

        for i in range(0,l):
        
            if not (cmp(self.value[i],"0")>=0 and cmp(self.value[i],"9")<=0):
            
                if (i-head-1>max_len):
                
                    max_len=i-head-1
                    l_key=head+1
                
                head=i; 
              
        print "l=%d max_len=%d"%(l_key,max_len)
        return self.value[l_key:l_key+max_len]

class Test3():
    def __init__(self,s):
        self.value=s;

    def getCoreValue(self):

        value=self.value[0]
        count=1
   
        for i in range(1,len(self.value)):
       
            if self.value[i]==value:
                count+=1
            else:
                count-=1
                if count==0:
                    value=self.value[i]
                    count=1       
            
            print "i=%d value=%d count=%d"%(i,value,count)
        
        print "count%d"%(count)
       
        if count>1:
            return value
        else:
            return -1
        

if __name__ == '__main__':
    print "试题%s的结果如下：" %sys.argv[1]
    if len(sys.argv) < 2:
        print "Parameter is not enough"
        sys.exit(0)
    if sys.argv[1]=="1":
        t1=Test1("345")
        print t1.getValue()


    if sys.argv[1]=="2":
        t2=Test2("abcd123456789ed125ss1234567")
        print t2.getLongStrOfNumbers()

    if sys.argv[1]=="3":

        arr=[0,5,5,3,5,7,5,5]
        arr1=[0,5,5,3,5,1,5,7]
        t3=Test3(arr1)

        print t3.getCoreValue()



    print(sys.argv)