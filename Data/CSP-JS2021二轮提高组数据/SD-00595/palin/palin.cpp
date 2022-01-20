#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rp(i, a, b) for(int i = (a); i <= (b); i++)

const int N = 5e5 + 10;

int n, flag;
int a[N], b[N], ans[N];
int al, ar, bc, ansc;

void check() {
	int inflag = 0;
	rp(i, 1, 2 * n) if(b[i] != b[2 * n + 1 - i]) {inflag = 1; break;}
	if(!inflag) {
		flag = 1;
		rp(i, 1, 2 * n) cout << (ans[i] == 0 ? 'L' : 'R');
		cout << endl;
	}
}

void work(int x) {
	//¼Ó¸ö¼ôÖ¦ --->
	if(flag) return;
	if(x > 2 * n) {
		check();
		return;
	}
	if(x > (n + 1)) {
		if(b[2 * n - (x - 1) + 1] != b[x - 1]) return;
	}
//	int re = ans[al];
	b[++bc] = a[al++];
	ans[++ansc] = 0;
	work(x + 1);
	al -= 1; bc -= 1; ansc -= 1;
	
	b[++bc] = a[ar--];
	ans[++ansc] = 1;
	work(x + 1);
	ar += 1; bc -= 1; ansc -= 1;
}

int main ()
{
	freopen("palin.in","r",stdin); freopen("palin.out","w",stdout);
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		flag = bc = ansc = 0;
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b)); memset(ans, 0, sizeof(ans));
		cin >> n;
		rp(i, 1, 2 * n) {int ls; cin >> ls; a[i] = ls;}
		al = 1, ar = 2 * n;
		work(1);
		if(!flag) cout << -1 << endl;
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

1
20
5 20 6 12 13 18 9 17 2 7 7 18 1 11 10 15 4 6 17 19 14 10 14 13 1 16 8 3 12 8 19 20 4 16 5 3 9 2 15 11
*/ 
