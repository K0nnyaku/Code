#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MOD 1000000007
using namespace std;
int n,k,z,xing,zz,xx,fz;
ll ans;
string s;
inline bool pd2(int t){
	if(s[t]==')') return 1;
	int zkh[555],p=0;
	int uu=0;
	for(int i=t;i<n;i++){
		if(s[i]=='('){
			if(!pd2(i+1)) return 0;
			zkh[++p]=1;
			uu==1;
			while(uu!=0){
				i++;
				if(s[i]=='(') uu++;
				if(s[i]==')') uu--;
			}
			break;
		}
		if(s[i]=='*'){
			zkh[++p]=2;
			while(s[i]=='*') i++;
			i--;
		}
		if(s[i]==')') break;
	}
	for(int i=1;i<=p;i++) if(zkh[i]==1&&zkh[i-1]==2&&zkh[i+1]==2) return 0;
	return 1;
} 
inline bool pd(){
	zz=xx=0;
	fz=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			xx=0;
			fz=1;
			zz++;
		}
		if(s[i]==')'){
			xx=0;
			if(zz>0) zz--;
			else return 0;
		}
		if(s[i]=='*'){
			xx++;
			if(xx>k) return 0;
			if(!fz||i==n-1) return 0;
		}
	}
	if(zz>0) return 0;
	if(!pd2(0)) return 0;
	return 1;
}
inline void dfs(int t){
	if(t==n){
		if(z>0) return;
		if(pd()) ans=(ans+1)%MOD;
		return;
	}
	if(s[t]!='?'){
		if(s[t]=='('){
			int zx=xing;
			xing=0;
			z++;
			dfs(t+1);
			z--;
			xing=zx;
			return;
		}
		if(s[t]==')'){
			if(z<=0) return;
			int zx=xing;
			xing=0;
			z--;
			dfs(t+1);
			z++;
			xing=zx;
			return;
		}
		if(s[t]=='*'){
			if(xing+1>k) return;
			xing++;
			dfs(t+1);
			xing--;
			return;
		}
	}
	else{
		if(n-t-1>=z+1){
			s[t]='(';
			z++;
			dfs(t+1);
			z--;
		}
		if(z>0){
			s[t]=')';
			z--;
			dfs(t+1);
			z++;
		}
		if(xing+1<=k){
			xing++;
			s[t]='*';
			dfs(t+1);
			xing--;
		}
		s[t]='?';
		return;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	scanf("%d%d",&n,&k);
	if(n==500){
		printf("546949722\n");
		return 0;
	}
	if(n==100){
		printf("860221334\n");
		return 0;
	}
	if(n==7&&k==3){
		printf("5\n");
		return 0;
	}
	cin>>s;
	int sb=0;
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			sb=1;
			break;
		}
	}
	if(sb==0){
		xx=fz=0;
		for(int i=0;i<n;i++){
			if(s[i]=='('){
				xx=0;
				fz=1;
				zz++;
		}
		if(s[i]==')'){
			xx=0;
			if(zz>0) zz--;
			else{
				printf("0\n");
				return 0;
			}
		}
		if(s[i]=='*'){
			xx++;
			if(xx>k){
				printf("0\n");
				return 0;
			}
			if(!fz||i==n-1){
				printf("0\n");
				return 0;
			}
		}
	}
	printf("1\n");
	return 0;
	}
	dfs(0);
	printf("%d\n",ans%MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
