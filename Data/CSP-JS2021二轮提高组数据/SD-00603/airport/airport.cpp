#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
inline int read()
{
	int x(0);char c(0);bool flag(0);
	for(;!isdigit(c);c=getchar())if(c=='-')flag=1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return flag?-x:x;
}
struct Node
{
	int l,r;
	bool operator <(const Node &x)const
	{
		return l<x.l;
	}
};
//bool used[100005];
set<Node>beifen1,beifen2,opt1,opt2,histop1[100005],histop2[100005],emp;//histop[i]->after i times delete 
int hist1[100005],hist2[100005];
int flag1,flag2;
inline void calc1(int block1)
{
	if(flag1)
	{
		hist1[block1]=hist1[block1-1];
		histop1[block1]=histop1[block1-1];
		return;
	}
	int ans1;
	if(block1==0)
	{
		ans1=0;
		opt1=emp;
	}
	else
	{
		ans1=hist1[block1-1];
		opt1=histop1[block1-1];
		if(opt1.empty())
		{
			hist1[block1]=ans1;
			histop1[block1]=opt1;
			return;
		}
	}
	auto beg=opt1.begin();
	Node last;
//	cout<<"block1="<<block1<<endl;
//	for(Node i:opt1)
//	{
//		cout<<i.l<<' '<<i.r<<endl;
//	}
	for(set<Node>::iterator it=opt1.begin();it!=opt1.end();)
	{
		if(opt1.empty())break;
		if(it==beg)
		{
			ans1++;
			last=*it;
			it++;
			opt1.erase(last);
			continue;
		}
		if((it->l)>(last.r))
		{
			ans1++;
			last=*it;
			it++;
			opt1.erase(last);
			continue;
		}
		it++;
	}	
	histop1[block1]=(block1==0?beifen1:opt1);
	hist1[block1]=ans1;
	if(histop1[block1].empty()&&block1)flag1=1;
}
inline void calc2(int block2)
{
	if(flag2)
	{
		hist2[block2]=hist2[block2-1];
		histop2[block2]=histop2[block2-1];
		return;
	}
	int ans2;
	if(block2==0)
	{
		ans2=0;
		opt2=emp;
	}
	else
	{
		ans2=hist2[block2-1];
		opt2=histop2[block2-1];
	}
	auto beg=opt2.begin();
	Node last;
//		cout<<"block2="<<block2<<endl;
//	for(Node i:opt2)
//	{
//		cout<<i.l<<' '<<i.r<<endl;
//	}
	for(set<Node>::iterator it=opt2.begin();it!=opt2.end();)
	{
		if(opt2.empty())break;
		if(it==beg)
		{
			ans2++;
			last=*it;
			it++;
			opt2.erase(last);
			continue;
		}
		if((it->l)>(last.r))
		{
			ans2++;
			last=*it;
			it++;
			opt2.erase(last);
			continue;
		}
		it++;
	}
	histop2[block2]=(block2==0?beifen2:opt2);
	hist2[block2]=ans2;
	if(histop2[block2].empty()&&block2)flag2=1;
}
int ans=-1;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
//	scanf("%d%d%d",&n,&m1,&m2);
	n=read();m1=read();m2=read();
	Node t;
	for(int i=1;i<=m1;i++)
	{
//		scanf("%d%d",&node1[i].l,&node1[i].r);
		t.l=read();
		t.r=read();
		beifen1.insert(t);
	}
	for(int i=1;i<=m2;i++)
	{
//		scanf("%d%d",&node2[i].l,&node2[i].r);
		t.l=read();
		t.r=read();
		beifen2.insert(t);
	}
	for(int i=0;i<=n;i++)
	{
//		opt1=histop1[0];opt2=histop2[0];
//		memset(used,0,sizeof usd);
		calc1(i);
		calc2(i);
//		cout<<calc(i,n-i)<<endl;
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,hist1[i]+hist2[n-i]);
	}
//	for(int i=0;i<=n;i++)
//	{
//		cout<<hist1[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=0;i<=n;i++)
//	{
//		cout<<hist2[i]<<' ';
//	}
//	cout<<endl; 
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
