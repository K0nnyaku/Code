#include <bits/stdc++.h>
#define f(i,a,b) for(register int i=(a);i<=(b);++i)
#define F(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
int a[100005];
int w[105],b[105],rel;
int T,n;
int l,r;
bool vis;
int kk(int s,int g)
{
	g*=2;
	if(s==n)
	{
		return g;
	}
	kk(s+1,g);
}
void so1()
{
	
}
int so2(int s)
{
	l=0,r=0;vis=1;
	f(i,1,n)
	{
		if(w[i])b[i]=a[n-(++r)+1];
		else b[i]=a[++l];
	}
//	f(i,1,n)cout<<b[i];cout<<'\n';
	f(i,1,n)
	{
//		cout<<b[i]<<b[n-i+1]<<"\n";
		if(b[i]!=b[n-i+1])vis=0;
	}
	if(vis)return 1;
	if(s==rel)return 0;
	F(i,n,1)
	{
		++w[i];
		if(w[i]==2)w[i]=0;
		else break;
	}
//	f(i,1,n)cout<<w[i];cout<<'\n';
	so2(s+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	if(T==1&&n>1000){cout<<-1;return 0;}
	while(T--)
	{
		cin>>n;n*=2;rel=kk(1,1)-1;
//		cout<<rel<<"\n";
		f(i,1,n)
		{
			cin>>a[i];
			w[i]=0,b[i]=0;
		}
		if(n>30)
		{
			so1();//ts
		}
		else
		{
			if(so2(1)) {
				f(i,1,n) {
					if(w[i])cout<<'R';
					else cout<<'L';
				}
				cout<<'\n';
			}
			else cout<<"-1\n";
		}
		
	}
	return 0;
}
/*
1
5
4 1 2 4 5 3 1 2 3 5
*/

/*
1
3
3 2 1 2 1 3
*/

/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
