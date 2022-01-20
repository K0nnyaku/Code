#include<bits/stdc++.h>
#define MAXN 100500
#define re register
#define il inline
using namespace std;
template<typename tn> void read(tn &a)
{
	tn f=1,x=0;char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=f*x;
}
int a[MAXN],b[MAXN];
int n;
struct Treap
{
	struct Node
	{
		Node* ch[2];
		int v;
		int r;
		int cmp(int x) const
		{
			if(x==v) return -1;
			else return x<v ? 0 : 1;
		}
	}*root=NULL;
	
	void Insert(Node* &o,int x)
	{
		if(o==NULL)
		{
			o=new Node();
			o->v=x;
			o->r=rand();
			o->ch[0]=o->ch[1]=NULL;
		}
		else
		{
			int d=o->cmp(x);
			Insert(o->ch[d],x);
			if(o->ch[d]->r > o->r) Rotate(o,d^1);
		}
	}
	void Rotate(Node* &o,int d)
	{
		Node* k=o->ch[d^1];
		o->ch[d^1]=k->ch[d];
		k->ch[d]=o;
		o=k;
	}
	int Max(Node* o)
	{
		while(o->ch[1]!=NULL)
			o=o->ch[1];
		return o->v;
	}
}tree;
int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		read(n);
		for(re int i=1;i<=n;i++)
			read(a[i]),tree.Insert(tree.root,a[i]);
		cout<<tree.Max(tree.root);
		cout<<"-1";
	}
	//fclose(stdin);
	//fclose(stdout)
	return 0;
}

