#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
bool flag;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	int a[2002];
	scanf("%d",&t);
	while(t--){
		flag=0;
		int n;
		scanf("%d",&n);
		for(int i=0;i<2*n;i++){
			scanf("%d",&a[i]);
		}
		
		
		if(flag==0) cout<<"-1"<<endl;
		else{
			
		}
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
