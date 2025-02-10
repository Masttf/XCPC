#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,q;cin>>n>>q;
	vector<set<int>>a(n+1);
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[i].insert(x);
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		if(a[y].empty())swap(a[x],a[y]);
		else{
			if(a[x].size()>a[y].size()){
				for(auto it:a[y]){
					a[x].insert(it);
				}
				swap(a[x],a[y]);
			}else{
				for(auto it:a[x]){
					a[y].insert(it);
				}
			}
			a[x].clear();
		}
		cout<<a[y].size()<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}