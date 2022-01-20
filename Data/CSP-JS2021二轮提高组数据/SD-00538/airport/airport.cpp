#include <bits/stdc++.h>
using namespace std;
long long n,m1,m2,h1=1,h2=1;
long long am11[10005],am12[10005],am13[10005];
long long am21[10005],am22[10005],am23[10005];
int spw1[100005],spw2[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long maxn1=-1;long long maxn2=-1;
	cin >> n >> m1 >> m2;
	for(int i=1;i<=m1;i++){
		cin>>am11[i]>>am12[i];
		am13[am11[i]]=i;
		maxn1=max(am11[i],maxn1);
	}
	for(int i=1;i<=m2;i++){
		cin>>am21[i]>>am22[i];
		am23[am21[i]]=i;
		maxn2=max(am11[i],maxn2);
	}
	int p=1;
	int max1=-1;
	do{
		int tot=0;
		int t=n-p;
		for(int i=1;i<=maxn1;i++){
			if(am13[i]!=0){
				for(int x=1;x<=p;x++){
					if(am11[am13[i]]>=spw1[x]){
						spw1[x]=am12[am13[i]];
						tot++;
						break;
					}
				}
			}
		}
		for(int i=1;i<=maxn2;i++){
			if(am13[i]!=0){
				for(int x=1;x<=t;x++){
					if(am11[am13[i]]>=spw2[x]){
						spw2[x]=am12[am13[i]];
						tot++;
						break;
					}
				}
			}
		}
		max1=max(max1,tot);
	}while(p==n);
	cout << max1;
	return 0;
}
