//枚举秒数可以得到能运行的设备单调减
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const double eps=1e-6;
int n,q;
pair<double,double> res[maxn];
bool check(double x){
	double sum=0;
	for(int i=1;i<=n;i++){
		if(res[i].first*x>res[i].second){
			sum+=res[i].first*x-res[i].second;
		}
	}
	return sum<=q*x;
}
int main(){
	cin>>n>>q;
	double s=0;
	for(int i=1;i<=n;i++){
		cin>>res[i].first>>res[i].second;
		s+=res[i].first;
	}
	if(s<=q){
		cout<<-1.000;
		return 0;
	}
	double ans=-1,left=0,right=1e10;
	while(left+eps<=right){
		double mid=(left+right)/2;
		if(check(mid))ans=mid,left=mid;
		else right=mid;
	}
	cout<<ans;
	return 0;
}
