#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
	bool operator<(const node&a)const{
		return a.r<r;
	}
};
node a[100005],b[100005];
int n,m1,m2;
bool cmp(node a,node b){
	return a.l<b.l;
}
priority_queue<node,vector<node> >q;
int num(int k1){
	int cnt=0,k2=n-k1;
	while(!q.empty())
		q.pop();
	cnt=0;
	for(int i=1;i<=m1;i++){
		if(k1==0)
			break;
		if(q.size()<k1){
			cnt++;
			q.push(a[i]);
			continue;
		}
		else if(a[i].l>=q.top().r){
			cnt++;
			q.pop();
			q.push(a[i]);
		}
	}
	while(!q.empty())
		q.pop();
	for(int i=1;i<=m2;i++){
		if(k2==0)
			break;
		if(q.size()<k2){
			cnt++;
			q.push(b[i]);
			continue;
		}
		else if(b[i].l>=q.top().r){
			cnt++;
			q.pop();
			q.push(b[i]); 
		}
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int ans=0;
	if(n<=100){
		for(int k1=0;k1<=n;k1++){
			ans=max(ans,num(k1));
		}
		printf("%d",ans);
		return 0;
	}
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		int x=num(mid);
		if(x<=num(mid+1)){
			ans=max(ans,x);
			l=mid+1;
		}
		else{
			ans=max(ans,x);
			r=mid-1;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
