#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;
const int N=505,mod=1e9+7;
int read(){
	int x=0;short f=0;char c=getchar();
	while(c<'0' || c>'9') { if(c=='-') f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=(x<<1)+(x<<3)+(c^48); c=getchar(); }
	return f ? ~x+1 : x ;
}
int n,k,my_count,cnt,ans,t,sum1,sum2,sum3,LEFT,RIGHT;
char a[N],H[N],b[N];
bool my_check(){
	t=sum1=sum2=sum3=0;
	for (int i=1;i<=n;++i){
		if(a[i]=='?') b[i]=H[++t];
		else b[i]=a[i];
		if(b[i]=='('){
			++sum1; if(sum3>k) break;
			sum3=0;
		} 
		else if(b[i]==')'){
			++sum2; if(sum2>sum1 || sum3>k) break; sum3=0;
		}
		else ++sum3;
	}
	if(sum1!=sum2 || sum3>k || b[1]=='*' || b[n]=='*') return 0; 
	LEFT=1,RIGHT=n;
	
	
	while(b[LEFT]=='(' && b[RIGHT]==')'){
		LEFT++; RIGHT--;
	}
	if(RIGHT<LEFT) return 1;
	for (int i=LEFT;i<=RIGHT;++i){
		if(b[i]=='*' && b[i+1]=='(' && b[i-1]!=')'){
			int j=i+2;
			while(b[j]!=')') ++j;
			++j;
			if(b[j]=='*'){
				while(b[j]=='*') ++j;
				if(b[j]!='(') return 0;
			}
		}
	}
}
void my_dfs(int x){
	if(x-1==cnt){
		if(my_check()) ++ans;
		--my_count;
		return;
	}
	for (int i=0;i<3;++i){
		if(i==0){ H[++my_count]='(' ; my_dfs(x+1); }
		else if(i==1){ H[++my_count]=')' ; my_dfs(x+1); }
		else{ H[++my_count]='*' ; my_dfs(x+1); }
	}
	--my_count;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",a+1);
	for (int i=1;i<=n;++i)
		if(a[i]=='?') ++cnt;
	my_dfs(1);
	printf("%d\n",ans%mod);
	return 0;
}
