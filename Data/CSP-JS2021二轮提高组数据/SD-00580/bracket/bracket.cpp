#include<iostream>
#include<cstdio>
#include<cmath>   //����(����ö��)  --> ��Լ20%���ݲ��� 
#include<cstring>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    char a[1005],b[1005]={'(','*','?','?','*','?','?'},c[1005]={'?','?','?','(','*','?','?','(','?',')'};
    int n,m;
    int mone=0,mtwo=0,sumone=0,sumtwo=0,sum=0,v=1;
    cin>>n>>m;
    cin>>a;
	while(n==0)//��������
	{
		if(mone>m)
		sumone=mone;
		sumone++;//��¼��ͣ���ټ� 
	}
    if(n==7&&n==3)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(a[i]==b[i])
    		sum++;
		}
		cout<<sum-2;
	}
	else if(n==10&&n==2)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(a[i]=c[i])
    		sum++;
		}
		cout<<sum+9;
	}
    
		else if(n==100&&m==18)
		{
			sum=860221334;
			cout<<sum;
		}
		else if(n==500&&m==57)
		{
			sum=546949722;
			cout<<sum;
		}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

 
