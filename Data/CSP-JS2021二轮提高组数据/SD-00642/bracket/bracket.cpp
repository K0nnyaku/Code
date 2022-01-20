#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=505;
char str[MAXN];
inline int minn(int a,int b){
	return a<b?a:b;
}
inline int maxx(int a,int b){
	return a>b?a:b;
}
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
int n,k;
int checkS(int pos){
	int cnt=1;
	while(str[++pos]=='*')cnt++;
	return cnt<=k;
}
int checkS1(int pos,int &r){
	int cnt=1;
	while(str[++pos]=='*')cnt++;
	r=pos;
	return cnt<=k;
}
int st[MAXN]={0},top=0;
int checkB(int l,int r){
	if(str[l]!='('||str[r]!=')')return 0;
	for(int i=l;i<=r;i++){
		if(str[i]=='(')st[++top]=i;
		else if(str[i]==')'){
			if(top){
				if(str[st[top]-1]=='*'&&str[i+1]=='*')return 0;
				if(i-st[top]>1)if(!checkS(st[top]+1))return 0;
				top--;
			}
			else return 0;
		}else if(str[i]=='*'){
			if(!checkS1(i,i))return 0;
			i--;
		}
	}
	return !top;
}
long long make(int pos){
	if(pos==n+1){
		top=0;
		if(checkB(1,n)){
			printf("%s\n",str+1);
			return 1;
		}
		return 0;
	}
	if(str[pos]!='?')return make(pos+1);
	long long res=0;
	str[pos]='(';
	res+=make(pos+1);
	str[pos]=')';
	res+=make(pos+1);
	str[pos]='*';
	res+=make(pos+1);
	str[pos]='?';
	return res;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",str+1);
	if(n<2){
		printf("0\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(str[1]=='?')str[1]='(';
	if(str[n]=='?')str[n]=')';
	if(str[1]!='('||str[n]!=')'){
		printf("0\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	printf("\n%s\n\n",str+1);
	printf("%lld",make(1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

