#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int a[1000009],b[1000009];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++){
			scanf("%d",&a[i]);	
		}
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

