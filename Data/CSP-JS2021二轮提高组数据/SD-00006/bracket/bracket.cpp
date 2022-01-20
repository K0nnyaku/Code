#include<bits/stdc++.h>
using namespace std;
unsigned int f[256][256][256][2];
char str[256];
unsigned int n, k;
int main(){
	
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
	cin>>n>>k;
	
	while(isspace(cin.peek()))cin.get();
	cin.getline(str+1, 255);
	
	f[0][0][0][0]=1;
	//f[0][0][0][1]=1;
	
	for(unsigned int i=1; i<=n; i++){
		for(unsigned int j=0; j<=i; j++){
			for(unsigned int a=0; a<k; a++){
				for(unsigned int b=0; b<2; b++){
					if(str[i]=='('){
						f[i][j+1][0][1]=max(f[i-1][j][a][b], f[i][j+1][0][1]);
					}
					else if(str[i]=='*'&&a+1<k){
						f[i][j][a+1][b]=f[i-1][j][a][b];
					}
					else if(str[i]==')'&&j>0){
						f[i][j-1][0][1]=max(f[i-1][j][a][b], f[i][j-1][0][1]);
					}
					else{//?
						f[i][j+1][0][1]+=f[i-1][j][a][b];//(
						if(a+1<k)f[i][j][a+1][b]+=f[i-1][j][a][b];//*
						if(j>0)f[i][j-1][0][1]+=f[i-1][j][a][b];//)
					}
				}
			}
		}
	}
	/*
	for(unsigned int i=1; i<=n; i++){
		cerr<<str[i]<<": "<<endl;
		for(unsigned int j=0; j<=i; j++){
			for(unsigned int a=0; a<k; a++){
				for(unsigned int b=0; b<2; b++){
					cerr<<"f["<<i<<"]["<<j<<"]["<<a<<"]["<<b<<"]="<<f[i][j][a][b]<<endl;
				}
			}
		}
	}
	*/
	
	cout<<f[n][0][0][1]<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
}
/*
7 3
(*??*??

10 2
???(*??(?)
*/

