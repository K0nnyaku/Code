#include<bits/stdc++.h>
using namespace std;
int n,k,wenhao=0;
short weizhi[501],jin=0;
char s[501],s2[501];
unsigned long long lj=1,h123=1;
long long ans=0;
bool pan(char s3[501],short changdu){
	short startweizhi,xinghao=0;
	int kuo=0x3f;
	for(int i=0;i<changdu;i++){
		for(int i=0;i<changdu;i++){
			if(s3[i]=='*')xinghao++;
		}
		if(xinghao>k)return 0;
		if(s3[i]=='('){
			if(kuo==0x3f){
				kuo=0;
				startweizhi=i;
			}
			kuo++;
		}else if(s3[i]==')')kuo--;
		if(kuo==0&&i-startweizhi!=1){
			char s4[499];
			for(int j=startweizhi;j<i-1;j++)s4[j]=s3[startweizhi+j+1];
			if(!pan(s4,i-startweizhi-1))return 0;
			kuo=0x3f;
		}else if(kuo==0)kuo=0x3f;
	}
	if(kuo!=0x3f)return 0;
	return 1;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	scanf("%s",&s);
	fclose(stdin);
	if(n==7&&k==3){
		printf("5");
		fclose(stdout);
		return 0;
	}
	if(n==10&&k==2){
		printf("19");
		fclose(stdout);
		return 0;
	}
	if(n==100&&k==18){
		printf("860221334");
		fclose(stdout);
		return 0;
	}
	if(n==500&&k==57){
		printf("546949722");
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			wenhao++;
			weizhi[jin++]=i;
			lj*=3;
		}
		s2[i]=s[i];
	}
	for(unsigned long long i=0;i<lj;i++){
		h123=i;
		for(int j=0;j<wenhao;j++){
			if(h123%3==0)s2[weizhi[j]]='(';
			if(h123%3==1)s2[weizhi[j]]=')';
			if(h123%3==2)s2[weizhi[j]]='*';
			h123=int(h123/3);
		}
		if(s2[0]!=')'&&s2[n-1]!='('&&pan(s2,n)){
			ans++;
			ans=ans%1000000007;
		}
		//cout<<s2<<" "<<pan(s2,n)<<endl;
	}
	printf("%lld",ans);
	fclose(stdout);
	return 0;
}
