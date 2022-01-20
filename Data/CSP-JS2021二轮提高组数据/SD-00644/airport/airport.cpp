#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct T{
	int ti,op,id;
};
bool cmp(T x,T y){return x.ti<y.ti;}
int n;
struct Air{
	int m;
	int a[maxn],b[maxn],s[maxn],ids[maxn];
	T p[maxn];
	int cnt;
	int sum[maxn];
	void solve(){
		sort(p+1,p+1+cnt,cmp);
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=1;i<=n;i++)q.push(i);
		for(int i=1;i<=cnt;i++){
			if(p[i].op>0){
				if(q.empty())continue;
				int x=q.top();q.pop();
				sum[x]++;
				ids[s[p[i].ti]]=x;
			}
			else{
				if(ids[p[i].ti])
				q.push(ids[p[i].ti]);
			}
		}
		for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
	}
}A1,A2;
inline int read(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*w;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();A1.m=read();A2.m=read();
	for(int i=1;i<=A1.m;i++)A1.a[i]=read(),A1.b[i]=read();
	for(int i=1;i<=A2.m;i++)A2.a[i]=read(),A2.b[i]=read();
	for(int i=1;i<=A1.m;i++){
		A1.s[A1.a[i]]=A1.b[i];
		A1.p[++A1.cnt]=(T){A1.a[i],1};
		A1.p[++A1.cnt]=(T){A1.b[i],-1};
	}
	for(int i=1;i<=A2.m;i++){
		A2.s[A2.a[i]]=A2.b[i];
		A2.p[++A2.cnt]=(T){A2.a[i],1};
		A2.p[++A2.cnt]=(T){A2.b[i],-1};
	}
	A1.solve();A2.solve();
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,A1.sum[i]+A2.sum[n-i]);
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}

