#include<bits/stdc++.h>

using namespace std;

const int MAXN=5*1e5;
const char l='L';
const char r='R';
const int  NO=-1;

int flag;

int a[MAXN];
int key[MAXN];
stack<char> ans;


int t,n,fr,fl;

inline void tepan()
{
	int s=n;
	while (s--)
	{
		int tttmp=n-s+1;
		if(a[s]==a[tttmp]) flag++;
	}
	if (flag==n) {flag=1;return;}
	flag=0;
}


inline void read()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&a[i]);
	}
	fl=1;
	fr=2*n;
}

inline void rea()
{
	memset(a,0,MAXN);
	memset(key,0,MAXN);
}

inline void out()
{
	char otmp;
	stack<char> tmp;
	tmp=ans;
	int len=ans.size();
	while(len--) 
	{
		otmp=tmp.top();
		tmp.pop();
		printf("%c",otmp);
	}
	printf("\n");
}

inline bool deal(char choice)
{
	if(fl+1>fr)
	{
		if(key[a[fl]]==0) {ans.push(l),key[a[fl]]=fl,fl++;return 1;}
		else if(key[a[fl]]==2*n+1-fl||2*n+1-key[a[fl]]==fl) {ans.push(l),fl++;return 1;}
		return 0;
	}
	else if (choice==l) 
	{
		if(key[a[fl]]==0)
		 {
		 ans.push(l),key[a[fl]]=fl,fl++;
		 if(deal(l))
		 {
		 	return 1;
		 }
		 else {ans.pop(),key[a[fr]]=0,key[a[fl]]=0,fl--;return deal(r);}
		 }
		else if(key[a[fl]]==2*n+1-fl||2*n+1-key[a[fl]]==fl) 
		{
			ans.push(l),fl++;
			if( deal(l))
			{
				return 1;
			}
			else  {ans.pop(),fl--,key[a[fr]]=0,key[a[fl]]=0;return deal(r);}
		}
		return deal(r);
	}
	else
	{
		if(key[a[fr]]==0) 
		{
		ans.push(r),key[a[fr]]=fr,fr--;
		if (deal(l))
		{
			return 1;
		}
		else
		{
			ans.pop(),key[a[fr]]=0,key[a[fl]]=0,fr++;
			return 0;
		}
		}
		else if(key[a[fr]]==2*n+1-fr||2*n+1-key[a[fr]]==fr) 
		{
		ans.push(r),key[a[fr]]=fr,fr--;
		if (deal(l))
		{
			return 1;
		}
		else
		{
			ans.pop(),fr++,key[a[fr]]=0,key[a[fl]]=0;
			return 0;
		}
		}
		return 0;
	}

}




int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
		rea();
		read();
		tepan();
		if(flag==0)
		{
			if(deal(l)) out();
			else printf("%d\n",NO);
		}
		else if(flag == 1)
		{
			int s=2*n;
			while (s--)
			{
				printf("%c",l);
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
