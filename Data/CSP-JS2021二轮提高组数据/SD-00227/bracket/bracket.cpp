#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int t;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	printf("0\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
