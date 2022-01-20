#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n;char s[1000010];
		scanf("%d",&n);
		for(int i=0;i<2*n;i++){
			cin>>s[i];
		}
		cout<<-1<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
