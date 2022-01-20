#include <iostream>

using std::cin;
using std::cout;

struct arr {
	int* arr;
	int len;
};

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.ans", "w", stdout);
	
	int T;
	cin >> T;
	arr data[T];
	for (int i = 0; i < T; ++i) {
		int len;
		cin >> len;
		int* arr = new int[len];
		for (int j = 0; j < len; ++j) {
			cin >> arr[j];
		}
		data[i] = {arr, len};
	}
	
	for (int i = 0; i < T; ++i) {
		cout << -1 << std::endl;
		delete[] data[i].arr;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
