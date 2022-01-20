#include<bits/stdc++.h>
using namespace std;
const int CN = 505; const int P = 1e9 + 7;
int n, m; char ch[CN];
int add(int x, int y) {return x + y < P ? x + y : x + y - P;}
int ans = 0; char cur[CN];
bool ck(int l, int r){
	if(cur[l] == '*' || cur[r] == '*') return 0;
	if(cur[l] != '(' || cur[r] != ')') return 0;
	if(l + 1 == r) return 1;
	l++, r--; int p = l, q = r;
	while(p <= r && cur[p] == '*') p++;
	if(p > r) return (r - l + 1) <= m;
	while(q >= l && cur[q] == '*') q--;
	if((q ^ r) && (p ^ l)) return 0;
	return ck(max(p, l), min(q, r));
}
void work(int pos){
	if(pos > n){
		if(ck(1, n)){
			cerr << (cur + 1) << endl;
			ans++;
	    }
		return;
	}
	if(ch[pos] != '?') cur[pos] = ch[pos], work(pos + 1);
	else{
		cur[pos] = '(', work(pos + 1);
		cur[pos] = '*', work(pos + 1);
		cur[pos] = ')', work(pos + 1);
	}
}
int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d%s", &n, &m, ch + 1);
	work(1), printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
/*
int f[CN][CN]; bool vis[CN][CN];
void work(int l, int r){
	if(l == r) return 0; if(vis[l][r]) return f[l][r];
	f[l][r] = 0, vis[l][r] = 1;
	if((ch[l] == '?' || ch[l] == '(') && (ch[r] == ')' || ch[r] == '?')){
        f[l][r] = 1;
        
	}
	return f[l][r];
}*/
/*void work(){
	if(ch[1] == '*' || ch[1] == ')') {printf("0\n"); return;}
	f[1][0][1] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < min(i, m); j++){
			for(int k = 0; k <= i; k++) if(f[i][j][k]){
				// * 
				if(ch[i + 1] == '*' || ch[i + 1] == '?')
				    f[i + 1][j + 1][k] = add(f[i + 1][j + 1][k], f[i][j][k]);
				// (
				if(ch[i + 1] == '(' || ch[i + 1] == '?')
				    f[i + 1][0][k + 1] = add(f[i + 1][0][k + 1], f[i][j][k]);
				// )
				if(k && (ch[i + 1] == ')' || ch[i + 1] == '?'))
				    f[i + 1][0][k - 1] = add(f[i + 1][0][k - 1], f[i][j][k]);
			}
		}
	}
	int ans = 0;
	for(int j = 0; j <= m; j++){
		ans = add(ans, f[n - 1][j][1]);
		cerr << f[n - 1][j][1] << endl;
    }
	printf("%d\n", ans);
}*/
