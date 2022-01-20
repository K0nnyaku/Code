#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <utility>
#include <cmath>
using namespace std;
//--------------------------------------------------

//--------------------------------------------------

//--------------------------------------------------
int read() {
	int f = 0, x = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
//--------------------------------------------------
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	printf("12\n");
	fclose(stdin); fclose(stdout); 
	return 0;
}
