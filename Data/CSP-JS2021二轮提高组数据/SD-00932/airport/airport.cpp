#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5100;
int read() {
  int x = 0, f = 1; char c = getchar();
  while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
  while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
  return x * f;
}
int n, m_1, m_2, Ans, t_1[MAXN], t_2[MAXN];
bool  fag[MAXN];
int tmp_1[MAXN], tmp_2[MAXN], tot_1, tot_2;
struct node{int s, t;}a[MAXN], b[MAXN];
bool cmp(node x, node y) {return x.s < y.s;}
int T[MAXN << 2], T_2[MAXN << 2];
void Modify_1(int x){
  for (int i = x; i <= MAXN; i += i & (-i)) T[i]++;
}
int Query_1(int x) {
  int ret = 0;
  for (int i = x; i; i -= i & (-i)) ret += T[i];
  return ret;
}
void Modify_2(int x){
  for (int i = x; i <= MAXN; i += i & (-i)) T_2[i]++;
}
int Query_2(int x) {
  int ret = 0;
  for (int i = x; i; i -= i & (-i)) ret += T_2[i];
  return ret;
}
void work(){
   for (int i = 1; i <= m_1; i++) {
   	  a[i].s = read(), a[i].t = read();
   	  tmp_1[++tot_1] = a[i].s;
	  tmp_1[++tot_1] = a[i].t; 
   }
   for (int i = 1; i <= m_2; i++) {
   	  b[i].s = read(), b[i].t = read();
   	  tmp_2[++tot_2] = b[i].s;
	  tmp_2[++tot_2] = b[i].t; 
   }
   int num_1 = unique(tmp_1 + 1, tmp_1 + tot_1 + 1) - tmp_1 - 1;
   int num_2 = unique(tmp_2 + 1, tmp_2 + tot_2 + 1) - tmp_2 - 1;
   sort(tmp_1 + 1, tmp_1 + num_1 + 1);
   sort(tmp_2 + 1, tmp_2 + num_2 + 1);
   for (int i = 1; i <= m_1; i++) {
   	  a[i].s = lower_bound(tmp_1 + 1, tmp_1 + num_1 + 1, a[i].s) - tmp_1;
   	  a[i].t = lower_bound(tmp_1 + 1, tmp_1 + num_1 + 1, a[i].t) - tmp_1; 
   }
   for (int i = 1; i <= m_2; i++) {
   	  b[i].s = lower_bound(tmp_2 + 1, tmp_2 + num_2 + 1, b[i].s) - tmp_2;
   	  b[i].t = lower_bound(tmp_2 + 1, tmp_2 + num_2 + 1, b[i].t) - tmp_2;
   }
   sort(a + 1, a + m_1 + 1, cmp), sort(b + 1, b + m_2 + 1, cmp);
   for (int cnt_1 = 0; cnt_1 <= n; cnt_1++) {//留给国内航班的 
   	 int cnt_2 = n - cnt_1;
   	 int res_1 = 0, res_2 = 0; 
   	 for (int i = 1; i <= m_1; i++) {
   	   int res = Query_1(a[i].s);
   	   if(i - 1 - res < cnt_1) res_1++, Modify_1(a[i].t);
	 }
	 for (int i = 1; i <= m_2; i++) {
	   int res = Query_2(b[i].s);
	   if(i - 1 - res < cnt_2) res_2++, Modify_2(b[i].t);
	 }
	 Ans = max(Ans, res_1 + res_2);
   }
   cout<<Ans;
}
int main(){
   freopen("airport.in", "r", stdin);
   freopen("airport.out", "w", stdout);
   n = read(), m_1 = read(), m_2 = read();
   if(n >= 1000) {
   	 work();
     fclose(stdin);
     fclose(stdout);
   	 return 0;
   }
   for (int i = 1; i <= m_1; i++) {
   	  a[i].s = read(), a[i].t = read();
   }
   for (int i = 1; i <= m_2; i++) {
   	  b[i].s = read(), b[i].t = read();
   }
   sort(a + 1, a + m_1 + 1, cmp), sort(b + 1, b + m_2 + 1, cmp);
   for (int cnt_1 = 0; cnt_1 <= n; cnt_1++) {//留给国内航班的 
   	 int cnt_2 = n - cnt_1;
   	 int res_1 = 0, res_2 = 0; 
   	 memset(fag, 0, sizeof fag);
   	 for (int i = 1; i <= m_1; i++) {
   	   int ret = 0;
	   for (int j = 1; j < i; j++) if(a[j].t > a[i].s && fag[j]) ret++;
	   if(ret < cnt_1) fag[i] = 1, res_1++;
	 }
	 memset(fag, 0, sizeof fag);
	 for (int i = 1; i <= m_2; i++) {
   	   int ret = 0;
	   for (int j = 1; j < i; j++) if(b[j].t > b[i].s && fag[j]) ret++;
	   if(ret < cnt_2) res_2++, fag[i] = 1;
	 }
	 Ans = max(Ans, res_1 + res_2);
   }
   cout<<Ans;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
