#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
int T,a[1000001],n;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		for(int j=1;j<=2*n;j++){
			scanf("%d",&a[j]);
		}
		for(int j=1;j<=2*n;j++){
			cout<<"L";
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

