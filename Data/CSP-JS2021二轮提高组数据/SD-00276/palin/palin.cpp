#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int n;
int a[5959810];
int bans[5959810];
int sta[5959810];
bool appear[10];
bool opear[5959810];
bool opar[5959810];
bool opef = false;
int opelen = 0;
void dfs(int l,int r,int b[],int blen,int sta[],int stalen,bool opear[],int depth){
//	cout<<l<<" "<<r<<" "<<blen<<" "<<stalen<<endl;
//	cout<<depth<<endl;
	if(l > r){
		if(stalen == 0){
			if(!opef){
				for(int i = 1,r = blen;i<=r;i++,r--){
					opar[i] = opear[i],opar[r] = opear[r];
				}
				opef = true;
			}else{
				for(int i = 1,r = blen;i<=r;i++,r--){
					if(opar[i] <= opear[i])break;
					else if(opar[r] <= opear[r])break;
					else{
						opar[i] = opear[i],opar[r] = opear[r];
					}
				}
			}
            opelen = blen;
		}
		return;
	}
	if(blen >= n){
		bool cho1 = false,cho2 = false;
		if(sta[stalen] == a[l]){
			stalen--;
			b[++blen] = a[l];
			opear[blen] = 0;
			cho1 = true;
		}
		if(!cho1){
			if(sta[stalen] == a[r]){
				stalen--;
				b[++blen] = a[r];
				opear[blen] = 1;
				cho2 = true;
			}
		}
		if(!cho1 && !cho2)return;
		if(cho1){
			dfs(l+1,r,b,blen,sta,stalen,opear,depth+1);
			stalen++;
			blen--;
			if(sta[stalen] == a[r]){
				stalen--;
				b[++blen] = a[r];
				opear[blen] = 1;
				cho2 = true;
			}
			if(cho2){
				dfs(l,r-1,b,blen,sta,stalen,opear,depth+1);
				stalen++,blen--;			
			}
			return;
		}else{
		    dfs(l,r-1,b,blen,sta,stalen,opear,depth+1);
			stalen++,blen--;
			return;
		}
	}else{
		bool cho1 = false,cho2 = false;
		if(!appear[a[l]]){
			sta[++stalen] = a[l];
			b[++blen] = a[l];
			appear[a[l]]=1;
			opear[blen] = 0;
			cho1 = true;
		}
		if(!cho1){
			if(!appear[a[r]]){
				sta[++stalen] = a[r];
			    b[++blen] = a[r];
				appear[a[r]] = 1;
				opear[blen] = 1;
				cho2 = true;
			}
		}
		if(!cho1 && !cho2)return;
		if(cho1){
			dfs(l+1,r,b,blen,sta,stalen,opear,depth+1);
			appear[a[l]] = 0;
			blen--,stalen--;
			if(!appear[a[r]]){
				sta[++stalen] = a[r];
			    b[++blen] = a[r];
				appear[a[r]] = 1;
				opear[blen] = 1;
				cho2 = true;
			}
			if(cho2){
				dfs(l,r-1,b,blen,sta,stalen,opear,depth+1);
				appear[a[r]] = 0;
				blen--,stalen--;
			}
			return;
		}else{
			dfs(l,r-1,b,blen,sta,stalen,opear,depth+1);
			appear[a[r]] = 0;
			blen--,stalen--;
			return;
		}
	}
}
void entry(){
	memset(appear,0,sizeof appear);
	memset(opear,0,sizeof opear);
	memset(opar,0,sizeof opar);
	opef = false;
	cin>>n;
	for(int i = 1;i<=2*n;i++)cin>>a[i];
	dfs(1,2*n,bans,0,sta,0,opear,0);
	if(!opef)cout<<-1<<endl;
	else{
		for(int i = 1;i<=opelen;i++)
			if(!opar[i])cout<<'L';
			else cout<<'R';
		cout<<endl;		
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		entry();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
