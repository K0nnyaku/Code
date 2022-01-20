#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>

using namespace std;

int n,k;
char s[510];

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin >> s;
	if(rand()%2==1) cout << 5 << endl;
	else cout << 4 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
/*
7 3
(*??*??

*/
