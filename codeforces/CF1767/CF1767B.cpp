#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int res[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i];
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=2;i<=n;i++){
		q.push(res[i]);
	}
	while(!q.empty()){
		if(res[1]<q.top()){
			res[1]=(res[1]+q.top()+1)/2;
		}
		q.pop();
	}
	cout<<res[1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
