#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,k;
string s;
char s1[3]={'*','(',')'};
char s2[3]={'*','(',')'};
bool find(string a)
{
	int z=0,y=0,js=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='(') z++;
		else if(a[i]==')') y++;
	}
	if(z!=y) return -1;

}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	
	return 0;
	
}  
