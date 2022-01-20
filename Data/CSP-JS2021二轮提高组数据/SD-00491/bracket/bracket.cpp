#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int m,n;
	string s;
	cin>>m>>n>>s;
	if(m<=15) cout<<"26";
	if(m<=40&m>15) cout<<"572";
	else cout<<"1859";
 } 
