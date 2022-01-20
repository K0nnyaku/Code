#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;
const int MAXM = 2e2 + 10;
int n,N;
int a[MAXN];
struct Number_ {
	int l,r;
}s[MAXM];
bool F = false;
int b[MAXM],c[MAXM],ans[MAXM];
int read()
{
	int s = 0,f = 0;char ch = getchar();
	while(!isdigit(ch)) f |= ch == '-',ch = getchar();
	while(isdigit(ch)) s = (s << 3) + (s << 1) + (ch ^ 48),ch = getchar();
	return f ? -s : s;
}
bool judge(int L,int R)
{
	for(int i = L,j = R;;i ++,j --) {
		if(i > j) break;
		if(c[i] != c[j]) return false;
	}
	return true;
}
void Dfs(int id,int L,int R)
{
	if(id - 1 > n) {
		if(!judge(N - id + 2,id - 1)) return;
	}
	if(id == N + 1) {
		if(judge(1,N)) {
			if(ans[1] == 0) for(int i = 1;i <= N;i ++) ans[i] = b[i];
			else {
				bool f = false;
				for(int i = 1;i <= N;i ++) {
					if(b[i] < ans[i]) {f = true;break;}
					if(ans[i] < b[i]) break;
				}
				if(f) {
					for(int i = 1;i <= N;i ++) ans[i] = b[i];
				}
			}
		}
		return;
	}
	b[id] = 1;
	c[id] = a[L];
	Dfs(id + 1,L + 1,R);
	c[id] = a[R];
	b[id] = 2;
	Dfs(id + 1,L,R - 1);
	c[id] = 0;
	b[id] = 0;
	return;
} 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T = read();
	while(T --) {
		n = read();N = n * 2;
		memset(s,0,sizeof s);F = false;
		memset(ans,0,sizeof ans);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		for(int i = 1;i <= N;i ++) {
			a[i] = read();
			if(!s[a[i]].l) s[a[i]].l = i;
			else if(s[a[i]].l && !s[a[i]].r) s[a[i]].r = i;
		}
		Dfs(1,1,N); 
		if(ans[1] == 0) {puts("-1");continue;}
		else {
			for(int i = 1;i <= N;i ++) {
				if(ans[i] == 1) printf("L");
				else printf("R");
			}
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
