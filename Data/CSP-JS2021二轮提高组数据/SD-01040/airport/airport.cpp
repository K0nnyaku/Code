#include<bits/stdc++.h>
using namespace std;

int n, m1, m2;
struct data{
	int a, b;
}f1[100005], f2[100005];
int number1, number2, number;
int t[200005];
int ans;

bool comp (data a, data b)
{
	if (a.a==b.a)
		return a.b<b.b;
	return a.a<b.a;
}

void work (int x)
{
	number1=0; memset (t, 0, sizeof(t));
	if (x!=0)
		for (int i=1; i<=m1; i++)//国内 
		{
			if (f1[i].a>t[1])
				t[1]=f1[i].b,
				number1++;
			sort (t+1, t+x+1); 
		}
	
	number2=0; memset (t, 0, sizeof(t));
	if (x!=n)
		for (int i=1; i<=m2; i++)//国外 
		{
			if (f2[i].a>t[1])
				t[1]=f2[i].b,
				number2++;
			sort (t+1, t+n-x+1); 
		}
	
	number=number1+number2;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf ("%d%d%d", &n,&m1,&m2);
	for (int i=1; i<=m1; i++)
		scanf ("%d%d", &f1[i].a,&f1[i].b);
	for (int i=1; i<=m2; i++)
		scanf ("%d%d", &f2[i].a,&f2[i].b);
	
	sort (f1+1, f1+m1+1, comp);
	sort (f2+1, f2+m2+1, comp);
	
	for (int i=0; i<=n; i++)
		work (i),//给国内i个 
		ans=max (ans, number);
	
	printf ("%d", ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
