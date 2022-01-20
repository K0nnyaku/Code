#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int M=1e5+50;
struct node {
	int a,b;
}p[M],t[M];
int n,m1,m2,q[M],mxx;
int x[M],y[M];
int last[M],l1[M],ed[M],ad[M];
int last1[M],l2[M]; 
int cmp(node A,node B) {
	return A.a<B.a;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&p[i].a,&p[i].b);
	}
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&t[i].a,&t[i].b);
	sort(p+1,p+m1+1,cmp);
	sort(t+1,t+m2+1,cmp);
	int tot=0,ans=m1;//tot¸öÍ£»ú 
	int mm1=m1,mm2=m2;
	while(ans!=0) {
		m1=ans;
		ans=0;tot++;
		if(tot%2==1) {
			last[tot]=p[1].b,l1[tot]=1;
			for(int i=2;i<=m1;i++) {
				if(p[i].a>last[tot])last[tot]=p[i].b,l1[tot]++;
				else ed[++ans]=p[i].a,ad[ans]=p[i].b;
			}
		}
		else {
			last[tot]=ad[1],l1[tot]=1;
			for(int i=2;i<=m1;i++) {
				if(ed[i]>last[tot])last[tot]=ad[i],l1[tot]++;
				else p[++ans].a=ed[i],p[ans].b=ad[i];
			}
		}
	}
	
	ans=m2;int tmp=0;
	while(ans!=0) {
		m2=ans;
		ans=0;tmp++;
		if(tmp%2==1) {	
			last1[tmp]=t[1].b,l2[tmp]=1;
			for(int i=2;i<=m2;i++) {
				if(t[i].a>last1[tmp])last1[tmp]=t[i].b,l2[tmp]++;
				else ed[++ans]=t[i].a,ad[ans]=t[i].b;
			}
		}
		else {
			last1[tmp]=ad[1],l2[tmp]=1;
			for(int i=2;i<=m2;i++) {
				if(ed[i]>last1[tmp])last1[tmp]=ad[i],l2[tmp]++;
				else t[++ans].a=ed[i],t[ans].b=ad[i];
			}
		}
		
	}
	for(int i=1;i<=n;i++) {
		if(n>=mm1||x[i-1]==mm1) {
			x[i]=mm1;
			continue;
		}
		x[i]=x[i]+x[i-1]+l1[i]; 
	} 
	for(int i=1;i<=n;i++) {
		if(n>=mm2||y[i-1]==mm2) {
			y[i]=mm2;
			continue;
		}
		y[i]=y[i]+y[i-1]+l2[i];
	}
	for(int i=0;i<=n;i++) {
		mxx=max(mxx,x[i]+y[n-i]);
	}
	cout<<mxx<<endl;
	return 0;
}
