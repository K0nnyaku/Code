#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mol=1e9+7;
inline int read()
{
	int x=0; int f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,ans=0;
char bk[505];
int main()
{
	//freopen("bracket.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	int i,j;
	scanf("%d %d",&n,&k);
	cin.getline(bk,n+1); 
	
	
	
	//fclose(stdin); fclose(stdout);
	return 0;
}
