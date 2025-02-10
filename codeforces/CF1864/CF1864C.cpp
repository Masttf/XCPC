//同时一个数的 lowbit值也一定是它的因子???
#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int x;cin>>x;
	vector<int>ans;
	ans.push_back(x);
	map<int,int,greater<int>>mp;
	auto get = [&](int xx,int ct)->void{
		for(int i=2;i*i<=xx;i++){
			if(xx%i==0){
				int cnt=0;
				while(xx%i==0){
					xx/=i;
					cnt++;
				}
				mp[i]+=cnt*ct;
			}
		}
		if(xx!=1)mp[xx]+=1*ct;
	};
	get(x,1);
	while(x!=1){
		int rt=mp.begin()->first;
		int ct=mp.begin()->second;
		mp.erase(rt);
		get(rt-1,ct);
		for(int i=1;i<=ct;i++){
			ans.push_back(x-x/rt);
			x-=x/rt;
			//cout<<"YES "<<x<<endl;
		}
	}
	//cout<<"YES"<<endl;
	cout<<ans.size()<<'\n';
	for(auto t : ans)cout<<t<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
