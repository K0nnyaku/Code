#include<set>
#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 150017
#define P pair<int,int> 
#define fir(i) i.first
#define sec(i) i.second
#define mk(i,j) make_pair(i,j)
using namespace std;

int n,m[2];
struct issue{int a,b;}p[2][N];
struct BIT{
	int c[N];
	int lowbit(int x) {
		return x & (-x);
	}
	void insert(int x) {
		for(;x < N;x += lowbit(x)){
			c[x]++;
		}
	}
	int query(int x) {
		int res = 0;
		for(;x;x -= lowbit(x)){
			res += c[x];
		}
		return res;
	}
}tr[2]; 

bool cmp(issue A,issue B) {
	return A.a < B.a;
}

void solve(bool f) {
	set<int>st;priority_queue<P >q;
	for(int i = 1;i <= n;i += 1)
		st.insert(i);
	for(int i = 1;i <= m[f];i += 1){
		while(!q.empty() && (-1)*fir(q.top()) <= p[f][i].a){
			st.insert(sec(q.top()));q.pop();
		}
		if((int)st.size()){
			int pos = *st.begin();
			tr[f].insert(pos);q.push(mk(-p[f][i].b,pos));st.erase(pos);
		}
	}
}

int main()
{
	freopen("airport.in","r",stdin);freopen("airport.out","w",stdout); 
	scanf("%d%d%d",&n,&m[0],&m[1]);
	for(int i = 1;i <= m[0];i += 1)scanf("%d%d",&p[0][i].a,&p[0][i].b);
	for(int i = 1;i <= m[1];i += 1)scanf("%d%d",&p[1][i].a,&p[1][i].b);
	sort(p[0]+1,p[0]+m[0]+1,cmp);sort(p[1]+1,p[1]+m[1]+1,cmp);
	solve(0);solve(1);int ans = 0;
	for(int i = 0;i <= n;i += 1)ans = max(ans,tr[0].query(i)+tr[1].query(n-i));
	printf("%d\n",ans);
	return 0;
}

