#include<cstdio>
#include<queue>
#include<algorithm>

const int N = 100005;
int n, m1, m2, ans;
int a1[N], b1[N], a2[N], b2[N];
int num;
struct fly {
	int a, b;
}fl1[N], fl2[N];
struct node {
	int l, r;
	bool operator <(const node &x) const {
		return x.r > r;
	}
};
std::priority_queue<node> l1, l2; 

bool cmp(const fly x, const fly y) {
	return x.a < y.a;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; ++i) scanf("%d%d", &fl1[i].a, &fl1[i].b);
	for(int i = 1; i <= m2; ++i) scanf("%d%d", &fl2[i].a, &fl2[i].b);
	std::sort(fl1 + 1, fl1 + m1 + 1, cmp);
	std::sort(fl2 + 1, fl2 + m2 + 1, cmp);
	num = n;
	while(num >= 0) {
		int t1 = num, t2 = n - num, tsum = 0;;
		while(!l1.empty()) l1.pop();
		while(!l2.empty()) l2.pop();
		for(int i = 1; i <= m1; ++i) {
			while(!l1.empty()) {
				if(l1.top().r > -fl1[i].a) {
					l1.pop();
					t1++;
				} else break;
			}
			if(t1) {
				t1--;
				l1.push((node){fl1[i].a, -fl1[i].b});
				tsum++;
			}
		}
		for(int i = 1; i <= m2; ++i) {
			while(!l2.empty()) {
				if(l2.top().r > -fl2[i].a) {
					l2.pop();
					t2++;
				} else break;
			}
			if(t2) {
				t2--;
				l2.push((node){fl2[i].a, -fl2[i].b});
				tsum++;
			}
		}
		if(tsum > ans) ans = tsum;
		num--;
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
