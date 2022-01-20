#include<cstdio>
#include<iostream>
using namespace std;
const int N = 1e6 + 9;
int t, n, a[N], b[N], ans[N];
int l, r, cnt;
int vis[N];
bool flag;
void print(){
	for(int i = 1; i <= n; i++){
		if(b[i] != b[2 * n - i + 1]){
			return;
		}
	}
	flag = 1;
	for(int i = 1; i <= 2 * n; i++){
		if(ans[i] == 1){
			cout << "L";
		}
		else{
			cout << "R";
		}
	}
	return;
}
void dfs(int t){
	if(t > 2 * n){
		print();
		return;
	}
	
	ans[t] = 1;
	b[t] = a[l];
	l++;
	dfs(t + 1);
	l--;
	if(flag) return;
	ans[t] = 2;
	b[t] = a[r];
	r--;
	dfs(t + 1);
	r++;
	if(flag) return;
}
int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		flag = 0;
		scanf("%d", &n);
		l = 1, r = 2 * n;
		for(int i = 1; i <= 2 * n; i++){
			scanf("%d", &a[i]);
			vis[i] = 0;
		}
		dfs(1);
		if(!flag){
			printf("-1");
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
