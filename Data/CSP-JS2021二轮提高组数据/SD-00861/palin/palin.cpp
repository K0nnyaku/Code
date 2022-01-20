#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#define SIZE 500005
using namespace std;

int t, n, a[SIZE];
vector <int> c,b;
deque <int> v;

bool dfs(int x) {
	if(x == 2 * n + 1) {
		for(int i = 0; i < n; ++i)
			if(b[i] != b[2 * n - i - 1])
			 	return 0;
		return 1;
	}
	c.push_back(1);
	b.push_back(v.front());
	v.pop_front();
	if(dfs(x + 1)) return 1;
	c.pop_back();
	v.push_front(b.back());
	b.pop_back();
	c.push_back(2);
	b.push_back(v.back());
	v.pop_back(); 
	if(dfs(x + 1)) return 1;
	c.pop_back();
	v.push_back(b.back());
	b.pop_back();
	return 0;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		while(c.size()) c.pop_back();
		while(b.size()) b.pop_back();
		while(v.size()) v.pop_back();
		scanf("%d",&n);
		for(int i = 1; i <= n * 2; ++i)
			scanf("%d",&a[i]), v.push_back(a[i]);
		if(dfs(1)) {
			for(int i = 0; i < 2 * n; ++i)
				printf("%c",c[i] == 1 ? 'L' : 'R');
			puts("");
		}
		else puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
