#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n[105],a[105][1060],s;
	cin>>s;
	for(int i=1;i<=s;i++) 
	{
		cin>>n[i];
		for(int j=1;j<=2*n[i];j++)
		cin>>a[i][j];
	}
    for(int i=1;i<=s;i++)
    {
    	if(n[i]%3==2)
    	{
    		for(int j=1;j<=n[i]*2;j++)
    		{
    			if(a[i][j]%3==0)
    			cout<<'L';
    			else
    			cout<<'R';
			}
		}
		else
		cout<<-1;
		cout<<endl;
	 } 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
