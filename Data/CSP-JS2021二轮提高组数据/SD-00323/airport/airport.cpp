#include<bits/stdc++.h>
using namespace std;
int n,m,mm;
int ans;
int e1,e2;
int a[100005],aa[100005],b[100005],bb[100005],ma=0;
bool t1[100005][105],t2[100005][250],fl[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m>>mm;
	int c1=0,c2;
	c2=n;
	for(int i=1;i<=n;i++){
		fl[i]=false;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i]>>aa[i];
	}
	for(int i=1;i<=mm;i++){
		cin>>b[i]>>bb[i];
	}
	for(int i=1;i<=250;i++)
		for(int j=1;j<=n;j++){
			t1[j][i]=false;
			t2[j][i]=false;
		}
	sort(a,a+m+1);
	sort(aa,aa+m+1);
	sort(bb,bb+mm+1);
	sort(b,b+mm+1);
	for(int i=0;i<=n;i++){
		e1=0;
		e2=0;
		ans=0;
		for(int j=1;j<=m;j++){
			if(e1<c1){
				ans++;
				e1++;
				for(int k=a[j];k<=aa[j];k++){
					t1[j][k]=true;
				}
			}
			else{
				for(int o=1;o<=c1;o++)
				if(t1[o][a[j]]==false&&fl[j]==false){
					ans++;
					for(int kk=a[j];kk<=aa[j];kk++)
						t1[o][kk]=true;
				}
			}
			cout<<ans<<" ";
		}
		for(int p=1;p<=mm;p++){
			if(e2<c2){
				ans++;
				e2++;
				for(int q=b[p];q<=bb[p];q++){
					t2[p][q]=true;
				}
			}
			else{
				for(int oo=1;oo<=c2;oo++) 
				if(t2[oo][b[p]]==false&&fl[p]==false){
					ans++;
					for(int qq=b[p];qq<=bb[p];qq++)
						t2[oo][qq]=true;
				}
			}
			cout<<ans<<" ";
		}
		c1++;
		c2--;
		ma=max(ma,ans);
	}
	cout<<ma<<endl;
	return 0;
}
