#include<bits/stdc++.h>
using namespace std;
int T,n,cnt;
const int N=1000009;
int a[N];
bool flag=false;
string G;
void tp1(){
	int t=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[2*n+1-i])t++;
	}
	if(t==n){
		flag=true;
		for(int i=1;i<=n*2;i++){
			printf("L");
		}
		printf("\n");
	}
}
int b[109][N],tot;
string bb[N];
bool tp2(){//不存在回文字符串 
	int t=0,k=1;
	for(int i=1;i<=n;i++){
		bb[k]=a[i];
		for(int j=i+1;j<=i+n-1;j++){
			if(a[i]==a[j]){
				t++;k--;
			}
			else{
				bb[k]+=a[j];
			}
		}
	}
	tot=k;
	if(t==n||(t==n-1 && !flag)){
		printf("-1\n");
		return false;
	}
}
bool qr(int j){
	int t=0;
	for(int i=1;i<=n;i++){
		if(b[j][i]==b[j][2*n+1-i])t++;
	}
	if(t==n){
		return true;
	}else{
		return false;
	}
} 
string ans;
void comp(string s){
	for(int i=1;i<=n;i++){
		if(ans[i]>s[i]){
			ans=s;
		}
	}
}
void gxh(string c){
	string d;
	int cnt2=n*2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n*2;j++){
			if(a[j]==c[i]-'0'){
				if(j<cnt/2){
					d+='L';
					cnt--;
				}else{
					d+='R';
					cnt--;
				}
				break;
			}
		}
	}
	d+="RRRRR";
	comp(d);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++){
			scanf("%d",&a[i]);
			ans+='R';
		}
		tp1();
		if(flag==true){
			return 0;
		}
		if(tp2()==false){
			return 0;
		}
		for(int i=1;i<=tot;i++){
			gxh(bb[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
