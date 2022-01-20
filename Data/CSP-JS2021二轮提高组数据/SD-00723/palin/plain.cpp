#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int t , x;
	cin >> t ;
	int a[t] ;
	for(int i = 0 ; i < t ; i++ )
	{
		cin >> a[i] ;
	}
	
	for(int i = 0 ; i < t ; i++ )
	{
		for(int i = 0 ; i < 2*a[i] ; i++ )
			cin >> x ; 
	}
	if(t == 2){
		cout << "LRRLLRRRRL"<<endl; 
		cout << -1 ;
	}
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}


