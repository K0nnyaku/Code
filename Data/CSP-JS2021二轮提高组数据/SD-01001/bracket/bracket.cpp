#include<stdio.h>
#include<stdlib.h>
char str[512];
int n,sta[512],tp=0,k,ans=0;
bool check(int l,int r){
	if(r<l) return 1;
	int cob=0,flag=0;tp=1;
	for(int i=l;i<=r;i++){
		if(str[i]=='(') tp++,flag=1;
		else if(str[i]==')') tp--,flag=1;
		if(tp<0) return 0;
	}
	tp--;
	if(tp!=0) return 0; 
	if(!flag) return (r-l+1)<=k;
	int sts=0,lb;
	for(int i=l;flag&&(i<=r);i++){
		switch(str[i]){
			case '(':sta[tp++]=i,sts=0;break;
			case ')':
				lb=sta[--tp];
				flag=check(lb+1,i-1);
				if((str[lb]=='*')&&(str[i]=='*'))
					flag=0;
				sts=0;
			break;
			case '*':
				sts++;
				flag=(sts<=k);
			break;
			default:
				flag=0;
		}
	}
	return flag;
}
void dfs(int p){
	if(p==n-1){
		if(check(1,n-2)){
			ans++;
		}	
		return;
	}
	if(str[p]=='?'){
		str[p]='*';
		dfs(p+1);
		str[p]='(';
		dfs(p+1);
		str[p]=')';
		dfs(p+1);
		str[p]='?';
	}else dfs(p+1);
	
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	scanf("%d%d",&n,&k);
	scanf("%s",str);
	str[0]='(';str[n-1]=')';
	dfs(1);
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
