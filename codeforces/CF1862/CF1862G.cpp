#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	map<int,int>m;
	for(int i=1;i<=n;i++)cin>>a[i],m[a[i]]++;
	int q;cin>>q;
	map<int,int,greater<int>>res;
	int last=0;
	res[0]++;
	for(auto it=m.begin();it!=m.end();it++){
		if(it==m.begin()){
			last=it->first;
			continue;
		}
		res[it->first-last]++;
		last=it->first;
	}
	auto updata = [&](int x,int val)->void{
		auto it=m.lower_bound(x);
		if(it!=m.begin()&&it!=--m.end()){
			auto t1=--it;
			it++;
			auto t2=++it;
			it--;
			res[t2->first-t1->first]-=val;
			if(res[t2->first-t1->first]==0)res.erase(t2->first-t1->first);
		}
		if(it!=m.begin()){
			it--;
			res[x-it->first]+=val;
			if(res[x-it->first]==0)res.erase(x-it->first);
			it++;
		}
		if(it!=--m.end()){
			it++;
			res[it->first-x]+=val;
			if(res[it->first-x]==0)res.erase(it->first-x);
		}
	};
	for(int i=1;i<=q;i++){
		int p,x;cin>>p>>x;
		int tem=a[p];
		a[p]=x;
		m[tem]--;
		if(m[tem]==0){
			if(m.size()!=1)updata(tem,-1);
			m.erase(tem);
		}
		m[x]++;
		if(m[x]==1){
			if(m.size()!=1)updata(x,1);
		}
		auto ans=--m.end();
		cout<<ans->first+res.begin()->first<<' ';
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
