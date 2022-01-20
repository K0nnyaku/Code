#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

struct Plane {
	int arrive;
	int leave; 
};

int lqLeave[100000];
inline int calc(int lqCount, Plane* planes, int planeCount) {
	memset(lqLeave, 0, sizeof(int) * lqCount);
	int result = 0;
	for (int i = 0; i < planeCount; ++i) {
		for (int j = 0; j < lqCount; ++j) {
			if (!lqLeave[j] || lqLeave[j] <= planes[i].arrive) {
				lqLeave[j] = planes[i].leave;
				++result;
				break; 
			}
		}
	}
	return result;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.ans", "w", stdout);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	Plane planes1[m1];
	Plane planes2[m2];
	for (int i = 0; i < m1; ++i) {
		int a, l;
		cin >> a >> l;
		planes1[i] = {a, l};
	}
	for (int i = 0; i < m2; ++i) {
		int a, l;
		cin >> a >> l;
		planes2[i] = {a, l};
	}
	
	int max = calc(n, planes2, m2);
	for (int i = 1; i < n; ++i) {
		int total = calc(i, planes1, m1) + calc(n - i, planes2, m2);
		if (total > max) {
			max = total;
		}
	}
	
	int total = calc(n, planes1, m1);
	if (total > max) {
		max = total;
	}
	
	cout << max;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
