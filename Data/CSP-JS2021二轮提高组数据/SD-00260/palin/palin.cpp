#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm> 
using namespace std;
#define ll long long
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch-48);
		ch=getchar(); 
	}
	return x*f;
}
int a[700001],c[700001];
bool b[700001];
int main()
{
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	int T,n,p,l1,l2,r1,r2;
	char s[700001];
	bool an,lol;
	T=read();
	while(T--)
	{
		memset(s,' ',sizeof(s));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		p=0;an=0;l2=2*n+1;l1=0;r1;r2;
		lol=0;
		n=read();
		for(int i=1;i<=2*n;i++)
		{
			a[i]=read();
			if(!b[a[i]]&&an==0)
			{
				p++;
				b[a[i]]=1;
				l1=i;
			}
			else
			an=1;
		}
	//	for(int i=1;i<=n;i++)
	//	cout<<b[i]<<' ';
		for(int i=2*n;i>=1;i--)
		{
			if(!b[a[i]])
			{
				p++;
				b[a[i]]=1;
				l2=i;
			}
			else
			break;
		}
	//	cout<<endl;
	//	for(int i=1;i<=n;i++)
	//	cout<<b[i]<<' ';
		r1=l1+1;r2=l2-1;
		if(p!=n)
		{
			cout<<-1<<"\n";
			continue;
		}
		int l1q=l1,l2q=l2,r1q=r1,r2q=r2,lr=n,len=1;
		//cout<<l1<<' '<<l2<<' '<<p<<' '<<r1<<' '<<r2<<"\n";
		while(r1<=r2)
		{
			if(a[l2]==a[r1])
			{
				s[lr--]='R';
				c[len++]=a[l2];
				l2++;r1++;
			}
			else if(a[l2]==a[r2])
			{
				s[lr--]='R';
				c[len++]=a[l2];
				l2++;r2--;
			}
			else if(a[l1]==a[r1])
			{
				s[lr--]='L';
				c[len++]=a[l1];
				l1--;r1++;
			}
			else if(a[l1]==a[r2])
			{
				s[lr--]='L';
				c[len++]=a[l1];
				l1--;r2--;
			}
			else
			{
				lol=1;
				break;
			}
		}
		if(lol)
		{
			cout<<-1<<"\n";
			continue;
		}
		l1=l1q,l2=l2q,r1=r1q,r2=r2q,lr=n+1;
		int llen=1;
		len-=1;
	//	for(int i=1;i<=len;i++)
	//	cout<<c[i]<<' ';
	//	cout<<endl;
		while(llen<=len)
		{
		//	cout<<a[r1]<<' '<<a[r2]<<' '<<c[llen]<<endl;
			if(c[llen]==a[r1])
			{
				s[lr++]='L';r1++;
			}
			else if(c[llen]==a[r2])
			{
				s[lr++]='R';r2--;
			}
			else
			{
				lol=1;
				break;
			}
			llen++;
		}
		for(int i=1;i<=2*n;i++)
		cout<<s[i];
		cout<<"\n"; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3*/
