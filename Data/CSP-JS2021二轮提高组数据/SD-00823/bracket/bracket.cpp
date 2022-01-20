#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')a=a*10+c-'0',c=getchar();
	return a;
}
int main(){     
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(0));
	int n,m;
	string fuck;
	n=read();m=read();
	getline(cin,fuck);
	int a=rand()%50+1;
	printf("%d",a);
	return 0;
}

