#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k;char ch[505];int num1,num2,num3,num4;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n;
	scanf("%d %d",&n,&k);
	scanf("%s",ch); 
	for(int i=0;i<strlen(ch);i++){
		if(ch[i]=='('){
			num1++;
		}else if(ch[i]=='*'){
			num2++;
		}else if(ch[i]==')'){
			num3++;
		}else{
			num4++;
		}
	}
	num4-=abs(num1-num3);
	int m = max(num1,num3);
	int ans = (m*2-1)*k-num2;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
