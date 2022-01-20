#include<iostream>
using namespace std;
int num[1000005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	while(t){
		t--;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)scanf("%d",&num[i]);
		int f=1;
		for(int i=1;i<=n;i++){
			if(num[i]!=num[n-i+1]){
				f=0;
				break;
			}
		}
		if(f==0)printf("-1");
		else for(int i=1;i<=2*n;i++)printf("L");
		printf("\n");
	}
	return 0;
}
