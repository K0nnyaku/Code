#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;
struct time123{
	int l,r;
};
int f1[N],f2[N],tot1,tot2;
time123 g1[N],g2[N];
int n,m1,m2;
bool operator < (const time123 a,const time123 b){
	return a.l < b.l;
}
void init(){
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1 ; i <= m1 ; ++i)
		scanf("%d%d",&g1[i].l,&g1[i].r);
	for(int i = 1 ; i <= m2 ; ++i)
		scanf("%d%d",&g2[i].l,&g2[i].r);
	sort(g1 + 1,g1 + 1 + m1);
	sort(g2 + 1,g2 + 1 + m2);
}

int dpf(){
	int ops4[N];
	int tot = 0;
	bool flag;
	for(int i = 1 ; i <= m1 ; ++i){
		flag = true;
		for(int j = 1 ; j <= tot ; ++j)
			if(ops4[j] <= g1[i].l){
				++f1[j],ops4[j] = g1[i].r,flag = false;
				break;
			}
		if(flag && tot < n){
			ops4[++tot] = g1[i].r;
			++f1[tot];
		}
	}
	tot = 0;
	for(int i = 1 ; i <= m2 ; ++i){
		flag = true;
		for(int j = 1 ; j <= tot ; ++j)
			if(ops4[j] <= g2[i].l){
				++f2[j],ops4[j] = g2[i].r,flag = false;
				break;
			}
		if(flag && tot < n){
			ops4[++tot] = g2[i].r;
			++f2[tot];
		}
	}
	for(int i = 2 ; i <= n ; ++i)
		f1[i] += f1[i - 1],f2[i] += f2[i - 1];
}

void put_answer(){
	int ans = 0;
	for(int i = 0 ; i <= n ; ++i)
		ans = max(ans,f1[i] + f2[n - i]);	
	printf("%d",ans);
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	init();
	dpf();
	put_answer();
	return 0;
}
