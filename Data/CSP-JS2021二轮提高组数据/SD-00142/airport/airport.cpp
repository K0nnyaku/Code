#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
} 
int n,m10,m11;
struct node{
	int l,r;
	bool operator<(const node &k)const{
		return l<k.l;
	}
};
node chi[N],abro[N];
bool cmp(int a,int b){
	return a>b;
}
struct prio{
	int id,nop;
	bool operator<(const prio &k)const{
		return nop>k.nop;
	}
};
priority_queue<prio> q10,q11;
int ans[N]; 
int sum1[N],sum2[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m10=read();
	m11=read();
	for(int i=1;i<=m10;i++){
		chi[i].l=read();
		chi[i].r=read();
	}
	sort(chi+1,chi+1+m10);
	for(int i=1;i<=m11;i++){
		abro[i].l=read();
		abro[i].r=read();
	}
	sort(abro+1,abro+1+m11);
	int maxm=0;
	for(int i=0;i<=n;i++){
		int j=n-i;
		for(int k=1;k<=i;k++){
			prio o;
			o.id=k;
			o.nop=chi[k].r;
			q10.push(o);
			ans[k]=1;
		}
		int tot=i+1;
		while(!q10.empty()){
			prio o=q10.top();
			q10.pop();
			while(chi[tot].l<o.nop&&tot<=m10) tot++;
			if(tot>m10) continue;
			o.nop=chi[tot].r;
			ans[o.id]++;
			q10.push(o);
			tot++;
		}
		int maxn=0;
		for(int k=1;k<=i;k++) maxn+=ans[k];
		for(int k=1;k<=j;k++){
			prio o;
			o.id=k;
			o.nop=abro[k].r;
			ans[k]=1;
			q11.push(o);
		}
		tot=j+1;
		while(!q11.empty()){
			prio o=q11.top();
			q11.pop();
			while(abro[tot].l<o.nop&&tot<=m11) tot++;
			if(tot>m11) continue;
			o.nop=abro[tot].r;
			ans[o.id]++;
			q11.push(o);
			tot++;
		}
		for(int k=1;k<=j;k++) maxn+=ans[k];
		maxm=max(maxm,maxn);
	}
	printf("%d",maxm);
	return 0;
	fclose(stdin);
	fclose(stdout);
}

