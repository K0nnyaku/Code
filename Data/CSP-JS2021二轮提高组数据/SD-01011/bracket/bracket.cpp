#include<bits/stdc++.h>
#define ll long long
#define fint int
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
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
int n, k, dp[503][502], sum[maxn];
char s[maxn], a[maxn];
int qku(int a, int b){
	fint sm = a + b; if(sm > mod)sm -= mod;
	return sm;
}
signed main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k;
	cin >> a + 1;
	if(a[1] == '*' || a[1] == ')' || a[n] == '*' || a[n] == '('){
		puts("0");
		fclose(stdin);
    	fclose(stdout);
    	return 0;
	}
	for(fint i = 1; i <= n; i++){
		dp[i][i - 1] = 1;
		sum[i] = sum[i - 1] + (a[i] == ')' || a[i] == '(');
	}
	for(fint i = n; i >= 1; i--){
		for(fint j = i - 1; j <= n; j++){
			for(fint l = i + 1; l + 1 < j; l++){
				if(!dp[i][l])continue;
				dp[i][j] = qku(dp[i][j], (dp[i][l] * dp[l + 1][j] % mod));
				for(fint w = l + 1; w + 1 < j && w - l <= k; w++){
					if(a[w] == '(' || a[w] == ')')break;
					dp[i][j] = qku(dp[i][l] * dp[w + 1][j] % mod, dp[i][j]);
				}
			}
			if(i >= j)continue;
			if((a[i] == '(' || a[i] == '?') && (a[j] == ')' || a[j] == '?')){
		    	dp[i][j] = qku(dp[i + 1][j - 1], dp[i][j]);
			    fint q1 = i + 1, q2 = j - 1;
			    if(sum[q2] - sum[q1 - 1] == 0)dp[i][j]++;
			    for(fint l = q1 + 1; l < q2; l++){
			    	if(sum[q2] - sum[l] == 0 && q2 - l - 1 <= k){
			    		dp[i][j] = qku(dp[i][j], dp[q1][l]);
					}
					if(sum[l] - sum[q1 - 1] == 0 && l - q1 - 1 <= k){
						dp[i][j] = qku(dp[i][j], dp[l][q2]);
					}
				}
			}
			//cout << i << " " << j << " : " << dp[i][j] << "\n";
		}
	}
	cout << dp[1][n] << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
