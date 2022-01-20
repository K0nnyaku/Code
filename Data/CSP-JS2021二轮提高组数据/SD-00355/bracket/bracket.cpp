#include<iostream>
#include<cstdio>
#include<stack>
#define R register
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') 
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
char a[505],b[505],c[4]="(*)";
int n,k,ans=0;
bool pan(char b[],int x){
	if(b[0]==')'||b[0]=='*')return -1;
	stack<char> st;
	st.push(b[0]);
	bool l=0,r=0;
	int j=1;
	while(!st.empty()){
		st.push(b[j]),j++;
		if(st.top()==')'){
			while(st.top()!='('){
				st.pop();
				if(st.empty())return -1;
			}
			st.pop();
			if(l==1)return -1;
			if(st.top()=='*'){
				while(st.top()=='*') st.pop();
				l=1;
			}
		}
		else if(st.top()=='*'){
				int s=1;
				while(b[j]=='*') st.push(b[j]),j++,s++;
				if(s>k)return -1;
				else continue;
		}
		else {
			if(l){
				l=0;
				continue;
			}
		}
		return -1;
	}
}
void dfs(int x){
	if(x==n){
		for(R int i=0;i<n;i++)
		b[i]=a[i];
		if(pan(b,1))
		ans++;
		return;
	}
	if(a[x]=='?'){
		for(R int i=0;i<=2;i++){
			a[i]=c[i];
			dfs(x+1);
			a[i]='?';
		}
		return ;
	}
	dfs(x+1);
}
int mod=1e9+7;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin>>a;
	if(a[0]=='*'||a[0]==')'){
		cout<<-1;
		return 0;	
	}
	dfs(1);
	printf("%d\n",ans%mod);
	fclose(stdin);
	fclose(stdout);
}
