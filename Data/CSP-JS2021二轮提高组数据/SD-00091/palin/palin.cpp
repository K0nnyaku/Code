#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
typedef long long ll;
template<typename T> void Read(T &x)
{
	x=0;bool f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=f==1?x:-x;
}
template<typename T> void Put(T x)
{
	if(x<10)
	{
		putchar(x+'0');
		return;
	}
	Put(x/10);putchar(x%10+'0');
}
struct node
{
	int val,wz;
};
int t,n,a[1001],pos[501][2],bj[501],ans[1001],tmp[1001],tmpp[1001],pd=0,res=0,be,end;
stack<node> lle,rri;
void dfs(int now,int last1,int last2)
{
	if(now==n+1)
	{
		int le=1,ri=2*n,ii=1;
		while(le<=ri)
		{
			if(tmp[le]==ii) tmpp[ii]=1,le++;
			else tmpp[ii]=2,ri--;
			ii++;
		}
		if(!pd)
		{
			for(int i=1;i<=2*n;i++) ans[i]=tmpp[i];
			pd=1;
			return;
		}
		else
			for(int i=1;i<=2*n;i++)
				if(tmpp[i]<ans[i])
				{
					for(int j=1;j<=2*n;j++) ans[j]=tmpp[j];
					return;
				}
				else if(tmpp[i]>ans[i]) return;
	}
	node p1,p2;int wz1=-1,wz2=-1;
	if(!lle.empty())p1=lle.top();
	if(!rri.empty())p2=rri.top();
	if(!lle.empty())wz1=pos[p1.val][0]+pos[p1.val][1]-p1.wz;
	if(!rri.empty())wz2=pos[p2.val][0]+pos[p2.val][1]-p2.wz;
	if(!last1&&!last2)
	{
		if(!lle.empty())
		{
			tmp[p1.wz]=now;tmp[wz1]=2*n-now+1;
		lle.pop();
		int a1=wz1-1,a2=wz1+1;
		if(a1<be) a1=0;
		if(a2>end) a2=0;
		dfs(now+1,a1,a2);
		lle.push(p1);tmp[p1.wz]=0;tmp[wz1]=0;
		}
		if(!rri.empty())
		{
			tmp[p2.wz]=now;tmp[wz2]=2*n-now+1;
		rri.pop();
		int a1=wz2-1,a2=wz2+1;
		if(a1<be) a1=0;
		if(a2>end) a2=0;
		dfs(now+1,a1,a2);
		}
	}
	else
	{
		if(wz1==last1)
		{
			tmp[p1.wz]=now;tmp[wz1]=2*n-now+1;
			lle.pop();
			int nxt=last1-1;
			if(nxt<be) nxt=0;
			dfs(now+1,nxt,last2);
			lle.push(p1);
		}
		if(wz2==last1)
		{
			tmp[p2.wz]=now;tmp[wz2]=2*n-now+1;
			rri.pop();
			int nxt=last1-1;
			if(nxt<be) nxt=0;
			dfs(now+1,nxt,last2);
			rri.push(p2);
		}
		if(wz1==last2)
		{
			tmp[p1.wz]=now;tmp[wz1]=2*n-now+1;
			lle.pop();
			int nxt=last2+1;
			if(nxt>end) nxt=0;
			dfs(now+1,last1,nxt);
			lle.push(p1);
		}
		if(wz2==last2)
		{
			tmp[p2.wz]=now;tmp[wz2]=2*n-now+1;
			rri.pop();
			int nxt=last2+1;
			if(nxt>end) nxt=0;
			dfs(now+1,last1,nxt);
			rri.push(p2);
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	Read(t);
	while(t--)
	{
		Read(n);
		memset(pos,0,sizeof(pos));
		memset(ans,0,sizeof(ans));
		memset(tmp,0,sizeof(tmp));
		memset(tmpp,0,sizeof(tmpp));
		res=pd=0;
		for(int i=1;i<=2*n;i++)
		{
			Read(a[i]);
			if(!pos[a[i]][0]) pos[a[i]][0]=i;
			else pos[a[i]][1]=i;
		}
		for(int i=n+1;i>=1;i--)
		{
			be=i,end=i+n-1;int pdd=0;
			memset(bj,0,sizeof(bj));
			for(int j=be;j<=end;j++)
				if(bj[a[j]])
				{
					pdd=1;
					break;
				}
				else bj[a[j]]=1;
			if(pdd) continue;
			else
			{
				while(!lle.empty()) lle.pop();
				while(!rri.empty()) rri.pop();
				for(int j=i-1;j>=1;j--) lle.push({a[j],j});
				for(int j=i+n;j<=2*n;j++) rri.push({a[j],j});
				dfs(1,0,0);
				if(pd) res=1;
			}
		}
		if(res)
		{
			for(int i=1;i<=2*n;i++)
				if(ans[i]==1) printf("L");
				else printf("R");
		}
		else printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
