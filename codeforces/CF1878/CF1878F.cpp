#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int q;cin>>q;
	int temp=n;
	map<int,int>m;
	int ans=1;
	auto get =[&](int x)->void{
		for(int i=2;i*i<=x;i++){
			if(x%i==0){
				int cnt=0;
				while(x%i==0){
					x/=i;
					cnt++;
				}
				if(m.count(i)){
					ans=ans/(m[i]+1);
				}
				m[i]+=cnt;
				ans*=(m[i]+1);
			}
		}
		if(x!=1){
			if(m.count(x)){
				ans=ans/(m[x]+1);
			}
			m[x]++;
			ans*=(m[x]+1);
		}
		return ;
	};
	auto check = [&](int x)->bool{
		bool flag=1;
		for(int i=2;i*i<=x;i++){
			if(x%i==0){
				int cnt=0;
				while(x%i==0){
					x/=i;
					cnt++;
				}
				if(m.count(i)){
					if(m[i]<cnt)flag=0;
				}else flag=0;
			}
		}
		if(x!=1){
			if(m.count(x)){
				if(m[x]<1)flag=0;
			}else flag=0;
		}
		return flag;
	};
	get(n);
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==2){
			n=temp;
			m.clear();
			ans=1;
			get(n);
		}else{
			int x;cin>>x;
			get(x);
			if(check(ans))cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
