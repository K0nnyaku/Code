#include<bits/stdc++.h>
#define ll long long

using namespace std;

inline int read() {
	int x = 0, f = 1; char s = getchar();
	while (s < '0' || s > '9') {if (s == '-') f = -1; s = getchar();}
	while (s <= '9' && s >= '0') {x = x * 10 + s - '0'; s = getchar();}
	return x * f;
}

inline void print(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
	return;
}

int n, m1, m2;
int book1[100010];
int book2[100010];
struct w{
	int st, en;
}a[100010], b[100010];

int cnt1, cnt2, ans = -1; 
bool cmp1(w s, w e) {
	return s.st < e.st;
}

priority_queue <int> q1;
priority_queue <int> q2;

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
    n = read(), m1 = read(), m2 = read();
    for (int i = 1; i <= m1; ++i)  a[i].st = read(), a[i].en = read();
    for (int i = 1; i <= m2; ++i)  b[i].st = read(), b[i].en = read();
    sort(a + 1, a + m1 + 1, cmp1);
    sort(b + 1, b + m2 + 1, cmp1);
    q1.push(-a[1].en);
    q2.push(-b[1].en);
    cnt1 = 1, cnt2 = 1;
    for (int i = 2; i <= m1; ++i) {
    	if (a[i].st >= -q1.top()) {
        	q1.push(-a[i].en);
			q1.pop();
		}
		else {
			cnt1++;
			q1.push(-a[i].en);
		} 
	}
	for (int i = 2; i <= m2; ++i) {
		if (b[i].st >= -q2.top()) {
			q2.push(-b[i].en);
			q2.pop();
		} 
		else {
			cnt2++;
			q2.push(-b[i].en);
		}
	}
	if (cnt1 + cnt2 <= n) {
		print(m1 + m2);
		return 0; 
	}
	for (int i = 0; i <= n; ++i) {
		while (!q1.empty())	q1.pop();
		while (!q2.empty())	q2.pop();
		int ans1 = 0, ans2 = 0;
		if (i != 0) {
			ans1 = 1;
			int cn1 = 1;
			q1.push(-a[1].en);
			for (int j = 2; j <= m1; ++j) {
			   if (a[j].st >= -q1.top()) {
			   	    q1.pop();
			   	    q1.push(-a[j].en);
					ans1++;
			   }
			   else if (cn1 >= i) continue;
			   else {
				   cn1++;
				   q1.push(-a[j].en);
				   ans1++;
			    } 
		    }
		}
		if (n - i != 0) {
			int cn2 = 1;
			ans2 = 1;
			q2.push(-b[1].en);
			for (int j = 2; j <= m2; ++j) {
		        if (b[j].st >= -q2.top()) {
		        	q2.pop(); 
		        	q2.push(-b[j].en);
					ans2++;
				}
			    else if (cn2 >= n - i) continue;
			    else {
				   cn2++;
				   q2.push(-b[j].en);
				   ans2++;
			   }
		    }
	    }	
		ans = max(ans, ans1 + ans2);
	}
	print(ans);
	fclose(stdin);
	fclose(stdin);
	return 0;
}

