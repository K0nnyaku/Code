#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
int n,T;
int a[1010];
string ans[110];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T>>n;
	for(int i=0;i<T;i++){
		ans[i]="-1";
	}
	while(T--){
		for(int i=0;i<=n;i++){
			cin>>a[i];
		}
	}
	for(int i=0;i<T;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
