#include<cstdio>
#include<iostream>
int n,k;
int a[505],ans=0,temp=0,t=0,h=0,b[505];
/*void pr(){
	for(int i=1;i<=n;i++){
		if(a[i]==0)printf("0");
		if(a[i]==1)printf("(");
		if(a[i]==2)printf(")");
		if(a[i]==3)printf("*");
	}
	putchar('\n');
}*/
bool check(){
	int st[505],top=0,lei=0;
	for(int i=1;i<=n;++i){
		if(a[i]==1){
			if(a[i-1]==3)st[++top]=1;
			else st[++top]=0;
		}
		if(a[i]==2){
			if(a[i+1]==3&&st[top]==1)return 0;
			else --top;
		}
	}
	if(top)return 0;
	return 1;
}
void dfs(int x){
	if(h>temp)return;
	if(x>n){if(check()){++ans;/*pr();*/}return;}
	/*if(h==temp){
		if(h<0)for(int i=x;i<=n;++i)if(a[i]==0)a[i]=1;
		else for(int i=x;i<=n;++i)if(a[i]==0)a[i]=2;
		dfs(n+1);
	}*/
	if(a[x]){
		if(a[x]==1)++h,dfs(x+1),--h;
		if(a[x]==2)--h,dfs(x+1),++h;
		if(a[x]==3)dfs(x+1);
		return;
	}
	--temp;
	++h;
	a[x]=1;
	dfs(x+1);
	--h;
	if(h){
		a[x]=2;
		--h;
		dfs(x+1);
		++h;
	}
	if(b[x-1]+b[x+1]<k){
		a[x]=3;
		if(b[x-1]&&b[x+1]){
			int tl=b[x-1],tr=b[x+1];
			b[x-tl-1]=b[x+tr+1]=tl+tr+1;
			dfs(x+1);
			b[x-tl-1]=tl,b[x+tr+1]=tr;
		}
		else{
			if((!b[x-1])&&(!b[x+1])){
				b[x]=1;
				dfs(x+1);
				b[x]=0;
			}
			else{
				if(b[x-1]){
					int tl=b[x-1];
					b[x-tl-1]=b[x]=tl+1;
					dfs(x+1);
					b[x-tl-1]=tl,b[x]=0;
				}
				else{
					int tr=b[x+1];
					b[x+tr+1]=tr+1;
					dfs(x+1);
					b[x+tr+1]=tr;
				}
			}
		}
	}
	a[x]=0;
	++temp;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	char ch;
	while(ch^'('&&ch^')'&&ch^'*'&&ch^'?')ch=getchar();
	for(int i=1;i<=n;++i){
		if(ch=='(')a[i]=1;
		if(ch==')')a[i]=2;
		if(ch=='*')a[i]=3;
		if(ch=='?')++temp;
		ch=getchar();
	}
	for(int i=1;i<=n;++i){
		if(t^0){
			if(a[i]==3){
				++t;
				continue;
			}
			else{
				b[i-t]=t,b[i-1]=t;
				t=0;
			}
		}
		if(t>k||h<0){
			printf("0");
			return 0;
		}
		if(a[i]==3)t=1;
	}
	a[1]=1,a[n]=2;
	dfs(1);
	printf("%d",ans);
	return 0;
}

