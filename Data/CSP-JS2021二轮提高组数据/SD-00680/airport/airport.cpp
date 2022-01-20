#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n,m[2];
int a,b;
int k[2][100005];
vector<pair<int,int> >v;
struct node{
	int tm,nm;
	bool operator<(const node &b)const{
		if(tm!=b.tm)return tm>b.tm;
		return nm>b.nm;
	}
};
node make_node(int c,int d){
	node res;
	res.tm=c;
	res.nm=d;
	return res;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,m,m+1);
	for(int i=0;i<2;++i){
		priority_queue<node>pq;
		set<int>q;
		for(int j=1;j<=n;++j){
			k[i][j]=0;
			q.insert(j);
		}
		for(int j=0;j<m[i];++j){
			scanf("%d%d",&a,&b);
			v.push_back(make_pair(a,b));
		}
		sort(v.begin(),v.end());
		for(int j=0;j<m[i];++j){
			a=v[j].first;
			b=v[j].second;
			while(!pq.empty()&&pq.top().tm<a){
				q.insert(pq.top().nm);
				pq.pop();
			}
			if(q.empty())continue;
			set<int>::iterator it=q.begin();
			int s=*it;
			q.erase(s);
			k[i][s]++;
			pq.push(make_node(b,s));
		}
		for(int j=1;j<=n;++j){
			k[i][j]+=k[i][j-1];
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		ans=max(ans,k[0][i]+k[1][n-i]);
	}
	printf("%d\n",ans);
	return 0;
}

