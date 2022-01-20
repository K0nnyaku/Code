#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

const int N = 1e5 + 10;

struct node {
	int a,b;
};

bool cmp(node x,node y) {
	return x.a < y.a;
}

int n,m1,m2,ans = -1,maxans1 = -1;
node gn[N],gw[N];

priority_queue <int,vector<int>,greater<int> > q1,q2;

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1 ; i<=m1 ; i++) scanf("%d %d",&gn[i].a,&gn[i].b);
	for(int i=1 ; i<=m2 ; i++) scanf("%d %d",&gw[i].a,&gw[i].b);
	sort(gn + 1,gn + 1 + m1,cmp);
	sort(gw + 1,gw + 1 + m2,cmp);
//	printf("Galaxy\n");
	for(int tot=0 ; tot<=n ; tot++) {
		int n1 = tot,n2 = n - tot,ans1 = 0,ans2 = 0;
//		printf("n1 = %d n2 = %d\n",n1,n2);
		while(q1.size()) q1.pop();
		while(q2.size()) q2.pop();
		if(n1 != 0) for(int i=1 ; i<=m1 ; i++) {
//			printf("size1 = %d\n",q1.size());
			int s = gn[i].a,e = gn[i].b;
			while(q1.size() && q1.top() < s) q1.pop();
			if(q1.size() < n1) {
				q1.push(e);
				ans1 ++;
				continue;
			}
		}
		if(ans1 <= maxans1) continue;
		if(n2 != 0) for(int i=1 ; i<=m2 ; i++) {
			int s = gw[i].a,e = gw[i].b;
			while(q2.size() && q2.top() < s) q2.pop();
			if(q2.size() < n2) {
				q2.push(e);
				ans2 ++;
				continue;
			}
		}
		if(ans1 + ans2 > ans) {
			ans = ans1 + ans2;
			maxans1 = ans1; 
		}
//		ans = max (ans,ans1 + ans2);
//		printf("ans_TIME = %d\n",ans1 + ans2);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
