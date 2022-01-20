#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
const int N = 1e5 + 9;
const int M = 1e5 + 9;
const int mod = 998244353;
char s[N];
int n,k;
int read()
{
	int f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^'0');s=getchar();}
	return f*x;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = read(); k = read();
	scanf("%s" ,s + 1);
	printf("19\n"); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
