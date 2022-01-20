#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005
struct fly{
	int l,r;
}a[maxn],b[maxn];
int n,m1,m2,ans;
priority_queue<int,vector<int>,greater<int> > q;
int getm() {
	int ned=0;
	while(q.size()) q.pop();
	for(int i=1;i<=m1;i++) {
		while(q.size() && q.top() < a[i].l) q.pop();
		q.push(a[i].r);
		ned=max(ned,(int)q.size());
	}
	return min(ned,n);
}
bool cmp(fly x,fly y) {
	return x.l < y.l;
}
int work(int num) {
	int answer=0;
	while(q.size()) q.pop();
	for(int i=1;i<=m1;i++) {
		while(q.size() && q.top() < a[i].l) q.pop();
		if(q.size() < num) {
			answer++;
			q.push(a[i].r);
		}
	}
	while(q.size()) q.pop();
	for(int i=1;i<=m2;i++) {
		while(q.size() && q.top() < b[i].l) q.pop();
		if(q.size() < n-num) {
			answer++;
			q.push(b[i].r);
		}
	}
	return answer;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++) scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
//	for(int i=1;i<=m1;i++) {
//		for(int j=1;j<=a[i].r;j++) {
//			if(j<a[i].l) printf(" ");
//			else
//			printf("*");
//		}
//		puts("");
//	}
	int num=getm();
	for(int i=0;i<=num;i++) {
		ans=max(ans,work(i));
//		printf("%d\n",work(i));
	}
	cout<<ans<<endl;
//	cout<<num<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
