#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <map> 
using namespace std;
const int N=1e6+5,inf=1e9;
#define ll long long
#define db double
#define gc getchar()
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define dep(x,y,z) for(int x=y;x>=z;x++)
int n,num[N],lk[N],ans,a[N],lg[N],st1[N],st2[N]; 
inline int in()
{
	int f=0,g=1;char c=gc;
	while(!isdigit(c)) 
		g=g*(c=='-'?-1:1),c=gc;
	while(isdigit(c))
		f=f*10+c-'0',c=gc;
	return f*g;
} 
void check(int sum)
{
	int hd=0,tl=2*n+1,tp1=0,tp2=2*n+1,fl=0;
	rep(i,1,2*n)
	{
		if(sum/lg[2*n-i]%2==0)
			st1[++tp1]=num[++hd],st2[--tp2]=num[hd];
		else 
			st1[++tp1]=num[--tl],st2[--tp2]=num[tl];
	}
	rep(i,1,2*n) if(st1[i]!=st2[i]) fl=1;
	if(!fl) 
	{
	//	cout<<endl<<sum<<endl;
	//	rep(i,1,2*n) cout<<st1[i]<<" "<<st2[i]<<"  ";
		ans=min(ans,sum);
	}
}
void dfs(int u,int sum)
{
	if(u>2*n) 
	{check(sum);return;}
	dfs(u+1,sum*2+0);
	dfs(u+1,sum*2+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	lg[0]=1;rep(i,1,21) lg[i]=lg[i-1]*2;
	int T;cin>>T;while(T--)
	{
		n=in();rep(i,1,2*n)
			num[i]=in();
		ans=inf;
		dfs(1,0);
		if(ans!=inf) 
		{
		
		rep(i,1,2*n)
		{
			if(ans/lg[2*n-i]%2==0) cout<<"L";
			else cout<<"R";
		}cout<<endl;}
		else cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
