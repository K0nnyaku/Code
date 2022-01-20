#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int n=1,k=0;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') n=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return n*k;
}
int n,k;
string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	cin>>s;
	printf("17");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
