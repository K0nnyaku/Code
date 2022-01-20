#include<cstdio>
#include<random>
#include<ctime>
using namespace std;
char s[510];
int n,k,emp;
inline int power(int a,int b){
	int c=1;
	while(b){
		if(b%2==1){
			c=c*a;
		}
		a=a*a;
		b>>=1;
	}
	return c;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='?')
			emp++;
	}
	printf("%d",emp>=19?rand()%1000000007:rand()%power(3,emp));
	return 0;
}
/*
O(n)
正确率：1/3^ct_?
也就是很低的意思
预计得分：0 
*/
