#include <cstdio>
#include <queue>
#include <algorithm>

const int Maxn = 1e5 + 5;

struct pt {
	int st, ed;
} a[Maxn];

std::priority_queue<int> hp;
int sz = 0;

int ca[Maxn], cb[Maxn];

int n, m_1, m_2;

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m_1, &m_2);
	for(int i = 1; i <= m_1; ++i) scanf("%d%d", &a[i].st, &a[i].ed);
	std::sort(a + 1, a + m_1 + 1, [](pt x, pt y){
		return x.st < y.st;
	});
	for(int k = 0; k <= n; ++k) {
		while(sz) hp.pop(), sz--;
		for(int i = 1; i <= m_1; ++i) {
			while(sz && ((-hp.top()) < a[i].st)) hp.pop(), sz--;
			if(sz < k) hp.push(-a[i].ed), sz++, ++ca[k]; //printf("after plane [%d %d] there are %d planes\n", a[i].st, a[i].ed, sz);
		}
	}
	
	while(sz) hp.pop(), sz--;
	for(int i = 1; i <= m_2; ++i) scanf("%d%d", &a[i].st, &a[i].ed);
	std::sort(a + 1, a + m_2 + 1, [](pt x, pt y) {
		return x.st < y.st;
	});
	
	for(int k = 0; k <= n; ++k) {
		while(sz) hp.pop(), sz--;
		for(int i = 1; i <= m_2; ++i) {
			while(sz && ((-hp.top()) < a[i].st)) hp.pop(), sz--;
			if(sz < k) hp.push(-a[i].ed), sz++, ++cb[k]; //printf("after plane [%d %d] there are %d planes\n", a[i].st, a[i].ed, sz);
		}
	}
	//for(int i = 1; i <= n; ++i) ca[i] += ca[i - 1], cb[i] += cb[i - 1];
	int mx_ans = 0;
	for(int i = 0; i <= n; ++i) mx_ans = std::max(mx_ans, ca[i] + cb[n - i])/*, printf("%d %d\n", ca[i], cb[i])*/;
	printf("%d", mx_ans);
	
	fclose(stdin); fclose(stdout);
	return 0;
}
