#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<cstring>
#include<map>
#include<cmath>
#include<ctime>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*f;
}
const int N=2e5+5,inf=2e8;
int n,m1,m2,ans;
struct Node{
	int pos,op,id;
}a[N],b[N];
bool vis[N];
bool cmp(Node A,Node B){
	return A.pos<B.pos;
}
int calc1(int lim){
	for(int i=1;i<=m1;i++) vis[i]=0;
	int summ=0,now=0;
	for(int i=1;i<=m1;i++){
		if(a[i].op==-1){
			if(vis[a[i].id]) now--;
		}
		else{
			if(now<lim){
				now++;
				summ++;
				vis[a[i].id]=1;
			}
		}
	}
	return summ;
}
int calc2(int lim){
	for(int i=1;i<=m2;i++) vis[i]=0;
	int summ=0,now=0;
	for(int i=1;i<=m2;i++){
		if(b[i].op==-1){
			if(vis[b[i].id]) now--;
		}
		else{
			if(now<lim){
				now++;
				summ++;
				vis[b[i].id]=1;
			}
		}
	}
	return summ;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	srand(time(0));
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i*2-1].pos,&a[i*2].pos);
		a[i*2-1].id=a[i*2].id=i;
		a[i*2-1].op=1;
		a[i*2].op=-1;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i*2-1].pos,&b[i*2].pos);
		b[i*2-1].id=b[i*2].id=i;
		b[i*2-1].op=1;
		b[i*2].op=-1;
	}
	
	m1*=2;m2*=2;
	
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	
	if(n*m1<=inf){
		for(int i=0;i<=n;i++){
			ans=max(ans,calc1(i)+calc2(n-i));
		}
	}
	else{
		int l=0,r=n;
		while(l<=r){
			int l1=l+(r-l)/3,r1=r-(r-l)/3;
			int val1=calc1(l1)+calc2(n-l1);
			int val2=calc1(r1)+calc2(n-r1);
			ans=max(ans,max(val1,val2)); 
			if(val1>val2) r=r1-1;
			else l=l1+1;
		}
		
		for(int i=1;i<=500;i++){
			int a=rand()%n+1;
			ans=max(ans,calc1(a)+calc2(n-a));
		}

	}
	
	printf("%d\n",ans);
	
	return 0;
}

