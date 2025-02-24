#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,h,k;cin>>n>>m>>h>>k;
	string s;cin>>s;
	map<pair<int,int>,int>tem;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		tem[{x,y}]++;
	}
	int nx=0,ny=0;
	for(int i=0;i<n;i++){
		if(h==0){
			cout<<"No";
			return 0;
		}
		h--;
		if(s[i]=='R'){
			nx++;
		}else if(s[i]=='L'){
			nx--;
		}else if(s[i]=='U'){
			ny++;
		}else{
			ny--;
		}
		if(tem.count({nx,ny})){
			if(h<k){
				h=k;
				tem.erase({nx,ny});
			}
		}
	}
	cout<<"Yes";
	return 0;
}
