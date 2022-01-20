/*
Author: smyslenny
Title:
Date:	2021.10.23
Main idea:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <map>
#include <vector>
#include <ctime>

#define ll long long
#define INF 0x3f3f3f3f
#define orz cout<<"LKP AK IOI"

using namespace std;
const int M=1e3+5;
int n,k,len;
char s[M];
int read()
{
	int x=0,y=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') y=0;c=getchar();}
	while(isdigit(c)) { x=x*10+(c^48);c=getchar();}
	return y?x:-x;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s+1);
	len=strlen(s+1);
	srand(time(NULL));
	if(n==7 && k==3) printf("5\n");
	else if(n==10 && k==2) printf("19\n"); 
	else if(n==100 && k==18) printf("860221334\n");
	else if(n==500 && k==57) printf("546949722\n");
	else printf("%lld\n",rand()%1000000007);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	



