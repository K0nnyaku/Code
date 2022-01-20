#include<bits/stdc++.h>
#define LL long long
#define rep(i,l,r) for(int i = l;i<=r;++i)
#define reg register
#define IT iterator
#define pb(x) push_back(x)
#define PII pair<int,int>
#define PIII pair<PII,int>
#define x first
#define y second
using namespace std;
const int N = 1e7+10,p = 1;
const bool is_file = 1;
const string Name = "airport";

int n,m_1,m_2;
PII a_1[N],a_2[N],A_1[N],A_2[N];

void init(){
	cin>>n>>m_1>>m_2;
	rep(i,1,m_1){
		cin>>a_1[i].first>>a_1[i].second;
//		lsh[++lsh_cnt]=a_1[i].first;lsh[++lsh_cnt]=a_1[i].second;
	}
	rep(i,1,m_2){
		cin>>a_2[i].first>>a_2[i].second;
//		lsh[++lsh_cnt]=a_2[i].first;lsh[++lsh_cnt]=a_2[i].second;
	}
//	sort(lsh+1,lsh+1+lsh_cnt);lsh_cnt=unique(lsh+1,lsh+1+lsh_cnt)-(lsh+1);
	sort(a_1+1,a_1+1+m_1);sort(a_2+1,a_2+1+m_2);
	rep(i,1,m_1){
		A_1[i]=a_1[i];
		swap(A_1[i].first,A_1[i].second);
	}
	rep(i,1,m_2){
		A_2[i]=a_2[i];
		swap(A_2[i].first,A_2[i].second);
	}
} 
int f[N],g[N],F[N],G[N];
int clac_1(int pott){ 
	priority_queue<PII,vector<PII>,greater<PII> > q;
	int res = 0;
	#define L second
	#define R first
	rep(i,1,m_1){
		while(q.size()){
			PII t = q.top();
			if(t.R<A_1[i].L){
				q.pop();
			}else{
				break;
			}
		}
		if(q.size()<pott){
			q.push(A_1[i]);
			++res;
		}
	}
	#undef L
	#undef R
	return res;
}
int clac_2(int pott){ 
	priority_queue<PII,vector<PII>,greater<PII> > q;
	int res = 0;
	#define L second
	#define R first
	rep(i,1,m_2){
		while(q.size()){
			PII t = q.top();
			if(t.R<A_2[i].L){
				q.pop();
			}else{
				break;
			}
		}
		if(q.size()<pott){
			q.push(A_2[i]);
			++res;
		}
	}
	#undef L
	#undef R
	return res;
}
namespace subtask_1{
	int tr[N];

	int lowbit(int x){return x&(-x);}
	void add(int x,int k){
		while(x<=n+1){
			tr[x]+=k;
			x+=lowbit(x);
		}
	}
void add_sec(int l,int r,int k){add(r+1,-k),add(l,k);}
int query(int x){
	int res = 0;
	while(x){
		res+=tr[x];
		x-=lowbit(x);
	}
	return res;
}
	int f[N],g[N],F[N],G[N];
	void clac(){
		rep(i,1,m_1){
			int l = a_1[i].first,r = a_1[i].second;
			f[i]=query(l)+1;add_sec(l,r,1);
		}
		memset(tr,0,sizeof tr);
		rep(i,1,m_2){
			int l = a_2[i].first,r = a_2[i].second;
			g[i]=query(l)+1;add_sec(l,r,1);
		}
		rep(i,1,n){
			--F[f[i]-1];F[0]++;
			--G[g[i]-1];g[0]++;
		}
		rep(i,1,n){
			F[i]+=F[i-1];
			G[i]+=G[i-1];
		}
	}
	int solve(){
		clac();
		int ans=1e9+7;
		rep(i,1,n){
			ans=min(ans,F[i]+G[n-i]);
		}
		cout<<(m_1+m_2-ans);
		return 0;
	}
		
};
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	init();
	if(n>5010){
		subtask_1::solve();
		return 0; 
	}
	int ans = 0;
	rep(i,0,n){
		ans=max(ans,clac_1(i)+clac_2(n-i));
	}
	cout<<ans;
	return 0;
}

