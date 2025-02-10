#include<bits/stdc++.h>
using namespace std;
int res[200][200];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>res[i][j];
			res[i][j]+=res[i-1][j]+res[i][j-1]-res[i-1][j-1];
		}
	}
	int mx=res[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int p=i-1;p>=0;p--){
				for(int q=j-1;q>=0;q--){
					mx=max(mx,res[i][j]-res[i][q]-res[p][j]+res[p][q]);
				}
			}
		}
	}
	cout<<mx;
	return 0;
}
