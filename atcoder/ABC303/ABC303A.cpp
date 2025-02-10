#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string a,b;cin>>a>>b;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			if((a[i]=='l'&&b[i]=='1')||(a[i]=='1'&&b[i]=='l')||(a[i]=='o'&&b[i]=='0')||(a[i]=='0'&&b[i]=='o')){
				continue;
			}else{
				cout<<"No";
				return 0;
			} 
		}
	}
	cout<<"Yes";
	return 0;
}
