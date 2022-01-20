#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<iostream>
#include<algorithm>      
#define inf 0x3f3f3f3f
using namespace std;
 
const int maxn = 1e7 + 10;
const int MAXN = 2e3 + 32;

int n, m1, m2;	
int ans = 0, ans_1 = 0, ans_2 = 0;

struct node{
	int Go,Out,t;
}a[maxn << 1], b[maxn << 1];

bool vis_1[maxn], vis_2[maxn];

bool cmp(node a, node b) {
	return a.Go < b.Go;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> n >> m1 >> m2;
	for(int i = 1; i <= m1; i++) {
		cin >> a[i].Go >> a[i].Out;
		a[i].t = a[i].Out - a[i].Go;
	}
	for(int i = 1; i <= m2; i++) {
		cin >> b[i].Go >> b[i].Out;
		b[i].t = b[i].Out - b[i].Go;
	}
	if(n >= m1 +m2) { 
		cout << m1 + m2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a + 1, a + m1 + 1, cmp);
	sort(b + 1, b + m2 + 1, cmp);
	for(int i = 1; i <= m1; i++) {
		if(vis_1[a[i].Go] == false) ans_1++;
		for(int j = a[i].Go; j < a[i].Out; j++) {
			vis_1[j] = true;
		}
	}
	for(int i = 1; i <= m2; i++) {
		if(vis_2[b[i].Go] == false) ans_2++;
		for(int j = b[i].Go; j < b[i].Out; j++) {
			vis_2[j] = true;
		}
	}
	ans = max(ans_1, ans_2);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}	
