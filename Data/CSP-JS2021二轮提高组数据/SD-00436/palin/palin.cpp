#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#define ll long long
using namespace std;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin >> T
	while(T--)
	{
		for(int i=1;i<=2*n;i++)
			cin >> a[i];
		for(int l=1,r=2*n;l<r;l++,r--)
			if(a[l]!=a[r])
			{
				cout << "-1" << endl;
			}
		for(int i=1;i<=n-1;i++)
			cout << "LR" << endl;
		cout << "LL" << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

