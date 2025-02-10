#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	vector<pair<int,int>>a(5);
	for(int i=1;i<=3;i++)cin>>a[i].first>>a[i].second;
	auto get = [&](int x,int y)->double{
		return sqrt((a[x].first-a[y].first)*(a[x].first-a[y].first)+(a[x].second-a[y].second)*(a[x].second-a[y].second));
	};
	double l=0,r=min(max(get(1,2),get(0,2)),max(get(1,3),get(0,3)));
	double x0=get(0,2);
	double x1=get(1,2);
	double y0=get(0,3);
	double y1=get(1,3);
	double d=get(2,3);
	//cout<<x0<<' '<<x1<<endl;
	//cout<<y0<<' '<<y1<<endl;
	//cout<<d<<endl;
	auto check = [&](double rr)->bool{
		if(x0<=rr&&x1<=rr)return true;
		if(y0<=rr&&y1<=rr)return true;
		//cout<<rr<<' '<<"NO"<<endl;
		if(x0<=rr&&y1<=rr&&d<=2*rr)return true;
		//cout<<"a0,bp"<<' '<<"NO"<<endl;
		if(y0<=rr&&x1<=rr&&d<=2*rr)return true;
		return false;
	};
	//cout<<l<<' '<<r<<endl;
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
		//cout<<l<<' '<<r<<endl;
	}
	cout<<fixed<<setprecision(12)<<l<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}