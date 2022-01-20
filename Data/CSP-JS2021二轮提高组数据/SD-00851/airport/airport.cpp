#include <bits/stdc++.h>
const int maxn = 2e6+5;

inline int read() {
	int x = 0,w = 1;char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') w = -1;ch = getchar();}
	while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0';ch = getchar();}
	return x * w;
}

int n,m1,m2,cnt1,cnt2,tar1,tar2,tot;
int cnt[maxn];

struct node {
	int a,b,timer;
}in[maxn],internal[maxn];

bool cmp(node a,node b) {
	return a.a < b.a;
}

void solve1() {
	for(int i = 1;i <= m1;i++) {
		for(int j = i;j <= m1;j++) {
			if(in[i].b > in[j].a) {
				tar1 = 0;
				continue;
			}
			else  
				if(tar1 >= n) continue;
				cnt1++;
				tar1++;
			}
		}
	}
//	std::cout << tar1 << "\n";
}

void solve2() {
	for(int i = 1;i <= m2;i++)
		for(int j = i;j <= m2;j++) {
			if(internal[i].b > internal[j].a) {
				tar2 = 0;
				continue;
			}
			else {
				if(tar2 >= n || tar2 >= (n -  tar1)) continue;
				cnt2++;
				tar2++;
			}
		}
//	std::cout << tar2 << "\n";
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read(),m1 = read(),m2 = read();
	for(int i = 1;i <= m1;i++) {
		in[i].a = read(),in[i].b = read();
		in[i].timer = in[i].b - in[i].a;
	}
	for(int i = 1;i <= m2;i++) {
		internal[i].a = read(),internal[i].b = read();
		internal[i].timer = internal[i].b - internal[i].a;
	}
	if(n >= m1 + m2) {
		std::cout << m1 + m2;
		return 0;
	}
	std::sort(in+1,in+m1+1,cmp);std::sort(internal+1,internal+m2+1,cmp);
	solve1();solve2();
	printf("%d",cnt1 + cnt2);
	return 0;
}

