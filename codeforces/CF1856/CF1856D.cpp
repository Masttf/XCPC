#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	map<pair<int,int>,int>m;
	auto get = [&](auto get,int l,int r)->int{
		if(m.count({l,r}))return m[{l,r}];
		if(l==r)return m[{l,r}]=l;
		else{
			int mid=(l+r)>>1;
			int i=get(get,l,mid);
			int j=get(get,mid+1,r);
			int res1;
			int res2;
			if(l==j-1){
				res1=0;
			}else{
				cout<<"? "<<l<<' '<<j-1<<endl;
				cin>>res1;
			}
			cout<<"? "<<l<<' '<<j<<endl;
			cin>>res2;
			if(res1==res2) return m[{l,r}]=j;
			else return m[{l,r}]=i;
		}
	};
	int ans=get(get,1,n);
	cout<<"! "<<ans<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
