#include <iostream>

using std::cin;
using std::cout;

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.ans", "w", stdout);
	
	int n, m, T;
	cin >> n >> m >> T;
	for (int i = 0; i < T; ++i) {
		cout << rand() << std::endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
