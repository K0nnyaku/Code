#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<queue>
using namespace std;
#define S 100005
int n,m1,m2,to,f1[S],f2[S];
struct pl{
	int ar,le;
}a[S],b[S],k;
bool cmp(pl x,pl y){
	return x.ar<y.ar;
}
priority_queue<pl>q;
bool operator<(pl x,pl y){
	return x.ar>y.ar;
}
void work1(){
	to=0;
	k.ar=0x7f7f7f7f;
	q.push(k);
	for(int i=1;i<=m1;i++){
		if(q.top().ar>a[i].ar){
			to++;
			f1[to]++;
			k.ar=a[i].le;
			k.le=to;
			q.push(k);
		}
		else{
			k=q.top();
			q.pop();
			k.ar=a[i].le;
			q.push(k);
			f1[k.le]++;
		}
	}
	for(int i=1;i<=n;i++){
		f1[i]=f1[i]+f1[i-1];
	}
}
void work2(){
	to=0;
	while(!q.empty())q.pop();
	k.ar=0x7f7f7f7f;
	q.push(k);
	for(int i=1;i<=m2;i++){
		if(q.top().ar>b[i].ar){
			to++;
			f2[to]++;
			k.ar=b[i].le;
			k.le=to;
			q.push(k);
		}
		else{
			k=q.top();
			q.pop();
			k.ar=b[i].le;
			q.push(k);
			f2[k.le]++;
		}
	}
	for(int i=1;i<=n;i++){
		f2[i]=f2[i]+f2[i-1];
	}
}
int ans=0;
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>a[i].ar>>a[i].le;
	for(int i=1;i<=m2;i++)
		cin>>b[i].ar>>b[i].le;
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	work1();
	work2();
	for(int i=0;i<=n;i++){
		ans=max(ans,f1[i]+f2[n-i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
