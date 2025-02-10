#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
struct node{
	int val,id;
	bool operator <(const node& y)const{
		if(val!=y.val)return val>y.val;
		else return id<y.id;
	}
};
void solve(){
	int n,k;cin>>n>>k;
	vector<node>ans;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		x=x%k;
		if(x==0)x=k;
		node temp;
		temp.val=x;
		temp.id=i;
		ans.push_back(temp);
	}
	sort(ans.begin(),ans.end());
	for(auto x:ans){
		cout<<x.id<<' ';
	}
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
