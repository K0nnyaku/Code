#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	for(int i = 1; i <= 12; i++) 
		printf("i = %d, f = %lf\n", i, pow(2, i) - 1);

	return 0;
}
