#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
int n,k,c_size=0;
string c;
inline int reads(){
	char ch=getchar();
	while(ch!='('&&ch!=')'&&ch!='*'&&ch!='?')ch=getchar();
	int WU=0;
	while(ch=='('||ch==')'||ch=='*'||ch=='?'){
		if(ch=='*')WU++;
		else WU=0;
		if(WU>k){
			cout<<"0\n";
			return 1;
		}
		c[c_size]=ch,ch=getchar(),c_size++;
	}
	return 0;
}
using namespace std;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();k=read();
	if(reads()) goto qwe;
	if(c[0]=='*'||c[0]==')'){
		cout<<"0\n";
		goto qwe;
	}
	cout<<1;
	qwe:;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
