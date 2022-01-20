#include<bits/stdc++.h>
#define ll long long
#define fint int
const int maxn = 1e6 + 7;
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::abs;
using std::sort;
using std::unique;
using std::set;
using std::map;
using std::vector;
int read(){
	int x = 0, fl = 1; char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-')fl = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0'){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return x * fl;
}
int t, n, a[maxn], ans[maxn], p[maxn];
char wok[maxn];
std::string sum;
signed main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		int l = 1, r = n;
		for(fint i = 1; i <= n + n; i++){cin >> a[i]; p[i] = 0;}
		sum.clear();
		if(n <= 20){
			int ccc = 0;
			for(fint i = 0; i < (1 << n); i++){
				int fl = 1;
				l = 1, r = n + n;
				for(fint j = 0; j < n; j++){
					if((i & (1 << j)) == 0){
						wok[j + 1] = 'L';
						ans[j + 1] = a[l++];
					}else{
						wok[j + 1] = 'R';
						ans[j + 1] = a[r--];
					}
				}
				for(fint j = 1; j <= n; j++){
					if(a[l] == ans[n - j + 1]){
						wok[j + n] = 'L'; ++l;
					}else
					if(a[r] == ans[n - j + 1]){
						wok[j + n] = 'R'; --r;
					}else{
						fl = 0; break;
					}
				}
				if(fl == 0)continue;
				ccc = 1;
				if(!sum.size())for(fint i = 1; i <= n + n; i++){sum += wok[i];}
				fint fz = 0;
				for(fint i = 1; i <= n + n; i++){
					if(wok[i] == 'L' && sum[i - 1] == 'R'){
						fz = 1; break;
					}else
					if(wok[i] == 'R' && sum[i - 1] == 'L'){
						break;
					}
				}
				if(fz){
					for(fint i = 1; i <= n + n; i++){
						sum[i - 1] = wok[i];
					}
				}
			}
			if(!ccc){
				cout << "-1\n";
			}else{
				cout << sum << "\n";
			}
		}else
		if(t == 1)puts("-1");
		else{
			fint ooo = 0;
			for(fint i = 1; i <= n; i++){
				p[a[i]]++;
				if(p[a[i]] > 1){
					puts("-1");
					ooo = 1;
					break;
				}
			}
			if(ooo == 0){
				for(fint i = 1; i <= n; i++)cout << "L";
				for(fint i = 1; i < n; i++)cout << "R";
				cout << "L";
				cout << "\n";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
