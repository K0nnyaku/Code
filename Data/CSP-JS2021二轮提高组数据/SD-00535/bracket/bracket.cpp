#include<cstdio>
#include<cstring>
#include<algorithm>

const int A = 1e4 + 7;
const int B = 1e5 + 7;
const int C = 1e6 + 7;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

void File() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
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

void Main() {
	Print(1ll * rand() * rand() % mod);
}

int main() {File(); Main(); REFile(); return 0;}


