#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int read(){
	char ch=' ';
	int v=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){v=(v<<1)+(v<<3)+(ch^48);ch=getchar();}
	return v*x;
}
const int N=500010;
int n,m1,m2,ans; 
int t,T[N],T1[N],T2[N];
//map<int,int> T1,T2; 
struct Air{
	int st,ed;
	bool friend operator < (Air x,Air y){
		return x.st<y.st;
	}
}a1[N],a2[N];
void clear(){
	memset(T1,0,sizeof(T1));
	memset(T2,0,sizeof(T2));
	//T1.clear();
	//T2.clear();
}
int lowbit(int x){
	return x&(-x);
}
void modify1(int x){
	for(;x<=t;x+=lowbit(x))
		T1[x]++;
}
int query1(int x){
	int res=0;
	for(;x;x-=lowbit(x))
		res+=T1[x];
	return res;
}
int calc1(int x){
	int res=0;
	for(int i=1;i<=m1;i++){
		if(query1(t)-query1(a1[i].st)<x){
			res++;
			modify1(a1[i].ed);
		}
	}
	return res;
}
void modify2(int x){
	for(;x<=t;x+=lowbit(x))
		T2[x]++;
}
int query2(int x){
	int res=0;
	for(;x;x-=lowbit(x))
		res+=T2[x];
	return res;
}
int calc2(int x){
	int res=0;
	for(int i=1;i<=m2;i++)
		if(query2(t)-query2(a2[i].st)<x){
			res++;
			modify2(a2[i].ed);
		}
	return res;
}
int main(){
	//range
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		T[++t]=a1[i].st=read();
		T[++t]=a1[i].ed=read();
	}
	for(int i=1;i<=m2;i++){
		T[++t]=a2[i].st=read();
		T[++t]=a2[i].ed=read();
	}
	sort(T+1,T+t+1);
	for(int i=1;i<=m1;i++){
		a1[i].st=lower_bound(T+1,T+t+1,a1[i].st)-T;
		a1[i].ed=lower_bound(T+1,T+t+1,a1[i].ed)-T;
	}
	for(int i=1;i<=m2;i++){
		a2[i].st=lower_bound(T+1,T+t+1,a2[i].st)-T;
		a2[i].ed=lower_bound(T+1,T+t+1,a2[i].ed)-T;
	}
	sort(a1+1,a1+m1+1);
	sort(a2+1,a2+m2+1);
	for(int i=0;i<=n;i++){
		clear();
		//printf("%d\n",calc1(i)+calc2(n-i));
		ans=max(ans,calc1(i)+calc2(n-i));
	}
	printf("%d",ans);
	return 0;
}


