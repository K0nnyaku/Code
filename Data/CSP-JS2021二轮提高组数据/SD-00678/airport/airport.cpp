#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll n,cn,en;
ll cdn[10005],cjn[10005],edn[10005],ejn[10005]; 
ll i,lkc,lke;
ll sumc,sume,ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	sumc=sume=1;
	cin>>n>>cn>>en;
	for(i=1;i<=cn;i++){
		cin>>cdn[i]>>cjn[i];
	}
	for(i=1;i<=en;i++){
		cin>>edn[i]>>ejn[i];
	}
	lkc=cjn[1];
	for(i=2;i<=cn;i++){
		if(cdn[i]>=lkc){
			sumc++;
			lkc=cjn[i];
		}
	}
	lke=ejn[1];
	for(i=2;i<=en;i++){
		if(edn[i]>=lke){
			sume++;
			lke=ejn[i];
		}
	}
	ans=max(sumc,sume);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

