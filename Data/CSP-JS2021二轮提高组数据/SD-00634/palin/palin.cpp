#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100010],r;
char ao[100010],ans[100010],b[100010];
int work(int x) {
	for(int i=1;i<=x;i++) {
		if(b[i]!=b[x-i+1]) return 0;
	} 
	return 1;
}
int cmp(int x) {
	for(int i=1;i<=x;i++) {
		if(ao[i]=='R'&&ans[i]=='L')  {
			return 0;
		}
	}
	return 1;
}
void dis(int t,int w,int e,int f) {	
	if(t>w) {	
		if(work(e)&&(cmp(e)||r==0)) {
			for(int i=1;i<=e;i++) ans[i]=ao[i];r=1;
		}
		return;
	}
	b[f]=a[t]+'0';
	ao[f]='L';
	dis(t+1,w,e,f+1);
	b[f]=a[w]+'0';
	ao[f]='R';
	dis(t,w-1,e,f+1);
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		int m;
		cin>>m;
		for(int j=1;j<=2*m;j++) {
			int y;
			cin>>y;
			a[j]=y;
		}
		r=0;
		dis(1,2*m,2*m,1);
	    if(r==1) {
	    	for(int j=1;j<=2*m;j++) cout<<ans[j];cout<<endl;
	    }
	    if(r==0) cout<<-1;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
