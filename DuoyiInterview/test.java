public class test{
    public static void main(String[] args) throws Exception{

        if (args.length<1){
            System.out.println("Parameter is not enough");
            return;
        }
        System.out.println("len="+args.length);
        int num=Integer.valueOf(args[0]).intValue();
        switch(num)
        {
            case 1:
            {
                test1 t1=new test1("345");
                System.out.println(t1.getValue());
            }
            break;

            case 2:
            {
                test2 t2=new test2("abcd123456789ed125ss1234567");
                System.out.println(t2.getLongStrOfNumbers());
            }
            break;

            case 3:{
                int arr[]={0,5,5,3,5,7,5,5};
                test3 t3=new test3(arr);
                System.out.println(t3.getCoreValue());
            }
            break;
            default:
                break;
        }
        
    }
}

class test1{
    private String m_value;

    public test1(String s)
    {
        this.m_value=s;
    }

    public int getValue()
    {
        return Integer.valueOf(this.m_value).intValue();
    }
}

class test2{
    private String m_value;

    public test2(String s)
    {
        this.m_value=s;
    }

    public String getLongStrOfNumbers()
    {
        int len=m_value.length();
        int head=-1;
        int max=0,l_key=0;
        for (int i=0; i<len; i++)
        {
            if (!(m_value.charAt(i)>='0' && m_value.charAt(i)<='9'))
            {
                if (i-head-1>max)
                {
                    max=i-head-1;
                    l_key=head+1;
                }
                head=i; 
            }
        }
        System.out.println("l="+l_key+"max="+max);
        return m_value.substring(l_key,l_key+max);
    }
}

class test3{
    private int[] m_value;
    public test3(int arr[])
    {
        this.m_value=arr;
    }

    public int getCoreValue()
    {
        int value=m_value[0],count=1;
        for (int i=1; i<m_value.length; i++)
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
            System.out.println("i="+i+" value="+value+"count="+count);

        }
        System.out.println("count="+count);
        if (count>1)
        {
            return value;
        }else{
            return -1;
        }
    }
}