#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
using namespace std;

const int N = 1e5 + 10;

struct node {
	int idx,en,val;
	node(){}
	node(int a,int b,int c) {
		idx = a,en = b,val = c;
	}
};

bool operator<(const node& x,const node& y) {
	return x.idx < y.idx;
}

int n,m1,m2;

struct Node {
	int a,b;
};

bool cmp(Node x,Node y) {
	return x.a < y.a;
}

Node gn[N],gw[N];
set <node> s1,s2;
int sum1[N],sum2[N];

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1 ; i<=m1 ; i++) scanf("%d %d",&gn[i].a,&gn[i].b);
	for(int i=1 ; i<=m2 ; i++) scanf("%d %d",&gw[i].a,&gw[i].b);
	sort(gn + 1,gn + 1 + m1,cmp);
	sort(gw + 1,gw + 1 + m2,cmp);
	for(int i=1 ; i<=m1 ; i++) {
		int a = gn[i].a,b = gn[i].b;
		set<node>::iterator it;
		bool flag = 0;
		for(it = s1.begin() ; it != s1.end() ; it++) {
			if(it->en < a) {
				flag = 1;
				int idx = it->idx,val = it->val;
				s1.erase(it);
				s1.insert(node(idx,b,val + 1));
				break;
			}
		}
		if(!flag) s1.insert(node(i,b,1));
	}
	for(int i=1 ; i<=m2 ; i++) {
		int a = gw[i].a,b = gw[i].b;
		set<node>::iterator it;
		bool flag = 0;
		for(it = s2.begin() ; it != s2.end() ; it++) {
			if(it->en < a) {
				flag = 1;
				int idx = it->idx,val = it->val;
				s2.erase(it);
				s2.insert(node(idx,b,val + 1));
				break;
			}
		}
		if(!flag) s2.insert(node(i,b,1));
	}
	set <node> ::iterator it;
	int cnt = 0;
	for(it = s1.begin() ; it != s1.end() ; it ++) {
		cnt ++;
		sum1[cnt] = sum1[cnt - 1] + it->val;
	}
	cnt = 0;
	for(it = s2.begin() ; it != s2.end() ; it ++) {
		cnt ++;
		sum2[cnt] = sum2[cnt - 1] + it->val;
	}
	int ans = -1;
	for(int tot=0 ; tot<=n ; tot++) {
		int n1 = tot,n2 = n - tot;
		ans = max(ans,sum1[n1] + sum2[n2]);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
