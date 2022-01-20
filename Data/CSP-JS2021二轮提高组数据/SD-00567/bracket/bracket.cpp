#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,k,cnt,ans;
char s1[505];
bool allq=true;;

long long fib(int x){
	long long ans[505];
	ans[1]=1;
	ans[2]=1;
	for(int i=3;i<=x;i++){
		ans[i]=ans[i-1]+ans[i-2];
		ans[i]%=(long long)((1e9)+7);
	}
	return ans[x]; 
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	
	scanf("%d%d",&n,&k);
	scanf("%s",&s1);
	for(int i=0;i<n;i++){
		if(s1[i]!='?') allq=false;
	}
	if(allq){
		printf("%lld",fib(n-1));
	}
	else{
		
	}
	
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
