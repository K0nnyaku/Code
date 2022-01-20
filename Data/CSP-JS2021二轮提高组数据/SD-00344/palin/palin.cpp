#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<queue>
#define maxn 1000000
inline int read()
{
	int f=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
using namespace std;
int n;
int a[maxn],b[maxn],ji=0,flag;
char ans[maxn],aaa[maxn];
int pd()
{
	for(int i=0;i<=n-1;i++)
	{
		if(b[i]!=b[2*n-i-1])
		{
			return false;
		}
		//cout<<"!!";
	}
	return true;
}
void dfs(int x,int y)
{
	//cout<<"!!";
	if(flag==1)
	return ;
	if(ji==2*n)
	{
		if(pd()==true&&flag==0)
		{
			if(aaa>ans)
			{
				for(int i=0;i<=2*n-1;i++)
				{
					cout<<ans[i];
				}
				cout<<endl;
				flag=1;
			}
		}
		return ;
	}
		//cout<<ji;
		ans[ji]='L';
		b[ji]=a[x];
		ji++;
		dfs(x+1,y);
        ji--;
    	ans[ji]='R';
    	b[ji]=a[y];
    	ji++;
		dfs(x,y-1);
		ji--;
}
int main()
{
	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int k;
	cin>>k;
	while(k--)
	{
		
		memset(a,0,sizeof(a));
		n=read();
		for(int i=0;i<=2*n-1;i++)
		{
			aaa[i]='Z';
		}
		for(int i=0;i<=2*n-1;i++)
		{
			a[i]=read();
			//cout<<"!!";
		}
		int tail=2*n-1,fr=0,num=0;
		flag=0;
		dfs(fr,tail);
		/*if(flag==1)
		{
			for(int i=0;i<=2*n+1;i++)
			{
				cout<<aaa[i]<<" ";
			}
			cout<<endl;
		}*/
		if(flag==0) cout<<-1<<endl;
	}
	return 0;
}
