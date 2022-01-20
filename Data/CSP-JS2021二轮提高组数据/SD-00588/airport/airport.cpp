#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m1,m2,ans;
int s[N],t1[N],t2[N];
struct qq{
	int a,b;
}q[N],d1[N],d2[N];
int redd(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
bool cmp(qq x,qq y){
	return x.a<y.a;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=redd();m1=redd();m2=redd();
	for(int i=1;i<=m1;i++)
		d1[i].a=redd(),d1[i].b=redd();
	for(int i=1;i<=m2;i++)
		d2[i].a=redd(),d2[i].b=redd();
	sort(d1+1,d1+m1+1,cmp);
	sort(d2+1,d2+m2+1,cmp);
	for(int i=1;i<=n;i++){
		int h=0,l=0,t=1;
		for(int j=1;j<=m1;j++)
			if(d1[j].a>q[h].b)
				q[h].a=q[h].b=0,h++,q[++l].a=d1[j].a,q[l].b=d1[j].b,t1[i]++;
			else
				if(t<i)
					t++,q[++l].a=d1[j].a,q[l].b=d1[j].b,t1[i]++;
		h=0,l=0,t=1;
		for(int j=1;j<=m2;j++)
			if(d2[j].a>q[h].b)
				q[h].a=q[h].b=0,h++,q[++l].a=d2[j].a,q[l].b=d2[j].b,t2[i]++;
			else
				if(t<i)
					t++,q[++l].a=d2[j].a,q[l].b=d2[j].b,t2[i]++;
	}
	for(int i=0;i<=n;i++)
		ans=max(ans,t1[i]+t2[n-i]);
	printf("%d",ans);
	return 0;
}
