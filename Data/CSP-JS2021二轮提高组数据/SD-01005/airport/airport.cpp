#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
int n,m1,m2;
int a[100000001];
int b[100000001];
int c[100005][2];
int d[100005][2];
int ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>c[i][0]>>c[i][1];
	}
	for(int i=1;i<=m2;i++){
		cin>>d[i][0]>>d[i][1]; 
	}
	for(int i=0;i<=n;i++){
		int sum1=0;
		int sum2=0;
		
		for(int j=1;j<=m1;j++){
			if(a[c[j][0]]<i){
				for(int l=c[j][0];l<=c[j][1];l++){
					a[l]++;
				}
				sum1++;
			}
		}
		for(int j=1;j<=m2;j++){
			if(b[d[j][0]]<n-i){
				for(int l=d[j][0];l<=d[j][1];l++){
					b[l]++;
				}
				sum2++;
			}
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if(sum1+sum2>ans)
		ans=sum1+sum2;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

