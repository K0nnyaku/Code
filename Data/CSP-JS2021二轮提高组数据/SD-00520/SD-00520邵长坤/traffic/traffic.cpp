#include<cstdio>

using namespace std;

inline int read(){
	int a=0,f=1;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
	while(s<='9'&&s>='0'){a=a*10+s-'0';s=getchar();}
	return a*f;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);



	fclose(stdin);
	fclose(stdout);
	return 0;
}

