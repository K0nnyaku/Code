#include<cstdio>
#include<random>
#include<ctime>
using namespace std;
int n,m,t;
int main(){
	srand(time(0));
//	freopen("traffic.in","r",stdin);
//	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	long long a=rand();
	for(;t;t--){
		a=rand();
		printf("%lld\n",a);
	}
	return 0;
}
/*
O(t)
正确率：1/2147483647 
预计得分：0 
*/
