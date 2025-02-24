#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	vector a(10,vector<int>(10));
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++)cin>>a[i][j];
	}
	
	int ok=1;
	for(int i=1;i<=9;i++){
		vector<int>cnt(10);
		for(int j=1;j<=9;j++){
			cnt[a[i][j]]++;
			if(cnt[a[i][j]]>=2)ok=0;
		}
	}
	for(int j=1;j<=9;j++){
		vector<int>cnt(10);
		for(int i=1;i<=9;i++){
			cnt[a[i][j]]++;
			if(cnt[a[i][j]]>=2)ok=0;
		}
	}
	if(!ok){
		cout<<"No";
		return ;
	}
	auto jd = [&](int x,int y)->bool{
		vector<int>cnt(10);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cnt[a[x+i][y+j]]++;
				if(cnt[a[x+i][y+j]]>=2)return false;
			}
		}
		return true;
	};

	for(int i=1;i<=9;i+=3){
		for(int j=1;j<=9;j+=3){
			if(!jd(i,j)){
				cout<<"No";
				return ;
			}
		}
	}
	cout<<"Yes";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}