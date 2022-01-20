#include<iostream>
#include<cstring>
#include<queue>
#define N 100001
using namespace std;

int p1[N],p2[N],a[N],b[N],t1[N],t2[N];
int n,m1,m2,M1 = 0,M2 = 0;
int ans = 0,s = 0;

void check1(int i,int j) {
			p1[j] = p1[j-1];
			if(t1[j]) p1[j] --;
			if(a[j]) {
				if(p1[j] + 1 <= i)
				{
					s ++;
					t1[a[j]] = 1;
					p1[j] ++;
				}
			}
}

void check2(int i,int j) {
		p2[j] = p2[j-1];
			if(t2[j]) p2[j] --;
			if(b[j]) {
				if(p2[j] + 1 <= i)
				{
					s ++;
					t2[b[j]] = 1;
					p2[j] ++;
				}
			}
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i = 1;i <= m1;i ++) {int x,y; cin>>x>>y; a[x] = y;M1 = max(M1,y);}
	for(int i = 1;i <= m2;i ++) {int x,y; cin>>x>>y; b[x] = y;M2 = max(M2,y);}
	M1 = max(M1,M2);
	for(int i = 0;i <= n;i ++) {
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		for(int j = 1;j <= M1;j ++){
			check1(i,j);
			check2(n-i,j);
		}
		ans = max(ans,s);
		s = 0;
	}
	cout<<ans;
	return 0;
}
