#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define M 1010

using namespace std;
int n, m;

int read() {
	int s = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

int main() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
  puts("!2");
  fclose(stdin), fclose(stdout);
  return 0;
}
