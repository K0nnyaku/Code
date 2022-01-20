#include <bits/stdc++.h>
#include <cstring>
using namespace std;

const int N=100;
int n,fl;
int a[N],book[N],b[N];
char ans[100001],now[100001];

bool cmp(char *s, char *b) {
	for(int i = 1;i <= 2*n;i ++) {
		if(s[i] > b[i]) return true;
		if(s[i] < b[i]) return false;
	} 
	return false;
}

void cop(char *s, char *b) {
	for(int i = 1;i<=2*n;i++)s[i] = b[i];
}
bool check(int *b) {
	for(int i = 1;i <= n;i++){
		if(b[i]!=b[2*n+1-i]) return false;
	}
	return true;
}

void dfs(int k,int st,int ed) {
	if(st == ed) {
		now[2*n]='L';
		b[2*n] = a[st];
		if(cmp(ans,now)) if(check(b)) cop(ans,now), fl = 1;
		return;
	}
	now[k] = 'L';
	b[k] = a[st];
	dfs(k+1,st+1,ed);
	now[k] ='R';
	b[k] = a[ed];
	dfs(k+1,st,ed-1);
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T --) {
		memset(b, 0, sizeof b);
		memset(now, 0, sizeof now);
		fl = 0;
		cin >> n;
		for(int i= 1;i<=2*n;i++)ans[i]='Z'+1;
		for(int i = 1;i <= n*2;i++) cin>>a[i];
		dfs(1,1,2*n);
		if(!fl) cout << -1 << endl;
		else  {for(int i=1;i<=n*2;i++)cout<<ans[i];
		cout <<endl;
		}
	}
	return 0;
}
