#include <bits/stdc++.h>

using namespace std;
const int maxn = 500 + 5;
const int maxx = 1e9 + 7;
int n,k,num;
usigned long long ans;
char a[maxn];
void add(int x)
{
	
}
int L[505],R[505];
int main()
{
	//freopen("bracket.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	cin>>a[i],if(i!=1&&i!=n&&a[i] == '?') num++;
	a[1] = '(',a[n] = ')';
	for(int i=1;i<=n;i++)
	{
		if(a[i] == '(') L[num1++] = i;
		else if(a[i] == ')') R[num2++] = i;
	}
	
	
	
	cout<<ans%maxx;
	return 0;	
} 
