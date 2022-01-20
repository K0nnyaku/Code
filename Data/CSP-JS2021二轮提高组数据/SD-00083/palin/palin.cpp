#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int read()
{
	int res=0,f=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) res*=10,res+=c-'0',c=getchar();
	return res*f;
}
int T,n,a[N],ans[N];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=2*n;i++) a[i]=read();
		int L,R,l,r;
		for(int i=2;i<=2*n;i++)
			if(a[i]==a[1]) l=r=i;
		L=2,R=2*n;ans[1]=1;ans[2*n]=1;
		int flag=0;
		for(int i=2;i<=n;i++)
		{
			//cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
			if(l>L+1&&a[l-1]==a[L]) ans[i]=1,l--,L++,ans[2*n-i+1]=1;
			else if(r<R&&a[r+1]==a[L]) ans[i]=1,r++,L++,ans[2*n-i+1]=2;
			else if(l>L&&a[l-1]==a[R]) ans[i]=2,l--,R--,ans[2*n-i+1]=1;
			else if(r<R-1&&a[r+1]==a[R]) ans[i]=2,r++,R--,ans[2*n-i+1]=2;
			else {flag=1;break;}
		}
		if(!flag)
		{
			for(int i=1;i<=2*n;i++)
			{
				if(ans[i]==1) putchar('L');
				else putchar('R'); 
			}
			cout<<endl;
		}
		else
		{
			for(int i=1;i<2*n;i++)
				if(a[i]==a[2*n]) l=r=i;
			L=1,R=2*n-1;
			ans[1]=2;ans[2*n]=1; 
			flag=0;
			for(int i=2;i<=n;i++)
			{
				//cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
				if(l>L+1&&a[l-1]==a[L]) ans[i]=1,l--,L++,ans[2*n-i+1]=1;
				else if(r<R&&a[r+1]==a[L]) ans[i]=1,r++,L++,ans[2*n-i+1]=2;
				else if(l>L&&a[l-1]==a[R]) ans[i]=2,l--,R--,ans[2*n-i+1]=1;
				else if(r<R-1&&a[r+1]==a[R]) ans[i]=2,r++,R--,ans[2*n-i+1]=2;
				else {flag=1;break;}
			}
			if(flag) puts("-1");
			else
			{
				for(int i=1;i<=2*n;i++)
				{
					if(ans[i]==1) putchar('L');
					else putchar('R'); 
				}
				cout<<endl;
			}
		}
	}
}
