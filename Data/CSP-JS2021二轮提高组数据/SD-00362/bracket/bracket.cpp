#include<bits/stdc++.h>
using namespace std;
const long long m=1e9+7;
char f[1000001];
int y(int n,int k){
	if(k==1){
		if(n==1) return 1;
		if(n==2) return 1;
		if(n==3) return 1;
		else return y(n-1,k)+y(n-2,k)+y(n-3,k);
	}
	else{
		if(k>1){
			if(n%2==0){
				return y(n,1)+(k-1)*(k-1);
			}
			else{
				return y(n,1)*(k-1);
			}
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>f[i];
	}
	int l=y(a,b);
	int h=l/5;
	if(h%2!=0){
		cout<<(h-2)%m;
	}
	else {
		cout<<(h-1)%m;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
