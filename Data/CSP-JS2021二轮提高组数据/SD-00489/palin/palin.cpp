#include <cstdio>
#include <queue>

using std::deque;

const int N=5e5+11;

int t;
int n;
int x;

namespace sbtsk_1 {
	int ans[N<<1];
	int fwd[N<<1],fwl;
	
	bool flag;
	
	deque<int> q;
	
	inline bool check() {
		for(int i=1,j=n*2;i<=j;i++,j--) {
			if(fwd[i]!=fwd[j]) return 0;
		}
		return 1;
	}
	
	void dfs(int step) {
//		printf("%d ",step);
//		for(int i=1;i<=n*2;i++) {
//			putchar(ans[i]==0?'E':(ans[i]==1?'L':'R'));
//		}
//		printf(" %d\n",check());
		
		if(flag || n*2<step) return;
		if(step==n*2) {
			flag=check();
		}
		else {
			fwd[++fwl]=q.front();
			q.pop_front();
			ans[fwl]=1;
			dfs(step+1);
			if(flag) return;
			ans[fwl]=0;
			q.push_front(fwd[fwl--]);
			
			fwd[++fwl]=q.back();
			q.pop_back();
			ans[fwl]=2;
			dfs(step+1);
			if(flag) return;
			ans[fwl]=0;
			q.push_back(fwd[fwl--]);
		}
	}
	
	inline void sov() {
		flag=fwl=0;
		q.clear();
		for(int i=1;i<=n*2;i++) {
			scanf("%d",&fwd[i]);
			q.push_back(fwd[i]);
		}
		if(check()) {
			for(int i=1;i<=n*2;i++) putchar('L');
			putchar('\n');
			return ;
		}
		dfs(0);
		if(flag) {
			for(int i=1;i<=n*2;i++) {
				putchar(ans[i]==0?'E':(ans[i]==1?'L':'R'));
			}
			putchar('\n');
		}
		else printf("-1\n");
	}
}


int main() {
//	freopen("palin1.in","r",stdin);
//	freopen("palin1.out","w",stdout);

	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	scanf("%d",&t);
	for(int T=1;T<=t;T++) {
		scanf("%d",&n);
		sbtsk_1::sov();
	}
	return 0;
}
