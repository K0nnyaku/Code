#include<bits/stdc++.h>
using namespace std;
int t;
const int N = 5e5 + 10;
int a[N] , b[N];
char op[N];int n;
queue<string>q;
bool check(string s) {		
	int l = 1 , r = 2 *n;
	int cnt = 0;
	for(int i = 0; i <= 2 * n - 1; i++)
		if(s[i] == 'L')b[++cnt] = a[l] , l++;
		else b[++cnt] = a[r] , r--;
	for(int i = 1; i <= n; i++) {
		if(b[i] != b[2 * n + 1 - i])return false;
	}
	return true;
}
void bfs() {
while(!q.empty())q.pop();
	q.push("L");
	q.push("R"); 
	
	while(!q.empty()) {
		string s = q.front();q.pop();
	//	if(s == "LRRLLRRRRL")return;
		if(s.size() == 2 * n) {
			if(check(s)) {
				cout << s << endl;
				return;
			}	
			continue;		
		}
	//	printf("%d\n" , s.size());
		string s1 = s + "L";
		string s2 = s + "R";
		q.push(s1);
		q.push(s2);
	}
	puts("-1");
}
void work() {
	scanf("%d" , &n);
	for(int i = 1; i <= 2*n; i++) {
		scanf("%d" , &a[i]);
	}	
	bfs();
	
}
int main() {
	freopen("palin.in" , "r" , stdin);
	freopen("palin.out", "w" , stdout);
	scanf("%d" , &t);
	while(t--) {
		work();
	}
	return 0;
} 
