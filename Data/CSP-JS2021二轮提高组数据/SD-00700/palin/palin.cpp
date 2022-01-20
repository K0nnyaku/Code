#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
const int N = 5e5+100;
//===============================================
int T, n;
int a[N << 1], b[N << 1];
int st[N << 1];
int ans[N << 1];
//===============================================
int read() {
	int s = 0, f = 0;char ch = getchar();
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}
bool Check_() {
  for (int i = 1 ; i <= n; ++i) {
    if(b[i] != b[2 * n - i + 1]) return false;
  }
//  for (int i = 1 ; i <= 2 * n; ++i)
//   cout << b[i] <<" ";puts("");
  return true;
}
ll cnt_;
void dfs(int Step, int head, int tail) {
//  puts("LKP AK IOI");
   Step++;
  if(head > tail) {
//    for (int i = 1 ; i <= 2 * n; ++i) 
//      cout << b[i] <<" ";
//    puts("");
    if(Check_()) {
      for (int i = 1 ; i <= 2 * n; ++i)  {
        if(ans[i] >= st[i]) ans[i] = st[i];
        else return ;
      }
//      for (int i = 1; i <= 2 * n; ++i) 
//        cout << ans[i] <<" ";
    }
    return;
  }
  for (int i = 0; i <= 1; ++i) {
    st[Step] = i;
    if(i == 0) b[Step] = a[head], head++;
    if(i == 1) b[Step] = a[tail], tail--;
    dfs(Step, head, tail);
    st[Step] = 0, b[Step] = 0;
    if(i == 0) head--;
    if(i == 1) tail++;
  }
}

//===============================================
int main() {
	freopen("palin.in","r", stdin);
	freopen("palin.out","w",stdout);
  T = read();
  while(T--) {
    n = read();
    
    for (int i = 1; i <= (n << 1); ++i) 
    a[i] = read(), ans[i] = 2;
    int head = 1, tail = (n << 1);
    int cnt = 0;
    bool flag = true;
    for(int i = 1 ;i <= n ;++i) {
      if(a[i] == a[2 * n - i + 1]) cnt++;
    } 
    if(cnt == n) {
      puts("0");
      continue;
    } 
    dfs(0, 1, 2 * n);
    int temp = 0;
    for (int i = 1; i <= 2 * n; ++i)  
      temp += ans[i];
    if(temp >= 2 * n) cout <<"-1";
    else {
      for (int i = 1;i <= 2 * n; ++i) {
        cout << (ans[i] == 0 ? 'L' : 'R');
      }
    }
    puts("");
    
  }
	fclose(stdin), fclose(stdout);
	return 0;
}
/*
2 
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
