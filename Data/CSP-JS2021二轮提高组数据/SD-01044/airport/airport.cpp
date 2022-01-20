#include<iostream>
using namespace std;
int main()
{   
    int a,b,c,m,n,q,s1[9],t1[9],s2[9],t2[9],num=0,i1,i2;
    cout<<"请输入廊桥的个数："<<endl;
    cout<<"请输入国内航班，国际航班的数量：";
    cin>>a>>b>>c;
    for(m=0;m++;m<=n)
   n=a-m; 
    {
	for(q=1;q<10;q++)
    {if(q%2==1) 
    cin>>s1[9]>>t1[9];
    else cin>>s2[9]>>t2[9];
	}
	}
	for(i1=0;i1++;i1<10)
	{
		if(s1[i1]<t1[i1-1]) num++;
	}
	for(i2=0;i2++;i2<10)
	{
		if(s2[i1]<t2[i2-1]) num++;
	}
	cout<<num;
	return 0;
} 
