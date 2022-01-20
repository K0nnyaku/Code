#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=1e5+10;
int n,m1,m2,ans,b1[N],b2[N],c1[N],c2[N],s1[N],s2[N];
struct point{
	int l,r;
}a[N],b[N];
int cmp(point x,point y){
	return x.l<y.l;
}
int solve(int x){
	int y=n-x;
	priority_queue<int> q;
	int sum=0,res=0;
	for(int i=1;i<=m1;i++){
		while(!q.empty()){
			int p=-q.top();
			if(p>a[i].l)
				break;
			q.pop();
			sum--;
		}
		if(sum<x){
			q.push(-a[i].r);
			sum++;
			res++;
		}
	}
	while(!q.empty())
		q.pop();
	sum=0;
	for(int i=1;i<=m2;i++){
		while(!q.empty()){
			int p=-q.top();
			if(p>b[i].l)
				break;
			q.pop();
			sum--;
		}
		if(sum<y){
			q.push(-b[i].r);
			sum++;
			res++;
		}
	}
	return res;
} 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
		a[i].l=read(),a[i].r=read();
	for(int i=1;i<=m2;i++)
		b[i].l=read(),b[i].r=read();
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;i++)
		ans=max(ans,solve(i));
	printf("%d",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

