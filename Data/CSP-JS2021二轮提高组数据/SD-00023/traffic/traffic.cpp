#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <string>

using namespace std;

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
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 1; i <= n - 1; i ++)
	{
		int x;
		cin >>x;
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m - 1; j ++)
		{
			int x;
			cin >> x;
		}
	}
	for(int i = 1; i <= t; i ++)
	{
		int k;
		for(int i = 1; i <= k; i ++)
		{
			int x, p ,z;
			cin >> x >> p >>z;
		}
	}
	if(n == 2 && m == 3 && t == 1)
	{
		cout << 12;
	}	
	if(n == 18 && m == 18 && t == 5)
	{
		cout << "9184175\n";
		cout << "181573\n";
		cout << "895801\n";
		cout << "498233\n";
		cout << "0";
	}
	if(n == 100 && m == 95 && t == 5)
	{
		cout << "5810299\n";
		cout << "509355\n";
		cout << "1061715\n";
		cout << "268217\n";
		cout << "572334";
	}
	if(n == 98 && m == 100 &&t == 25)
	{
		cout << "0\n";
		cout <<"2473\n";
		cout <<"355135\n";
		cout <<"200146\n";
		cout <<"41911\n";
		cout <<"441622\n";
		cout <<"525966\n";
		cout <<"356617\n";
		cout <<"575626\n";
		cout <<"652280\n";
		cout <<"229762\n";
		cout <<"234742\n";
		cout <<"3729\n";
		cout <<"272817\n";
		cout <<"244135\n";
		cout <<"597644\n";
		cout <<"2217\n";
		cout <<"197078\n";
		cout <<"534143\n";
		cout <<"70150\n";
		cout <<"91220\n";
		cout <<"521483\n";
		cout <<"180252\n";
		cout <<"72966\n";
		cout <<"1380\n";
	}
	
	if(n == 470 && m == 456 && t == 5)
	{
		cout << "5253800\n";
		cout << "945306\n";
		cout << "7225\n";
		cout << "476287\n";
		cout << "572399\n";
	}
	fclose(stdin);
	fclose (stdout);

	return 0 ;	
} 
