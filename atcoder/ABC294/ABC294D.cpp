#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	int mi=1;
	while(q--){
		int t;cin>>t;
		if(t==1){
			m[mi++]=1;
		}else if(t==2){
			int x;cin>>x;
			if(m.count(x))m.erase(x);
		}else cout<<m.lower_bound(0)->first<<'\n';
	}
	return 0;
}
