#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
struct node{
	int x;
	int y;
};
map<int,int> ma;
map<int,int> mb;
bool cmp(node i,node j)
{
	return i.x<j.x;
}
node a[N];
node b[N];
int st1[N*2],st2[N*2],top1,top2;
int tag[N*4];
void push_down(int k)
{
	if(!tag[k]) return ;
	tag[k*2]+=tag[k];
	tag[k*2+1]+=tag[k];
	tag[k]=0;
	return ;
}
void add(int k,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	{
		tag[k]++;
		return ;
	}
	push_down(k);
	int mid=l+r>>1;
	if(x<=mid) add(k*2,l,mid,x,y);
	if(y>=mid+1) add(k*2+1,mid+1,r,x,y);
	return ;
}
int query(int k,int l,int r,int x)
{
	if(l==r&&l==x) return tag[k];
	int mid=l+r>>1;
	push_down(k);
	if(x<=mid) return query(k*2,l,mid,x);
	if(x>=mid+1) return query(k*2+1,mid+1,r,x);
	return 0;
}
int read()
{
	char ch=getchar();
	int res=0,fl=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') fl=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*fl;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=read();
	int m1=read(),m2=read();
	for(int i=1;i<=m1;++i) 
	{
		a[i].x=read();
		a[i].y=read();
	}
	for(int i=1;i<=m2;++i) 
	{
		b[i].x=read();
		b[i].y=read();
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m1,cmp);
	for(int i=1;i<=m1;++i)
	{
		st1[++top1]=a[i].x;
		st1[++top1]=a[i].y;
	}
	for(int i=1;i<=m2;++i)
	{
		st2[++top2]=b[i].x;
		st2[++top2]=b[i].y;
	}
	sort(st1+1,st1+1+top1);
	sort(st2+1,st2+1+top2);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=top1;++i)
	{
		if(!ma[st1[i]]) ma[st1[i]]=++cnt1;
	}
	for(int i=1;i<=top2;++i)
	{
		if(!mb[st2[i]]) mb[st2[i]]=++cnt2;
	}
	for(int i=1;i<=m1;++i) 
	{
		a[i].x=ma[a[i].x];
		a[i].y=ma[a[i].y];
	}
	for(int i=1;i<=m2;++i) 
	{
		b[i].x=mb[b[i].x];
		b[i].y=mb[b[i].y];
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int res1=0;
		memset(tag,0,sizeof(tag));
		for(int j=1;j<=m1;++j)
		{
			if(query(1,1,cnt1,a[j].x)<i)
			{
				res1++;
				add(1,1,cnt1,a[j].x,a[j].y-1);
			}
		}
		int res2=0;
		memset(tag,0,sizeof(tag));
		for(int j=1;j<=m2;++j)
		{
			if(query(1,1,cnt2,b[j].x)<n-i)
			{
				res2++;
				add(1,1,cnt2,b[j].x,b[j].y-1);
			}
		}
	 	ans=max(ans,res1+res2);
//	 	printf("**%d",res1+res2);
	} 
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
