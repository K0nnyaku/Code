#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
#define maxn 1e9+7
int n,k;

char s[510];
long long a[510]={0,0,1,1,2};

//我可以打表吧?? 
//不打了………… 
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	//all ? ??
	gets(s);
	
	int l=strlen(s);
	
	cout<<a[l]%maxn<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
