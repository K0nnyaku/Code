#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
string s="";
int end=0,l[614300],lin[614300],cnt[614300],t,n;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n*2;i++)scanf("%d",l+i);
		int i;
		for(i=0;i<1<<n;i++){
			int lnow=0,rnow=0,j;
			for(j=n-1;j>=0;j--){
				if(i&(1<<j))lin[lnow+rnow]=l[n*2-rnow-1],rnow++,s+="R";
				else lin[lnow+rnow]=l[lnow],lnow++,s+="L";
//				printf("%d %d %s\n",lnow,rnow,s.c_str());
			}
			for(j=0;j<n;j++){
//				printf("%d %d %d %d %d\n",lnow,rnow,lin[j],l[lnow],l[n*2-rnow-1]);
				if(lin[n-j-1]==l[lnow])lnow++,s+="L";
				else if(lin[n-j-1]==l[n*2-rnow-1])rnow++,s+="R";
				else{
					s="";
					break;
				}
			}
			if(j==n){
				printf("%s\n",s.c_str());
				break;
			}
		}
		if(i==1<<n)printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*1 5
4 1 2 4 5 3 1 2 3 5*/
