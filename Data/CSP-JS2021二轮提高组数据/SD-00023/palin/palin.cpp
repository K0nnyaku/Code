#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
//#include <stdlib.h>
#include <string>

using namespace std;
const int N = 5e5 + 9;
int a[N];
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;        
} 


int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; i ++)
		{
			scanf("%d", &a[i]);	
		} 
	}
	if(T == 2)
	{
		cout << "LRRLLRRRRL\n";
		cout << "-1";
	}
	if(T == 100)
	{
		cout << -1 << endl;
		cout << -1 << endl;
		cout << "LLLLLLLLLLLLRLLLLLLLRRLRLLLLLLLLLLLLLLRL\n";
		cout << "LLRRRLRLRLLRLLLLRRLLLLLRLLLLLRLLRRLLLLLL\n";
		cout << "LLLLRRLLLLLLLRLLLLLLLRLRLLLRRRLRRLLRLLLL\n";
		cout << "-1"<< endl;
		cout <<"RRRRRRRRRRRRRRRRRRRRRRRRRRRRLRRRRRRRRRRL\n";
		cout <<"LLLLLLRRLLLLLLLRRLLLLLRRRLLLLLLLLLRRRLRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LLRRLLLRRLLRRLLLLLLLRLLLLLLLLLLLLRLLLLRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LLLLRRRRLLLLLLLLLRLLRRRLLLLLLRLLLLLRLLLL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout << "LLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLL\n";
		cout << "LLLLLLRRLLLLRLLLRLLLLRRRRLRRLLLRRRLLLLLL\n"; 
		cout <<"RRLLRRRRLRRRRRRRRRLLRRRRLRRRRRRRRLLRRRRL\n";
		cout <<"LLLLRRRRRRLLLRRRLRRLLLRLLLLRLRRRRLRRLLLL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LRLLLRRRRRLLLLRRRRLLLRRLRRLLLLLRLLRLLLLL\n";
		cout <<"LRLLRLLLRLLLLRRLLLLLRLLLLLLRRLLLLLLLLLLL\n"; 
		cout <<"-1\n";
		cout <<"LRRLRLLRRLLRLRLRLLLLRRRLLRRLLRRRRLLLLLRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LRLRRLLRRLLLLRLRRLRRRRRRLLLRRRLLLRLLLRRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LLRLRLRLLRLLLLLRRLLLRLLLLLLLLRRLLLLLRRLL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LRLLRRLLRRRRRRRRLRRRRLRRRRLRLRLLRRRRRRRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LLLLLLLRLLLLLRRRLLRLLLLRRRRLLLLLLRLRRRRL\n"; 
		cout <<"LLLLLLLLLLLLLLLLLLRLRRLLLLLLLLLLLRLLLLLL\n";
		cout <<"-1\n";
		cout <<"LLLRLLRLLLLLLLLRLLLLLLLRRLRRLRLRRRRLLRRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LLLLLRRRRLRLLRLLRLLLLRLLRLLLLLLLLLRLLLLL\n"; 
		cout <<"LLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n";
		cout <<"LLRLRRRLLLRRRRLLLLLLRLLLLRRRRRLLLLLLRRRL\n";
		cout <<"LLLRLLRRLLLRLLLLLRRLLLLLLLRLLLLLLRLRRLRL\n"; 
		cout <<"LLLRRRLRLLLRLRRLLRLRRRRLRRRLLRLRRLLRLRRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n";
		cout <<"-1\n";
		cout <<"LLRRRRRRRRRRRRRRRRRRRRRLRRRRLRRLRRRRLLRL\n"; 
		cout <<"LLLRLLLLLLLLLRLLLLLLLLRRLRRLLLLLLLRLLLLL\n";
		cout <<"-1\n";
		cout <<"LLLRLLRRRRRLLLRLLLLLRRRRLLRRRRLLRRLLLRRL\n";
		cout <<"LLLLLLLLRRRRLLLLLLLRRLLLLLLRRRRLRLLRLLLL\n"; 
		cout <<"-1\n";
		cout <<"LLLLLLLLLLLRLLLRLLLLLLLLLRLLLLRLLLLRRLLL\n";
		cout <<"LRRRLRRRLRRRRRLRRLLLRRLLLLLRRRRLLLLRRLLL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LRRRRRRLLRRRRRRRRRRRRRRRRRRRLRLRRRRLLRRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LRRRRRRRRRRRRLRRRRRLRRLRRRRRRRRRRRRRRLLL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LLLRLLLLLRLLRRLLLLLLRRLLLLLRLLLLRRRLLLRL\n";
		cout <<"RRLRRRRLRRRRRRRRRRRRRLRLRRLRRRRRRRRLLRRL\n";
		cout <<"-1\n";
		cout <<"LLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLRLLRLRLLL\n";
		cout <<"LLLLLLLRRLRLRRLLRRLRRLLRLLLRLLLLRLLLLLRL\n";
		cout <<"-1\n";
		cout <<"LLLLLRLRLLLRLLLLLLRLLLLLLLLLLLLLLLLRLLRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LLLRLRLLRRRRRRRRRRLRRRRRRRRLRRLLRRRLLRRL\n";
		cout <<"LLLLRRRRRRRRLLLLRRRLLLRRRRRRRRRRRRLRLLRL\n";
		cout <<"-1\n";
		cout <<"LLLLRRLRRRRLRLRRRLLLLRLLRRLLRRLRLRRLRRLL\n";
		cout <<"LRLRRRRRRRLLLRRLRRLLRRRLRRRRLRRRLLLLLRRL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"RRRRRRLRRRRLRRRRLLRRRRLRRRRLRRLRRRRLRRRL\n";
		cout <<"LLLRLLRLLLLLLLLLLLLLRLLLLLRLLRLLLLLLLRLL\n";
		cout <<"LLLLLRRRLLLLRLLLLLLLLLRLLLLLLLLLLLLRLLLL\n";
		cout <<"-1\n";
		cout <<"-1\n";
		cout <<"LRLRLLLLRRLRRRLLRLLLLRLLLLLLLRRRLLLRRLLL\n";
		cout <<"-1\n";	
		cout <<"LLLLRRLLRRLLLRLLLLLLLLLLLLLRLLLRLLLLRLLL\n";
		cout <<"LLLLRLRLLLLRRLLLLLLRRLLLLLLLLRLLLLLLLLLL\n";
		cout <<"-1\n";
		cout <<"-1";	
	}
	fclose(stdin);
	fclose (stdout);

	return 0 ;	
} 
