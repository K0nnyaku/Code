#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
inline void file(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}
inline int rd(){
	register int x=0;
	register char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x; 
}
int n,cnt,wl,wr,il,ir,a[1000010],to[1000010],at[500010];
stack<int> st;
stack<bool> op;
char ans[1000010];
inline bool dfs(){
	if(wl==il+1 && wr==ir-1){
		for(int i=1;i<=n;++i)
			ans[n-i+1]=(op.top()?'R':'L'),op.pop();
		for(int i=1;i<=n;++i)putchar(ans[i]);
		for(int i=1,u;i<=n;++i){
			u=st.top();st.pop();
			if(a[wl]==u)putchar('L'),++wl;
			else if(a[wr]==u)putchar('R'),--wr;
		}
		putchar('\n');
		return 1;
	}
	if(wl==il+1){
		if(a[wr]!=a[ir])return 0;
		st.push(a[wr]),op.push(1);
		++ir,--wr;
		if(dfs())return 1;
		--ir,++wr;
		st.pop(),op.pop();
		return 0;
	}
	if(wr==ir-1){
		if(a[wl]!=a[il])return 0;
		st.push(a[wl]),op.push(0);
		--il,++wl;
		if(dfs())return 1;
		++il,--wl;
		st.pop(),op.pop();
		return 0;
	}
	if(wl!=il && a[wl]==a[il]){
		st.push(a[wl]),op.push(0);
		--il,++wl;
		if(dfs())return 1;
		++il,--wl;
		st.pop(),op.pop();
	}
	if(wl!=ir && a[wl]==a[ir]){
		st.push(a[wl]),op.push(0);
		++ir,++wl;
		if(dfs())return 1;
		--ir,--wl;
		st.pop(),op.pop();
	}
	if(wr!=ir && a[wr]==a[ir]){
		st.push(a[wr]),op.push(1);
		++ir,--wr;
		if(dfs())return 1;
		--ir,++wr;
		st.pop(),op.pop();
	}
	if(wr!=il && a[wr]==a[il]){
		st.push(a[wr]),op.push(1);
		--il,--wr;
		if(dfs())return 1;
		++il,++wr;
		st.pop(),op.pop();
	}
	return 0;
}
int main(){
	file();
	cnt=rd();
	while(cnt--){
		n=rd();
		for(int i=1;i<=n;++i)at[i]=0;
		for(int i=1;i<=2*n;++i){
			a[i]=rd();
			if(at[a[i]]){
				to[i]=at[a[i]];
				to[at[a[i]]]=i;
			}
			else at[a[i]]=i;
		}
		while(!st.empty())st.pop();
		while(!op.empty())op.pop();
		st.push(a[1]),op.push(0);
		wl=2,wr=2*n,il=to[1]-1,ir=to[1]+1;
		if(dfs())continue;
		while(!st.empty())st.pop();
		while(!op.empty())op.pop();
		st.push(a[2*n]),op.push(1);
		wl=1,wr=2*n-1,il=to[2*n]-1,ir=to[2*n]+1;
		if(dfs())continue;
		puts("-1");
	}
	return 0;
}
