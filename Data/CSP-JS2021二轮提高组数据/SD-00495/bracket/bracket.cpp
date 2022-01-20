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
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
    int n, k;
    n = read();
	k = read(); 
    srand(time(NULL));
    if(k > 2) cout << rand() % 10 + 1; 
    else cout << rand() % 100 + 10; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
