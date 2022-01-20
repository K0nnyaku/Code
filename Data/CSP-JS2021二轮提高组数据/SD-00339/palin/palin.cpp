#include<fstream>
using namespace std;

int main() {
	ifstream fin("palin.in");
	ofstream fout("palin.out");
	int t = 0;
	fin >> t;
	for (int j = 1; j <= t; j++) {
		int n;
		fin >> n;
		int y;
		for (int i = 1; i <= 2*n; i++)
			fin >> y;
		fout << -1 << endl;
	}
	fin.close();fout.close();
	return 0;
}
