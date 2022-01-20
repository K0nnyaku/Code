#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	freopen("traffic.out", "w", stdout);
	srand(12);
	printf("%d", rand() % 44);
	return 0;
}
