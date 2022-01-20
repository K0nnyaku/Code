
#include<set>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define pt putchar(' ')
#define pn putchar('\n')
#define IT std::set <node> :: iterator 

const int A = 1e4 + 7;
const int B = 1e5 + 7;
const int C = 1e6 + 7;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

void File() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
}
void REFile() {fclose(stdin); fclose(stdout);}

template <typename T> T Pow(T x) {return x * x;}
template <typename T> T Abs(T x) {return x < 0 ? -x : x;}
template <typename T> T Min(T x, T y) {return x < y ? x : y;}
template <typename T> T Max(T x, T y) {return x > y ? x : y;}
template <typename T> void Swap(T&x, T&y) {x ^= y ^= x ^= y;}

int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + (ch ^ 48); ch = getchar();}
	return x * f;
}
void Print(int x) {if(x < 0) x = -x, putchar('-'); if(x > 9) Print(x / 10); putchar(x % 10 ^ 48);}

int n, m1, m2, ans, kcnt1, kcnt2, sum1[B], sum2[B];
struct node {
	int l, r;
	bool operator < (const node &x) const {return r > x.r;}
} a[B], b[B]; 
std::priority_queue <node> q;
std::set <node> t;
//std::priority_queue <node> q1[B];
//std::priority_queue <int> q2;

bool cmp(node x, node y) {return x.l < y.l;}
void work1() {
	for(int i = 0; i <= n; ++i)
	{
		int _sum1 = 0, _sum2 = 0;
		for(int j = 1; j <= m1; ++j)
		{
			while(!q.empty() && q.top().r < a[j].l) q.pop();
			if(q.size() < i) q.push(a[j]), ++_sum1;
		}
		while(!q.empty()) q.pop();
		for(int j = 1; j <= m2; ++j)
		{
			while(!q.empty() && q.top().r < b[j].l) q.pop();
			if(q.size() < n - i) q.push(b[j]), ++_sum2;
		}
		while(!q.empty()) q.pop();
		ans = Max(ans, _sum1 + _sum2);
	}
	Print(ans);
}

void work2() {
	for(int i = 1; i <= m1; ++i)
	{
		IT it = t.upper_bound((node){0, a[i].l});
		if(it == t.end()) sum1[++kcnt1]++, t.insert((node){kcnt1, a[i].r});
		else
		{
			int id = it -> l, r = it -> r; t.erase(*it);
			sum1[id]++; t.insert((node){id, a[i].r});
		}
	}
	t.clear();
	for(int i = 1; i <= m2; ++i)
	{
		IT it = t.upper_bound((node){0, b[i].l});
		if(it == t.end()) sum2[++kcnt2]++, t.insert((node){kcnt2, b[i].r});
		else
		{
			int id = it -> l, r = it -> r; t.erase(*it);
			sum2[id]++; t.insert((node){id, b[i].r});
		}
	}
	for(int i = 1; i <= kcnt1; ++i) sum1[i] += sum1[i - 1];
	for(int i = 1; i <= kcnt2; ++i) sum2[i] += sum2[i - 1];
	for(int i = 0; i <= Min(n, kcnt1); ++i) ans = Max(ans, sum1[i] + sum2[n - i]);
	for(int i = 0; i <= Min(n, kcnt2); ++i) ans = Max(ans, sum2[i] + sum1[n - i]);
	Print(ans);
}
			
void Main() {
	n = read(); m1 = read(); m2 = read();
	for(int i = 1; i <= m1; ++i) a[i] = (node){read(), read()};
	for(int i = 1; i <= m2; ++i) b[i] = (node){read(), read()};
	std::sort(a + 1, a + 1 + m1, cmp);
	std::sort(b + 1, b + 1 + m2, cmp);
	if(n <= 5000) work1();
	else work2();
}

int main() {File(); Main(); REFile(); return 0;}

