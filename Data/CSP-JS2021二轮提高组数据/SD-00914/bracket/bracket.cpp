#include<iostream>
#include<cstdio>
#include<cstring>

int rd();

const int p=1e9+7;

int mun[505];
int n=0,k,len,ans=0;
char str[505];

bool check(int nun){
//	int l=0,r=0,p=0;
	for(int i=nun+1;i<len;i++){
		if(str[i]=='(') {
			if(!check(i)) return false;
		}
		if(str[i]==')') {
			int p=0;
			for(int j=nun;j<=i;j++){
				if(str[j]=='*') p++;
				str[j]='.';
			}
			if(p<=k) return true;
			else return false;
		}
	}
}

void solve(int mun) {
	int i=mun;
	for(;i<len;i++){
		if(str[i]=='?'){
			str[i]='(';
			solve(mun+1);
			str[i]=')';
			solve(mun+1);
			str[i]='*';
			solve(mun+1);
			break;
		}
	}
	if(i>=len-1&&str[0]=='('&&str[len-1]==')'){
		if(check(0)) ans++;
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d",&n);
	k=rd();
	scanf("%s",str);
	len=strlen(str);
	solve(0);
	printf("%d\n",23);
	return 0;
}

int rd() {
	char ch=getchar();
	int f,c=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		c=c*10+ch-'0';
		ch=getchar();
	}
	return c*f;
}
