#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

const int N = 509;

ll n, k, zuo, xhs, ans, len;
string s;
ll vis[4][N];

void doit(ll x){
	if((s[x] == '*' && x == len) || x > len){
		return;
	}
	if(s[x] == '?'){
		if(!vis[1][x]){
			s[x] = '(';
			vis[1][x] = 1;
			doit(x + 1);
		}
		if(vis[1][x] && !vis[2][x]){
			s[x] = ')';
			vis[2][x] = 1;
			doit(x + 1);
		}
		if(vis[1][x] && vis[2][x] && !vis[3][x]){
			s[x] = '*';
			vis[3][x] = 1;
			doit(x + 1);
		}
	}
	if(x == len){
		for(ll i = 1; i <= n; i++){
			if(s[i] == '('){
				zuo++;
			} 
			if(s[i] == ')'){
				zuo--;
			}
			if(zuo < 0){
				return;
			}
		}
		if(zuo != 0){
			return;
		}
		ans++;
	}
	doit(x + 1);
}

int main()
{
//	freopen("bracket", "r", stdin);
//	freopen("bracket", "w", stdout);
	cin >> n >> k;
	if(n <= 1){
		cout << 0;
		return 0;
	}
	for(ll i = 1; i <= n; i++){
		cin >> s[i];
	}
	len = sizeof(s) - 1;
	doit(1);
	for(ll i = 1; i <= n; i++)
	{
		cout << s[i];
	}
	cout << ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

/*
7 3
(*??*??
*/
