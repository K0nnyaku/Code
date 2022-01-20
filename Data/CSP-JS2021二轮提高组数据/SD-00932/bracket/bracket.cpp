#include<bits/stdc++.h>
using namespace std;
const int MAXN = 510;
int read() {
  int x = 0, f = 1; char c = getchar();
  while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
  while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
  return x * f;
}
int n, K, num[MAXN], tot, Ans, nxt[MAXN];
int cz[MAXN], fag[MAXN], ret[MAXN];
char s[MAXN];
void dfs(int x) {
  if(x == tot + 1) {
    int tmp = 1, Max = 0, lnum = 0, rnum = 0;
    memset(cz, 0, sizeof cz);
    memset(fag, 0, sizeof fag);
    memset(nxt, 0, sizeof nxt);
    int pos = 0;
    for (int i = 1; i <= n; i++) {
       if(s[i] == '(') {ret[i] = 1, cz[i] = tmp++, Max = max(cz[i], Max), lnum++;}
       else if(s[i] == ')') {ret[i] = 2, cz[i] = --tmp; Max = max(cz[i], Max), rnum++;}
       else if(s[i] == '?') {
       	 pos++;
       	 if(num[pos] == 0) cz[i] = tmp++, lnum++, ret[i] = 1, Max = max(cz[i], Max);
		 if(num[pos] == 1) cz[i] = --tmp, rnum++, ret[i] = 2, Max = max(cz[i], Max);
		 if(num[pos] == 2) ret[i] = 3;
	   }
	   else if(s[i] == '*') ret[i] = 3;
	   if(rnum > lnum) return ;
    }  
    if(lnum != rnum) return ;
    for (int i = 1; i <= Max; i++) {
      int l, r;
	  for (int j = 1; j <= n; j++) {
        if(cz[j] == i && ret[j] == 1) l = j;
        if(cz[j] == i && ret[j] == 2) { 
		   r = j;
           if(r == l + 1) {//() 
		      nxt[l] = r;
			  continue;
		   }
		   int tot = 0;
		   for (int k = l + 1; k <= r - 1; k++) if(ret[k] == 3) tot++;
		   if(tot == r - l - 1 && r - l - 1 <= K) {//ȫΪ * 
		   	   nxt[l] = r; continue;
		   }
           int lst = l + 1, lg = 0, judge = 0, cnt = 0;
           for (int k = l + 1; k <= r - 1;) {
           	  if(nxt[k]) k = nxt[k] + 1, lg ^= 1, cnt = 0;
           	  else {
           	    if(lg == 0) cnt++;
				if(cnt > K) return ;	
			  }
		   }
		   if(cnt > 2) return ;
		   if(i == 1 && cnt) return ;
		}
      }
	}
	Ans++;
	return;
  }
  for (int i = 0; i <= 2; i++) {
  	 num[x] = i;
  	 dfs(x + 1);
  }
}
int main(){
   freopen("bracket.in", "r", stdin);
   freopen("bracket.out", "w", stdout);
   n = read(), K = read();
   scanf("%s", s + 1);
   for (int i = 1; i <= n; i++) if(s[i] == '?') tot++;
   dfs(1);
   cout<<Ans;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
/*
18 3
((**()*(*))*)(***)
7 3
(*??*??
10 2
???(*??(?)
*/ 
