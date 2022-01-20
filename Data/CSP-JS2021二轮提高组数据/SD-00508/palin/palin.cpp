#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stack>
using namespace std;
int a[1200000],pre[1200000],ne[1200000],tag[1200000],ans[1200000],n,l,r;
int s[1200000],tp;
void reset(int o){
	for(int i=1;i<=2*o;i++)s[i]=ans[i]=a[i]=pre[i]=ne[i]=tag[i]=0;
	tp=0;
	return;
}
void wri(){
	int nl=1,nr=n*2;
	for(int i=1;i<=n;i++){
		if(s[i]==nl){
			printf("L");
			nl++;
		}else{
			printf("R");
			nr--;
		}
	}
	for(int i=n;i>1;i--){
		if(ans[i])printf("R");
		else printf("L");
	}
	printf("L");
	printf("\n");
	return;
}
bool dfs(int step){
//	while(tag[r]==1)r--;
//	while(tag[l]==1)l++;
	if(step==n){
		wri();
		return true;
	}
	//охвС╠ъ
	int pos=ne[a[l]];
	if(!tag[l] and (tag[pos-1] or tag[pos+1])){
		tag[pos]=1;
		s[++tp]=l;
		ans[tp]=(tag[pos-1])?1:0;l++;
		return dfs(step+1);
	} 
	//тыср╠ъ 
	pos=pre[a[r]];
	if(!tag[r] and (tag[pos-1] or tag[pos+1])){
		tag[pos]=1;
		s[++tp]=r;
		ans[tp]=(tag[pos-1])?1:0;r--;
		return dfs(step+1);
	}
	return false;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		reset(n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=2*n;i++){
			if(!pre[a[i]])pre[a[i]]=i;
			else ne[a[i]]=i;
		}
		l=2,r=2*n;tag[ne[a[1]]]=1;s[1]=1;tp=1;
		if(dfs(1))continue;
		for(int i=1;i<=2*n;i++)tag[i]=0;
		l=1,r=2*n-1;tag[pre[a[2*n]]]=1;s[1]=2*n;tp=1;
		if(dfs(1))continue;
		printf("-1\n");
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

