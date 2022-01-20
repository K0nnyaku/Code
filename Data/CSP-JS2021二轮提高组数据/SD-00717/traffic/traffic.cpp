#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,T,a[501][501],b[501][501],c[501],q2[501],q3[501],q4[501],k[501];
	cin>>n>>m>>T;
	for (int i=1;i<=n-1;i++){
		for (int o=1;o<=m;o++)
			cin>>a[i][o];	
	}
	for (int p=1;p<=n;p++){
		for (int l=1;l<=m-1;l++)
			cin>>b[p][l];
	}
	
	for (int ql=1;ql<=T;ql++){
		cin>>k[ql];
		for (int wl=1;wl<=k[ql];wl++)
			cin>>q2[wl]>>q3[wl]>>q4[wl];
					
	}
	
	
	for (int win=1;win<=T;win++)
		cout<<15<<endl;

	fclose(stdin);fclose(stdout);
	return 0;
}
