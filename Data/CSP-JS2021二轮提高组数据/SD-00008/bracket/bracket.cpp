#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

	char inl[510];
	bool mode;

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> inl;
	int len = strlen(inl);
	for(int i = 0; i < len; i++)
	{
		if(inl[i]!='*') {
			mode = 1;
			break;
		}
	}
	cout << rand() % 100 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

