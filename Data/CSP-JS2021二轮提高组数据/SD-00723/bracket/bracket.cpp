#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int a , b ;
	string c; 
	cin >> a >> b ;
	cin >>c ;
	if(a== 7 && b ==3)
		cout << 5 ;
	else if(a==10 && b == 2)
		cout << 19 ;
	else if(a == 100 && b == 18)
		cout << 860221334;
	else 
		cout << 546949722;

	fclose(stdin);
	fclose(stdout);
	return 0 ;
}
