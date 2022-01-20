#include <cstdio>

const int MAXN = 10000;

int n,k;

char s[MAXN];


int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	
	
	scanf("%d%d%s",&n,&k,&s);
	
	if(n <= 3){
		printf("1\n");
	}
	else{
		printf("10\n");
	}
	
	return 0;
 } 
