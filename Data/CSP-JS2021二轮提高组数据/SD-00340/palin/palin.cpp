#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long
using namespace std;

const int N = 100;

int t,a[N],b[N],cnt;
string ans;

signed main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&t);
	while(t --) {
		ans = "";
		int n;
		scanf("%lld",&n);
		for(int i=1 ; i<=n*2 ; i++) scanf("%lld",&a[i]);
		for(int s=0 ; s<pow(2,n*2) ; s++) {
			int p1 = 1,p2 = n * 2,cnt = 0;
			memset(b,0,sizeof b);
			string tmp = "";
			for(int i=0 ; i<2*n ; i++) {
				cnt ++;
				if((s >> i) & 1) {
					tmp += "L";
					b[cnt] = a[p1];
					p1 ++;
				}
				else {
					tmp += "R";
					b[cnt] = a[p2];
					p2 --;
				}
			}
			bool flag = 1;
			for(int i=1 ; i<=n ; i++) {
				if(b[i] != b[2 * n - i + 1]) {
					flag = 0;
					break;
				}
			}
			if(flag) {
				if(ans.size()) ans = min(ans,tmp);
				else ans = tmp;
			}
		}
		if(ans.size()) cout << ans << endl;
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
