#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
int main ( ) {
	freopen ("palin.in","r",stdin);
	freopen ("palin.out","w",stdout);
	srand(time(0));
	int t,n;
	scanf("%d",&t);
	if (t==1){
		printf("-1\n");
		return 0;
	}
	while (t--){
		scanf("%d",&n);
		int tt=rand()%(n*2),ttt=rand()%(n*2);
		tt=abs(tt-ttt);
		if (tt==0){
			printf("-1");
		}
		for (int i=0;i<tt;i++){
			ttt=rand()&1;
			printf("%c",ttt&1?'L':'R');
		}
		printf("\n");
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
