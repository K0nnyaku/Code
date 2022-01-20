#include<bits/stdc++.h>
using namespace std;

int T, n;
int a[200][2000];
char b[2000], ans[2000];
int c[2000];

int main()
{	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin >> T;
	for(int t=1;t<=T;++t)
	{
		int fflag = 1;
		cin >> n;
		for(int i=1;i<=2*n;++i)
		{
			cin >> a[t][i];
		}
		for(int i=0;i<=pow(2, 2*n);++i)
		{
			int k = i;
			int cnt = 0;
			for(int j=2*n-1;j>=0;j--)
			{
				int r = pow(2, j);
				if(k >= r){
					b[++cnt] = 'R';
					k -= r;
					continue;
				} 
				b[++cnt] = 'L';
			}
			int cntl = 0, cntr = 0;
			for(int j=1;j<=cnt;j++)
			{
				if(b[j] == 'L'){
					c[j] = a[t][++cntl];
				}
				else{
					c[j] = a[t][cnt-(++cntr)+1];
				}
			}
			int flag = 0;
			for(int j=1;j<=n;j++)
			{
				if(c[j] != c[cnt-j+1]){
					flag = 1;
				}
			}
			if(flag == 1) continue;
			for(int j=1;j<=cnt;j++) cout << b[j];
			cout << endl;
			fflag = 0;
			break;
		}
		if(fflag == 1) cout << "-1" <<endl;
	}
	return 0;
}
