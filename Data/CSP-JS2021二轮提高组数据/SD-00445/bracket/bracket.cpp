#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include<string>
#define random(x) (rand()%x)
using namespace std;
char s[510];
int n,k;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++){
		scanf("%c",&s[i]);
	}
	

	 
	//srand((int)time(0));
	//cout<<random(18);
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
}//±ðÍüÁËÈ¥µô×¢ÊÍ 
