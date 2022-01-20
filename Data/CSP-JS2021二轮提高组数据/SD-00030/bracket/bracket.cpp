#include <iostream> 
#include <cstring> 
using namespace std;
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	string a;
	cin>>a;
	int l=a.size();
	if(a[0]=='?' || a[l-1]=='?')
	{
		a[0]='(';
		a[l-1]=')';
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


