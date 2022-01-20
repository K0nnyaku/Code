#include<iostream> 
#include<cstring>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
void file(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int n=0;
	while(c>='0'&&c<='9'){
		n=n*10+c-'0';
		c=getchar();
	}
	return n;
}
const int MAX_N=5e5+500;
int a[MAX_N*2];
bool vis[MAX_N];
int pre[MAX_N];
int nxt[MAX_N];

bool opt[100],ans[100];
int n;
bool flag=false;
void dfs(int k){
	if(k==n*2){
		deque<int> dq;
		for(int i=1;i<=n*2;i++){
			dq.push_back(a[i]);
		}
		deque<int> rs; 
		rs.push_back(0);
		for(int i=1;i<=n*2;i++){
			if(opt[i]){
				rs.push_back(dq.back());
				dq.pop_back();
			}else{
				rs.push_back(dq.front());
				dq.pop_front();
			}
		}
		for(int i=1;i<=n;i++){
			if(rs[i]!=rs[n*2-i+1]){
				return;
			}
		}
		for(int i=1;i<=n*2;i++){
			if(ans[i]!=opt[i]){
				if(ans[i]<opt[i]){
					return;
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n*2;i++){
			ans[i]=opt[i];
		}
		flag=true;
		return;
	}
	dfs(k+1);
	opt[k]=1;
	dfs(k+1);
	opt[k]=0;
}

void solve(){
	n=read();
	for(int i=1;i<=n*2;i++){
		a[i]=read();
	}
	for(int i=1;i<=n*2;i++){
		ans[i]=1;
	}
	flag=false;
	dfs(1);
	if(!flag){
		cout<<"-1"<<endl;
		return;
	}
	for(int i=1;i<=n*2;i++){
		cout<<(ans[i]?'R':'L');
	}
	cout<<endl;
}


int main(){
	file();
	int t=read();
	while(t--)solve();
	return 0;
} 
