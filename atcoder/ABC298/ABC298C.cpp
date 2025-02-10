#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
multiset<int>a[maxn];
set<int>b[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int x,y;cin>>x>>y;
			a[y].insert(x);
			b[x].insert(y);
		}
		else if(t==2){
			int x;cin>>x;
			for(auto it=a[x].begin();it!=a[x].end();it++){
				cout<<*it<<' ';
			}
			cout<<'\n';
		}else{
			int x;cin>>x;
			for(auto it=b[x].begin();it!=b[x].end();it++){
				cout<<*it<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}
