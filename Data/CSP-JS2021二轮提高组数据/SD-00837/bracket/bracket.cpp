#include<bits/stdc++.h>
using namespace std;
string x;
int num=0;
int a[600];
int fb[600];
int t[10];
int n,k;//1 2 3 4´ú±í£¨£¬£©£¬*£¬£¿ 
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>x;
	for(int i=1;i<=n;i++){
		if(x[i-1]=='(') a[i]=1;
		if(x[i-1]==')') a[i]=2;
		if(x[i-1]=='*') a[i]=3;
		if(x[i-1]=='?') a[i]=4;
	}
	if(a[1]==4){
		num+=1;
		a[1]==1;
	}
	if(a[n]==4){
		num+=1;
		a[n]=2;
	}
	int maxl=0;int zz=1;
	for(int i=1;i<=n;i++){
		if(a[i]==4){
			fb[zz]=i;
			t[4]+=1;
			zz+=1;
		}
	}
	for(int i=1;i<=t[4];i++){
		zz++;
	}
	cout<<(2*n)-k;
	return 0;
}
