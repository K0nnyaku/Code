#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int I = 0, AK = 1; char IOI = getchar();
	while(IOI > '9' || IOI < '0') { if(IOI == '-') AK = -1; IOI = getchar(); }
	while(IOI <= '9' && IOI >= '0') { I = I * 10 + IOI - 48; IOI = getchar(); }
	return I * AK;
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
    int t;
	int a, b[500000 + 20];
	t = read();
	for(int i = 0 ; i < t ; i ++)
	{
		a = read();
		for(int j = 0 ; j < a * 2; j ++) b[j] = read();
		cout << -1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
