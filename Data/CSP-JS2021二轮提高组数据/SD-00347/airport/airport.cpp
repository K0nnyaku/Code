#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m1,m2;
const int M=1e5+5;
priority_queue<int> q;
struct node{
	int com;
	int lef; 
}a[M],b[M];//a国内，b国外。 
bool cmp(node x,node y){
	if(x.com==y.com) return x.lef<y.lef;
	return x.com<y.com;
}
void init(){
	while(!q.empty()) q.pop();
}
int main(){
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].com,&a[i].lef);
	}
	sort(a+1,a+1+m1,cmp);
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].com,&b[i].lef);
	}
	sort(b+1,b+1+m2,cmp);
	int ans=0;
	for(int i=0;i<=n;i++){
		init();
		int k=1,sum=0;
		if(i!=0) sum++;
		q.push(-a[1].lef);
		int y1=-q.top();
		for(int j=2;j<=m1;j++){
			if(i==0) continue;
			if(k>=i&&a[j].com<y1) continue;
			sum++;
			q.push(-a[j].lef);
			while(!q.empty()){
				int s=-q.top();
				if(a[j].com>s) q.pop();
				else break;
			}
			if(!q.empty()){
				k=q.size();
				y1=-q.top();
			}
			else {
				k=0;
				y1=0;
			}
		}
		k=1;
		int m=n-i;
		if(m!=0) sum++;
		init();
		q.push(-b[1].lef);
		int y2=-q.top();
		for(int j=2;j<=m2;j++){
			if(m==0) continue;
			if(k>=m&&b[j].com<=y2) continue;
			sum++;
			q.push(-b[j].lef);
			
			while(!q.empty()){
			int s=-q.top();
			int t=b[j].com;
			if(t>s) q.pop();
			else break;
		}
			if(!q.empty()){
				k=q.size();
				y2=-q.top();
			}
			else {
				y2=0;
				k=0;
			}
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	fclose(stdin);
    fclose(stdout);
	return 0;
}

