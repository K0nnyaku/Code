#include<bits/stdc++.h>
using namespace std;

char s[505],xh[505];
int ceng=0,n,k,wh=0;

bool judge(int a,int b){
	int kh=0;
	memset(xh,0,sizeof(xh));
	for(int i=a;i<=b;i++){
		if(s[i]=='('){
			if(xh[kh]>0)xh[kh]=-1;
			kh++;
		}
		if(s[i]=='*'){
			if(xh[kh]==-1){
				return 0;
			}
			xh[kh]++;
			if(i==b)return 0;
		}
		if(s[i]==')'){
			kh--;
			if(kh<0){
				return 0;
			}
			if(xh[kh+1]>k){
				return 0;
			}
			xh[kh+1]=0;
		}
	}
	if(xh[0]>k)return 0;
	if(kh!=0){
		return 0;
	}
	return 1;
}

long long most(int leftwh){
	//printf("%d\n",leftwh);
	long long q1,q2,q3;
	if(leftwh==0){	
		if(judge(1,n)==1){
			for(int i=1;i<=n;i++){
	//		printf("%c",s[i]);
			}
	//		printf("\n");
			return 1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			s[i]='(';
			q1=most(leftwh-1);
			s[i]='*';
			q2=most(leftwh-1);
			s[i]=')';
			q3=most(leftwh-1);
			s[i]='?';
			break;
		}
	}
	return q1+q2+q3;
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	getchar();
	if(n==0){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%c",&s[i]);
		if(s[i]=='?')wh++;
	}
	printf("%d\n",most(wh)%1000000007);
	//printf("%d\n",wh);
	//for(int i=1;i<=n;i++){
	//	printf("%c",s[i]);
	//}printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
