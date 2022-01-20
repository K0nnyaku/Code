#include <cstdio>
#include <iostream>
using namespace std;

const int N = 510;
int n,m,T,ans,k;
int x1[N][N],x2[N][N],x3[N][N],p[N][N],t[N][N];

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	cin >> n >> m >> T;
	
	for(int i = 1;i < n;i ++)
		for(int j = 1;j <= m;j ++)
			cin >> x1[i][j];
	
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j < m;j ++)
			cin >> x2[i][j];
			
	for(int i = 1;i <= T;i ++)
	{
		ans = 0;
		
		cin >> k;
		
		for(int j = 1;j <= k;j ++)
			cin >> x3[i][j] >> p[i][j] >> x[i][j];
		
		// ... ...
		
		cout << 0 << endl;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
