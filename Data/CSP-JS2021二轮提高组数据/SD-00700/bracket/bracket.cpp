#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int N = 600;
//===============================================

int n, k;
char s[N];
int cntl = 0, cntr = 0;
//===============================================
int read() {
	int s = 0, f = 0;char ch = getchar();
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}
ll q_pow(ll x, ll y) {
//  cout << y <<"\n";
//  system("pause");
  ll ans = 1ll;
  while(y) {
//    puts("LKP Ak IOI");
    if(y & 1) ans = ans * x  % mod;
    x = x * x % mod;
    y >>=1;
  }
  return ans % mod;
}
//===============================================
int main() {
	freopen("bracket.in","r", stdin);
	freopen("bracket.out","w",stdout);
  n = read(), k = read();
  for (int i = 1; i <= n; ++i) cin>>s[i];
  for (int i = 1; i <= n; ++i) {
   cntl += (s[i] == '('), cntr += (s[i] == ')') ;
  }
  int temp = n - cntl - cntr - abs(cntl - cntr);
  temp -= k;
  cout << q_pow(2ll, temp);
	fclose(stdin), fclose(stdout);
	return 0;
}
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/

