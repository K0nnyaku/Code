/*
By miao5



ALL RIGHTS RESERVED



我用fclose了，这个好像能过欸 



期望得分：0~100 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1000005];
string S,s;
int n;
int read(){
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	int s=0;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s;
}
bool checkl(){
	S+='L';
	s+='L';
	int l1=2,r1=n*2;
	int pos=-1;
	for(int i=2;i<=n*2;i++){
		if(a[i]==a[1]){
			pos=i;
			break;
		}
	}
	int l2=pos-1,r2=pos+1;
	int cnt=1;
	while(cnt<n){
		if(a[l1]==a[l2]&&l1<l2&&l2>=1){
			S+='L';
			s+='L';
			l1++;
			l2--;
			cnt++;
		}
		else if(a[l1]==a[r2]&&r2<=2*n){
			S+='L';
			s+='R';
			l1++;
			r2++;
			cnt++;
		}
		else if(a[r1]==a[l2]&&l2>=1){
			S+='R';
		    s+='L';
		    r1--;
		    l2--;
			cnt++;
		}
		else if(a[r1]==a[r2]&&r2<r1&&r2<=2*n){
			S+='R';
			s+='R';
			r1--;
			r2++;
			cnt++;
		}
		else return 0;
	}
	for(int i=n-1;i>=0;i--) S+=s[i];
}
bool checkr(){
	S+='R';
	s+='L';
	int l1=1,r1=n*2-1;
	int pos=-1;
	for(int i=1;i<n*2;i++){
		if(a[i]==a[n*2]){
			pos=i;
			break;
		}
	}
	int l2=pos-1,r2=pos+1;
//	cout<<l2<<' '<<r2<<endl;
	int cnt=1;
	while(cnt<n){
		if(a[l1]==a[l2]&&l1<l2&&l2>=1){
			S+='L';
			s+='L';
			l1++;
			l2--;
			cnt++;
		}
		else if(a[l1]==a[r2]&&r2<=2*n){
			S+='L';
			s+='R';
			l1++;
			r2++;
			cnt++;
		}
		else if(a[r1]==a[l2]&&l2>=1){
			S+='R';
		    s+='L';
		    r1--;
		    l2--;
			cnt++;
		}
		else if(a[r1]==a[r2]&&r2<r1&&r2<=2*n){
			S+='R';
			s+='R';
			r1--;
			r2++;
			cnt++;
		}
		else return 0;
	}
	for(int i=n-1;i>=0;i--) S+=s[i];
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n*2;i++) a[i]=read();
		a[0]=-1;
		a[2*n+1]=-2;
		S=s="";
		if(checkl()) cout<<S<<endl;
		else{
			S=s="";
			if(checkr()) cout<<S<<endl;
			else cout<<-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
