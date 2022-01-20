#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int T,n,qwq=1919810;
int a[114514],b[114514];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--)
	{
		qwq=1919810;
		memset(b,0,sizeof(b));
		for(int i=0;i<=n;i++) a[i]=0;
		cin>>n;
		for(int i=1;i<=n*2;i++) cin>>a[i];
		for(int s=0;s<1<<(n*2);s++)
		{
			int ans[50],cnt=0;
			while(s)
			{
				ans[cnt]=s%2;
				s/=2;
				cnt++;
			}
			int tmp=1,l=1,r=2*n;
			for(int i=2*n-1;i>=0;i--)
			{
				if(ans[i]==0)
				{
					b[tmp]=a[l];
					l++;
				}
				if(ans[i]==1) 
				{
					b[tmp]=a[r];
					r--;
				}
			}
			bool flag=0;
			for(int i=1,j=2*n;i<=n;i++,j--)
			{
				if(b[i]!=b[j]) 
				{
					flag=1;
					break;
				}
			}
			if(!flag) qwq=min(qwq,s);
		}
		if(qwq==1919810) cout<<-1<<endl;
		else
		{
			int ans[50],cnt=0;
			while(qwq)
			{
				ans[cnt]=qwq%2;
				qwq/=2;
				cnt++;
			}
			for(int i=2*n-1;i>=0;i--)
			{
				if(ans[i]==0)
					cout<<"L";
				if(ans[i]==1) 
					cout<<"R";
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
