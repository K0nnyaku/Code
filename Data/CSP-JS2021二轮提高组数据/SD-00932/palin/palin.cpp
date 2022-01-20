#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int read() {
  int x = 0, f = 1; char c = getchar();
  while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
  while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
  return x * f;
}
int T, a[MAXN], b[MAXN], fag, Ans[MAXN], n;
int num[MAXN];
void dfs(int x) {
  if(num[x - 1] > Ans[x - 1]) return ;
  if(x == n * 2 + 1) {
  	int tot = 0, l = 1, r = 2 * n;
  	for (int i = 1; i <= n * 2; i++) {
	   if(num[i] == 1) b[++tot] = a[l++];
	   if(num[i] == 2) b[++tot] = a[r--];
    }
	for (int i = 1; i <= n; i++){
	  if(b[i] != b[2 * n - i + 1]) return ; 
    }
	if(!fag) { 
	  fag = 1;
	  for (int i = 1; i <= 2 * n; i++) Ans[i] = num[i];
	  return ;
	} 
	else {
	  for (int i = 1; i <= 2 * n; i++) {
	    if(Ans[i] < num[i]) return ;
	    if(Ans[i] > num[i]) break;
	  }
	  for (int i = 1; i <= 2 * n; i++) Ans[i] = num[i];
	  return ;
	}
	return ;
  }
  for (int i = 1; i <= 2; i++) {
  	 num[x] = i;
  	 dfs(x + 1);
  }
}
int main(){
   freopen("palin.in", "r", stdin);
   freopen("palin.out", "w", stdout);
   T = read();
   while(T--) {
   	 n = read();
   	 for (int i = 1; i <= 2 * n; i++) a[i] = read();
     fag = 0;
     memset(Ans, 0x3f3f, sizeof Ans);
	 dfs(1);  
	 if(fag == 0) {
	 	cout<<"-1\n";
	 	continue;
	 }
	 for (int i = 1; i <= 2 * n; i++) {
	 	if(Ans[i] == 1) cout<<"L";	 
		else cout<<"R";
	 }
	 puts(""); 
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
