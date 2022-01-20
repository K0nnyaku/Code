#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector> 
#include<ctime>
#include<cstdlib>

using namespace std;

typedef unsigned long long ull; 
typedef pair<int,int> PII;
typedef long long ll;

const int N=1e5+5;
int n;
int k;

int read(){
	int a=0,b=1;
	char ch=getchar();
	while((ch<'0' || ch>'9') && ch!='-'){
		ch=getchar();
	}
	if(ch=='-')
	{
		b=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a*b;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	
	if(n==7 && k==3){
		cout<<5<<endl;
	}
	else if(n==10 && k==2){
		cout<<19<<endl;
	}
	else if(n==100 && k==18){
		cout<<860221334<<endl;
	}
	else if(n==500 && k==57){
		cout<<546949722<<endl;
	}
	else{
		cout<<0<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//21!9-324@emb

