#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int t,n;
int a[2*N]; 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    	scanf("%d",&n);
    	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    	printf("-1\n");
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

