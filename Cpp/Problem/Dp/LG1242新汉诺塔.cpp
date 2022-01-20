#include<bits/stdc++.h>
using namespace std;
#define IOR(x, y, z) for(int x = y; x < z; x++)
#define LOR(x, y, z) for(int x = y; x > z; x--)

const int MAXN = 45 + 10;
const char CH[4] = { '0', 'A', 'B', 'C' };

long long n, ans;
int From[MAXN], To[MAXN];

void Wk(int x, int y);

int main() { /**/
//#ifdef LOCAL
//	freopen("In.in", "r", stdin);
//	freopen("Out.out", "w", stdout);
//#endif
	cin >> n;
	IOR(i, 1, 4) {
		int m, x; cin >> m;
		IOR(v, 1, m+1) cin >> x, From[x] = i;
	}
	
	IOR(i, 1, 4) {
		int m, x; cin >> m;
		IOR(v, 1, m+1) cin >> x, To[x] = i;
	}

	LOR(i, n, 0) Wk(i, To[i]);

	cout << ans;

	return 0;
} /**/

void Wk(int x, int y) {
	if(From[x] == y) return ;
	LOR(i, x-1, 0) Wk(x, 6-From[x]-y), cout << i << "\n";

	cout << "move" << x << "from" << CH[From[x]] << "to" << CH[y] << "\n";
	
	From[x] = y; ans++;
}


