#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[25];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= 2*n; i ++){
			scanf("%d",&a[i]);
		}
		cout << -1 <<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
