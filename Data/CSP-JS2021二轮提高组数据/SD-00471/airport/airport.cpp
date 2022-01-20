#include<bits/stdc++.h>
using namespace std;

struct tata{	int s,id;}g[200005];
struct data{	int a,b;bool fl;}f1[100005],f2[100005],z;
int n,m1,m2,cnt1,cnt2,ans,t1[200005],t2[200005],p1[200005],p2[200005];
bool flag1[200005],flag2[200005];

bool comp(data x,data y) {	return x.a<y.a;}

bool cmp(tata x,tata y) {	return x.s<y.s;}

void init1() {
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&f1[i].a,&f1[i].b);
	}
	sort(f1+1,f1+1+m1,comp);
	for(int i=1;i<=m1;i++) {
		g[++cnt1].s=f1[i].a;g[cnt1].id=i;
		g[++cnt1].s=f1[i].b;g[cnt1].id=i;
	}
	sort(g+1,g+1+cnt1,cmp);
	for(int i=1;i<=cnt1;i++) {
		if(f1[g[i].id].fl==0) {
			f1[g[i].id].a=i;
			t1[i]=1;
			p1[i]=g[i].id;
			f1[g[i].id].fl=1;
		}
		else {
			f1[g[i].id].b=i;
			p1[i]=g[i].id;
			t1[i]=2;
		}
	}
}

void init2() {
	for(int i=1;i<=m2;i++) {
		scanf("%d%d",&f2[i].a,&f2[i].b);
	}
	sort(f2+1,f2+1+m2,comp);
	for(int i=1;i<=m2;i++) {
		g[++cnt2].s=f2[i].a;g[cnt2].id=i;
		g[++cnt2].s=f2[i].b;g[cnt2].id=i;
	}
	sort(g+1,g+1+cnt2,cmp);
	for(int i=1;i<=cnt2;i++) {
		if(f2[g[i].id].fl==0) {
			f2[g[i].id].a=i;
			t2[i]=1;
			p2[i]=g[i].id;
			f2[g[i].id].fl=1;
		}
		else {
			f2[g[i].id].b=i;
			p2[i]=g[i].id;
			t2[i]=2;
		}
	}
}

//1表示进入 
int check1(int m) {
	int count=0,now=0;
	for(int i=1;i<=cnt1;i++) {
		if(t1[i]==1&&now<m) {
			now++;count++;
			flag1[p1[i]]=1;
		}
		if(t1[i]==2&&flag1[p1[i]]==1)now--;
	}
	return count;
}

int check2(int m) {
	int count=0,now=0;
	for(int i=1;i<=cnt2;i++) {
		if(t2[i]==1&&now<m) {
			now++;count++;
			flag2[p2[i]]=1;
		}
		if(t2[i]==2&&flag2[p2[i]]==1)now--;
	}
	return count;
}

int main() {
	
	freopen("airport.in","r",stdin); 
	freopen("airport.out","w",stdout); 
	
	scanf("%d%d%d",&n,&m1,&m2);
	
	if(n>=m1+m2) {	cout<<m1+m2; return 0;}
	
	init1();
	memset(g,0,sizeof(g));
	init2();
	
	int ans=max(check1(n),check2(n));
	for(int i=1;i<n;i++) {
		ans=max(ans,check1(i)+check2(n-i));
	}
	cout<<ans;
	
	return 0;
}
