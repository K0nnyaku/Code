#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 505;
const int mod = 1e9 + 7; 

int n;
int k;

int re() {
	int x = 0, f = 1;
	char ch = getchar();

	while (ch < '0'||ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}

	while (ch <= '9'&&ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}

	return x * f;
}

char a[N];
char dx[3] = {'*', '(', ')'};

ll ans;
ll num;

void check() {
	bool flag = 0;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;
	
	if(a[0] == '*'||a[n - 1] == '*') {
		flag = 1;
	}
	else
	for(int i = 0; i < n; i++) {
		
		if(sum3 > k) {
			flag = 1;
			break;
		}
		else if(a[i] == '(')
			sum1++, sum3 = 0;
		else if(a[i] == ')')
			sum2++, sum3 = 0;
		else if(a[i] == '*')
			sum3++;
		
		if(sum2 > sum1) {
			flag = 1;
			break ;
		}
	}
	
	if(flag)
		return ;
	
	if(sum1 == sum2) {
		ans ++;
//		printf("%s\n", a);
		return;
	}
}

void dfs(int pos) {
	if(pos == n) {
		check();
		return ;
	}
	
	if(a[pos] == '*')
		num ++ ;
	else
		num = 0;
	
	if(a[pos] != '?') {
		dfs(pos + 1);
		return ;
	}
	
	if(num < k) {
		a[pos] = '*';
		dfs(pos + 1);
		num--;
		a[pos] = '?'; 
	}
		
	for(int i = 1; i < 3; i++) {
		a[pos] = dx[i];
		num = 0;
		dfs(pos + 1);
		a[pos] = '?'; 
	} 
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = re(); k = re();
	scanf("%s", a);
	dfs(0);
	printf("%d\n", ans);
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

