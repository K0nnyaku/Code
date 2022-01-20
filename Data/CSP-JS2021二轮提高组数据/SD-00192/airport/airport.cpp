#include<bits/stdc++.h>
using namespace std;
int sortt(int,int);
int sorte(int,int);
int na[100001][3],fr[100001][3];
int main()
{
freopen("airport.in","r",stdin);
freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++)
    for(int j=1;j<=2;j++)
    cin>>na[i][j];
    for(int i=1;i<=m2;i++)
    for(int j=1;j<=2;j++)
    cin>>fr[i][j];
for(int i=1;i<m1;i++)
if((na[i][1]>na[i+1][1])||(na[i][1]==na[i+1][1]&&na[i][2]>na[i+1][2]))
{swap(na[i][1],na[i+1][1]);
swap(na[i][2],na[i+1][2]);
}
for(int i=1;i<m2;i++)
if((fr[i][1]>fr[i+1][1])||(fr[i][1]==fr[i+1][1]&&fr[i][2]>fr[i+1][2]))
{swap(fr[i][1],fr[i+1][1]);
swap(fr[i][2],fr[i+1][2]);
}
	fclose(stdin);fclose(stdout);
	return 0;
	
}
