#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#define ri register int

using std::min;
using std::max;
 
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

int write(int x){
	if(x>9)write(x/10);
	putchar(x%10^48);
}

const int N=1e5+5;
int ans1[N],ans2[N],n,m1,m2;
int tree[N*30],id[N*30];
struct node{
	int l,r;
}a[N],b[N];

void Push_Up(int x){
	tree[x]=max(tree[x<<1],tree[x<<1|1]);
	if(tree[x<<1])id[x]=id[x<<1];
	else if(tree[x<<1|1])id[x]=id[x<<1|1];
	else id[x]=0;
}

void Add(int x,int l,int r,int p,int k){
	if(l>p||r<p)return;
	if(l==r){
    tree[x]+=k;
    if(tree[x]==1)id[x]=l;
    else id[x]=0;
    return;
	}
	int mid=l+r>>1;
	Add(x<<1,l,mid,p,k),Add(x<<1|1,mid+1,r,p,k);
	Push_Up(x);
} 

int Query(int x,int l,int r,int p){
	if(l==r)return id[x];
	int mid=l+r>>1,tmp=1,pos=0;
	if(p<=mid)tmp=1,pos=Query(x<<1,l,mid,p);
	else tmp=2,pos=Query(x<<1|1,mid+1,r,p);
	if(pos)return pos;
	if(tmp&1){
		if(tree[x<<1|1])return id[x<<1|1];
		else return 0; 
	}
	else return 0;
}

bool cmp(node x,node y){
	return x.l<y.l;
}

int ls[N*4],cnt=0;

int Find(int x){
	int l=1,r=cnt,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(ls[mid]==x)return mid;
		else if(ls[mid]>x)r=mid-1;
		else l=mid+1; 
	}
	return ans;
}

int res=0,dep,mp[N*10];

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	n=read(),m1=read(),m2=read();
	for(ri i=1;i<=m1;i++)a[i].l=read(),a[i].r=read(),ls[++cnt]=a[i].l,ls[++cnt]=a[i].r;
	for(ri i=1;i<=m2;i++)b[i].l=read(),b[i].r=read(),ls[++cnt]=b[i].l,ls[++cnt]=b[i].r;
	std::sort(a+1,a+m1+1,cmp),std::sort(b+1,b+m2+1,cmp),std::sort(ls+1,ls+cnt+1);
	for(ri i=1;i<=m1;i++)a[i].l=Find(a[i].l),a[i].r=Find(a[i].r);
	for(ri i=1;i<=m2;i++)b[i].l=Find(b[i].l),b[i].r=Find(b[i].r);
	for(ri i=1;i<=m1;i++)Add(1,1,cnt,a[i].l,1),mp[a[i].l]=a[i].r;
	res=0,dep=1;
	while(true){
		int las=1;
		while(true){
			int p=Query(1,1,cnt,las);
			if(!p)break;
			res++,las=mp[p]+1,ans1[dep]++;
			Add(1,1,cnt,p,-1);
		}
		if(res==m1)break;
		dep++;
	}
	for(ri i=1;i<=m2;i++)Add(1,1,cnt,b[i].l,1),mp[b[i].l]=b[i].r;
	res=0,dep=1;
	while(true){
		int las=1;
		while(true){
			int p=Query(1,1,cnt,las);
			if(!p)break;
			res++,las=mp[p]+1,ans2[dep]++;
			Add(1,1,cnt,p,-1);
		}
		if(res==m2)break;
		dep++;
	}
	for(ri i=1;i<=n;i++)ans1[i]+=ans1[i-1],ans2[i]+=ans2[i-1];
	int mx=0;
	for(ri i=0;i<=n;i++)mx=max(mx,ans1[i]+ans2[n-i]);
	printf("%d\n",mx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



