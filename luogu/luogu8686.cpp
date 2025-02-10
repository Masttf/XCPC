#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int x;
	vector<int>res;
	for(int i=1;i<=1000000;i++){
		m[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		if(m.count(x)){
			m.erase(x);
		}else{
			x=m.lower_bound(x)->first;
			m.erase(x);
		}
		res.push_back(x);
	}
	for(auto k:res)cout<<k<<' ';
	return 0;
}
/*
#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
const int maxn=1e6+5;
int a[maxn];
void updata(int x){
	while(x<maxn){
		a[x]++;
		x+=lowbit(x);
	}
	return ;
}
int query(int x){
	int sum=0;
	while(x){
		sum+=a[x];
		x-=lowbit(x);
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int x;
	vector<int>res;
	for(int i=1;i<=n;i++){
		cin>>x;
		int l=x,r=maxn,ans=x;
		while(l<=r){
			int mid=(l+r)>>1;
			if(query(mid)-query(x-1)<(mid-x+1)){
				r=mid-1;
				ans=mid;
			}else l=mid+1;
		}
		updata(ans);
		res.push_back(ans);
	}
	for(auto k:res)cout<<k<<' ';
	return 0;
}
 */
