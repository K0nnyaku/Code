#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long t,n,l,r,flag=1,sd;
long long wz[500005][2];
long long a[500005],wzl,wzr,sx[500005],charu[500005];
string ans;
inline long long read(){
	long long s=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(isdigit(c)){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*f;
}
void rt(){
	ans+="R";
	l=wz[a[2*n]][0]-1;
	r=wz[a[2*n]][0]+1;
	sx[wz[a[2*n]][0]]=1;
	sd=1;
	wzl=1;
	wzr=2*n-1;
	for(int i=2;i<=n;i++){
		if(wz[a[wzl]][0]+wz[a[wzl]][1]-wzl==l&&charu[a[wzl]]==0){
			sd++;
			sx[l]=sd;
			l--;
			charu[a[wzl]]=1;
			wzl++;
			ans+="L";
		}else if(wz[a[wzl]][0]+wz[a[wzl]][1]-wzl==r&&charu[a[wzl]]==0){
			sd++;
			sx[r]=sd;
			r++;
			charu[a[wzl]]=1;
			wzl++;
			ans+="L";
		}else if(wz[a[wzr]][0]+wz[a[wzr]][1]-wzr==l&&charu[a[wzr]]==0){
			sd++;
			sx[l]=sd;
			l--;
			charu[a[wzr]]=1;
			wzr--;
			ans+="R";
		}else if(wz[a[wzr]][0]+wz[a[wzr]][1]-wzr==r&&charu[a[wzr]]==0){
			sd++;
			sx[r]=sd;
			r++;
			charu[a[wzr]]=1;
			wzr--;
			ans+="R";
		}else{
			flag=0;
			return;
		}
	}
	l++;
	r--;
	for(int i=n;i>=1;i--){
		if(sx[l]==i){
			l++;
			ans+="L";
		}else if(sx[r]==i){
			r--;
			ans+="R";
		}
	}
	return;
}
void leaf(){
	ans+="L";
	l=wz[a[1]][1]-1;
	r=wz[a[1]][1]+1;
	sx[wz[a[1]][1]]=1;
	sd=1;
	wzl=2;
	wzr=2*n;
	for(int i=2;i<=n;i++){
		if(wz[a[wzl]][0]+wz[a[wzl]][1]-wzl==l&&charu[a[wzl]]==0){
			sd++;
			sx[l]=sd;
			l--;
			charu[a[wzl]]=1;
			wzl++;
			ans+="L";
		}else if(wz[a[wzl]][0]+wz[a[wzl]][1]-wzl==r&&charu[a[wzl]]==0){
			sd++;
			sx[r]=sd;
			r++;
			charu[a[wzl]]=1;
			wzl++;
			ans+="L";
		}else if(wz[a[wzr]][0]+wz[a[wzr]][1]-wzr==l&&charu[a[wzr]]==0){
			sd++;
			sx[l]=sd;
			l--;
			charu[a[wzr]]=1;
			wzr--;
			ans+="R";
		}else if(wz[a[wzr]][0]+wz[a[wzr]][1]-wzr==r&&charu[a[wzr]]==0){
			sd++;
			sx[r]=sd;
			r++;
			charu[a[wzr]]=1;
			wzr--;
			ans+="R";
		}else{
			flag=0;
			return;
		}
	}
	l++;
	r--;
	for(int i=n;i>=1;i--){
		if(sx[l]==i){
			l++;
			ans+="L";
		}else if(sx[r]==i){
			r--;
			ans+="R";
		}
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		n=read();
		ans="";
		flag=1;
		memset(wz,0,sizeof(wz));
		memset(charu,0,sizeof(charu));
		for(int j=1;j<=2*n;j++){
			a[j]=read();
			if(wz[a[j]][0]!=0){
				wz[a[j]][1]=j;
			}else{
				wz[a[j]][0]=j;
			}
		}
		leaf();
		if(flag==1){
			cout<<ans<<endl;
			continue;
		}
		flag=1;
		ans="";
		memset(charu,0,sizeof(charu));
		rt();
		if(flag==1){
			cout<<ans<<endl;
			continue;
		}
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
