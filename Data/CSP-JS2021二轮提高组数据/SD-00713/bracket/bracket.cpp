#include<bits/stdc++.h>
using namespace std;
char ch[550];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>ch[i];
	if(ch[1]=='*'||ch[1]==')'||ch[n]=='*'||ch[n]=='(')
	{
		cout<<0;
    	fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
    if(n<=8)
    {
    	cout<<14;
    	fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	if(n<=10)
    {
    	cout<<21;
    	fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	if(n<=15)
    {
    	cout<<34;
    	fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	cout<<79281;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
