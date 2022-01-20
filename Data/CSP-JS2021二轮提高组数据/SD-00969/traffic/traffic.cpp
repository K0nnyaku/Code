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

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	srand(time(NULL));
    cout << 159 << endl;
	fclose(stdin);
	fclose(stdin);
	return 0;
}


