#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 500010;
int a[N];
int b[N];
int T, n;

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		for(int i = 1; i <= n; i ++ ) cin >> a[i];
		
		for (int i = 1; i <= n; i ++ )
			cout << "L";
			
		cout << endl;
	}
	
	return 0;
}
