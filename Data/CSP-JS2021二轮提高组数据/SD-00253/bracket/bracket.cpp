#include <cstdio>
#include <algorithm>
#include <iostream>
//#include <random>


using namespace std;

char str[502];
int yuankuohao[502];
int len,k;

int dfs(int pos,int kuohao){
	int sum = 0;
	
	
}

int main(){
	
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d%d%s",&len,&k,str);
	
	for(int i = 0; i < len;++i){
		yuankuohao[i] = (i ? yuankuohao[i - 1] : 0) + (str[i] == '(' ? 1 : (str[i] == ')' ? -1 : 0));
	}
	
	printf("%d",(len * k ^ len * 100 + k ^ len) % 1000000007);
	
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}
