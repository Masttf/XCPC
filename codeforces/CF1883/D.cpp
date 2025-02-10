#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){//要有两个区间不交叉就是r<l
	int q;cin>>q;
	map<int,int>l;
	map<int,int>r;
	for(int i=1;i<=q;i++){
		string s;cin>>s;
		int x,y;cin>>x>>y;
		if(s[0]=='+'){
			l[x]++;
			r[y]++;
		}else{
			l[x]--;
			r[y]--;
			if(l[x]==0)l.erase(x);
			if(r[y]==0)r.erase(y);
		}
		if(l.empty())cout<<"NO\n";
		else{
			auto it=l.end();
			it--;
			int ll=it->first;
			int rr=r.begin()->first;
			if(ll>rr)cout<<"YES\n";
			else cout<<"NO\n";
		}
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