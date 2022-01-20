#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const int INF=1e8+7;
int n,m1,m2,maxx,max1,max2;
int es[maxn];

struct node{
	int x,y;
}fj1[maxn];

struct edge{
	int x,y;
}fj2[maxn];

bool cmp1(node x,node y) {
	if(x.y==y.y) {
		return x.x<y.x;
	}
	return x.y<y.y;
}

bool cmp2(edge x,edge y) {
	if(x.y==y.y) {
		return x.x<y.x;
	}
	return x.y<y.y;
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) {
		cin>>fj1[i].x>>fj1[i].y;
	}
	sort(fj1+1,fj1+1+n,cmp1);
	for(int i=1;i<=m2;i++) {
		cin>>fj2[i].x>>fj2[i].y;
	}
	sort(fj2+1,fj2+1+n,cmp2);
	for(int i=0;i<=n;i++) {
		int cnt=0;
		int nei=i,wai=n-i;
		es[1]=fj1[1].y;
		cnt=1;
		for(int j=2;j<=m1;j++) {
			int xxx=min(cnt,nei);
			for(int k=1;k<=xxx;k++) {
				if(fj1[j].x>=es[k]) {
					es[k]=fj1[j].y;
					cnt++;
					break;
				}
				else if(cnt<nei) {
					es[++cnt]=fj1[j].y;
					break;
				}
			}
			max1=max(max1,cnt);
		}
		memset(es,0,sizeof(es));
		int sum=0;
		for(int j=2;j<=m2;j++) {
			int xxx=min(sum,nei);
			for(int k=1;k<=xxx;k++) {
				if(fj2[j].x>=es[k]) {
					es[k]=fj2[j].y;
					sum++;
					break;
				}
				else if(cnt<nei) {
					es[++sum]=fj1[j].y;
					break;
				}
			}
			max2=max(max2,sum);
		}
		if(max1+max2>maxx) {
			maxx=max1+max2;
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4
1 5 
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30 
40 50
21 22
41 42
1 19
2 18
3 4 
5 6 
7 8 
9 10



*/

