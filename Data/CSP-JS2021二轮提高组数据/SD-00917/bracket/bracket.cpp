#include<bits/stdc++.h>
#include<stack>
using namespace std;
int read()
{
	int o=0,e=1;
	char z;
	z=getchar();
	while(z<'0'||z>'9') {if(z=='-') e=-1;z=getchar();}
	while(z>='0'&&z<='9') {o=(o<<1)+(o<<3)+z-'0';z=getchar();}
	return o*e;
}
const int N=510;
int n,k;
char a[N];
char xz[4]={0,'(',')','*'};
int ans=0;
const int MOD=1e9+7;

struct D{
	int pre,nxt,id;
}dn[N];
char stc[N];
char sa[N];
stack<char>zuo;
bool qu(int s,int t)
{
	if(dn[s+1].id==1||dn[t-1].id==1) return true;
	if(dn[t-1].pre==s+1) return true;
	return false;
}
bool yan()
{
	memset(stc,0,sizeof(stc));
	while(!zuo.empty()) zuo.pop();
	int js=0;
	for(int i=1;i<=n;i++)
	{
		stc[i]=sa[i];
		if(stc[i]=='(')
		{
			zuo.push(i);
			js+=1;
		}
		if(stc[i]=='*')
		{
			if(zuo.empty()||sa[zuo.top()]!='*')
				zuo.push(i);
			if(sa[i+1]!='*')
			{
				int t=i;
				int s=zuo.top();
				zuo.pop();
				dn[i].pre=s;
				dn[i].id=3;
				dn[s].nxt=i;
				dn[s].id=3;
			}
		}
		if(stc[i]==')')
		{
			js-=1;
			if(js<0)
				return false;
			int t=i;
			int s=zuo.top();
			zuo.pop();
			dn[i].pre=s;
			dn[i].id=1;
			dn[s].nxt=i;
			dn[s].id=1;
			
			if(!qu(s,t))
				return false;
		}
	}
	if(dn[1].id==1&&dn[n].id==1) return true;
	return false;
}
int ct=0;
void search(int dao,int lian)
{
	if(lian>k) return;			//¼õÖ¦ 
	if(ct<0) return;
	if(ct>(n-dao+1)) return;
	if(dao>n)
	{
		if(ct>0) return;
		if(yan())
		{
			ans+=1;
			ans%=MOD;
		}
		return;
	}
	if(a[dao]!='?')
	{
		sa[dao]=a[dao];
		if(sa[dao]=='(') ct+=1;
		if(sa[dao]==')') ct-=1;
		if(sa[dao]=='*')
			search(dao+1,lian+1);
		else
			search(dao+1,0);
		if(sa[dao]=='(') ct-=1;
		if(sa[dao]==')') ct+=1;
	}
	else for(int i=1;i<=3;i++)
	{
		sa[dao]=xz[i];
		if(sa[dao]=='(') ct+=1;
		if(sa[dao]==')') ct-=1;
		if(sa[dao]=='*')
			search(dao+1,lian+1);
		else
			search(dao+1,0);
		
		if(sa[dao]=='(') ct-=1;
		if(sa[dao]==')') ct+=1;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
//	freopen("in.in","r",stdin);
	n=read(),k=read();
	for(int i=1;i<=n;i++) 
		scanf("%c",&a[i]);
	search(1,0);
	cout<<ans<<endl;
	return 0;
}
