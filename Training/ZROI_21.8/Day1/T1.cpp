#include<cstdio>
#include<algorithm>
using namespace std;

int BkF[50], BkB[50];
int f, b;
int main() {
	freopen("In.in", "r", stdin);

	for(int i = 1; i <= 5; i++) {
		int x;
		scanf("%d", &x);
		BkF[x]++;
	}
	for(int j = 1; j <= 2; j++) {
		int x;
		scanf("%d", &x);
		BkB[x]++;
	}

	for(int i = 1; i <= 5; i++) {
		int x;
		scanf("%d", &x);
		if(BkF[x]) f++;
	}
	for(int i = 1; i <= 2; i++) {
		int x;
		scanf("%d", &x);
		if(BkB[x]) b++;
	}

	int pr = 0;
	if(f == 5 && b == 2) pr = 5000000;
	else if(f == 5 && b == 1) pr = 250000;
	else if(f == 5 && b == 0 || f == 4 && b == 2) pr = 3000;
	else if(f == 4 && b == 1 || f == 3 && b == 2) pr = 200;
	else if(f == 3 && b == 1 || f == 2 && b == 2 || f == 4 && b == 0) pr = 10;
	else if(f == 3 && b == 0 || f == 1 && b == 2 || f == 2 && b == 1 || f == 0 && b == 2) pr = 5;

	printf("%d", pr);

	return 0;
}
