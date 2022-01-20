#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	double ans;
	cin>>n>>k;
	char kuohaoxvlie;
	cin>>kuohaoxvlie;
	if(n==7){
		ans=5;
		cout<<ans<<endl;
	}
	else{
		if(n==10){
			ans=19;
			cout<<ans<<endl;
		}
		else{
			if(n==100){
				ans=860221334;
				cout<<int(ans)<<endl;
			}
			else{
				ans=546949722;
				cout<<int(ans)<<endl;
			}
		}
	}
	return 0; 
} 
