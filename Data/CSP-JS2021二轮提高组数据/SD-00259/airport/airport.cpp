#include<bits/stdc++.h>
using namespace std;
struct node{
	int st;
	int ed;
};
node a[100005],b[100005];
int suma[100005],sumb[100005];
int fa[100005],fb[100005];
int n,m1,m2,k1,k2,ans;
bool cmp(node l,node r){
	return l.st<r.st;
}
int max(int tr,int tt){
	return tr<tt?tt:tr; 
}
int min(int tr,int tt){
	return tr<tt?tr:tt;
}
priority_queue<int,vector<int>,greater<int> >q1;
priority_queue<int,vector<int>,greater<int> >q2; 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].st,&a[i].ed);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].st,&b[i].ed);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	suma[1]=1;sumb[1]=1;fa[1]=a[1].ed;fb[1]=b[1].ed;
	k1=1;k2=1;q1.push(a[1].ed);q2.push(b[1].ed);
	for(int i=2;i<=m1;i++){
		while(a[i].st>q1.top()&&!q1.empty())q1.pop();
		if(q1.size()<k1){
			fa[k1]=min(fa[k1],a[i].ed);
			for(int j=1;j<=k1;j++)
			if(fa[j]<a[i].st)suma[j]++;
			q1.push(a[i].ed);
		}
		else{
			k1++;
			fa[k1]=min(fa[k1-1],a[i].ed);
			suma[k1]=suma[k1-1]+1;
			q1.push(a[i].ed);
		}
	}
	for(int i=2;i<=m1;i++){
		while(b[i].st>q2.top()&&!q2.empty())q2.pop();
		if(q2.size()<k2){
			fb[k2]=min(fb[k2],b[i].ed);
			for(int j=1;j<=k2;j++)
			if(fb[j]<b[i].st)sumb[j]++;
			q2.push(b[i].ed);
		}
		else{
			k2++;
			fb[k2]=min(fb[k2-1],b[i].ed);
			sumb[k2]=sumb[k2-1]+1;
			q2.push(b[i].ed);
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,suma[i]+sumb[n-i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
