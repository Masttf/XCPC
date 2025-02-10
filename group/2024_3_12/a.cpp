#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	double a,b,c;cin>>a>>b>>c;
	double x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	if(y2>y1){
		swap(x1,x2);
		swap(y1,y2);
	}
	auto dis = [&](double x,double y,double i,double j)->double{
		return sqrt((x-i)*(x-i)+(j-y)*(j-y));
	};
	double ans=abs(x1-x2)+abs(y1-y2);
	double yy1=(-c-a*x1)/(1.0*b);
	double yy2=(-c-a*x2)/(1.0*b);
	double xx1=(-c-b*y1)/(1.0*a);
	double xx2=(-c-b*y2)/(1.0*a);
	// dbg(x1,yy1);
	// dbg(xx1,y1);
	// dbg(xx2,y2);
	// dbg(x2,yy2);
	if(x1<x2){
		if(y2<=yy1&&yy1<=y1){
			double d=y1-yy1+dis(x1,yy1,xx2,y2)+abs(xx2-x2);
			ans=min(ans,d);
			d=y1-yy1+dis(x1,yy1,x2,yy2)+abs(yy2-y2);
			ans=min(ans,d);
		}
		if(x1<=xx2&&xx2<=x2){
			double d=x2-xx2+dis(xx2,y2,x1,yy1)+abs(y1-yy1);
			ans=min(ans,d);
			d=x2-xx2+dis(xx2,y2,xx1,y1)+abs(x1-xx1);
			ans=min(ans,d);
		}
		if(x1<=xx1&&xx1<=x2){
			double d=xx1-x1+dis(xx1,y1,x2,yy2)+abs(yy2-y2);
			ans=min(ans,d);
			d=xx1-x1+dis(xx1,y1,xx2,y2)+abs(x2-xx2);
			ans=min(ans,d);
		}
		if(y2<=yy2&&yy2<=y1){
			double d=yy2-y2+dis(x2,yy2,xx1,y1)+abs(xx1-x1);
			ans=min(ans,d);
			d=yy2-y2+dis(x2,yy2,x1,yy1)+abs(y1-yy1);
			ans=min(ans,d);
		}
	}else{
		if(y2<=yy2&&yy2<=y1){
			double d=yy2-y2+dis(x2,yy2,xx1,y1)+abs(xx1-x1);
			ans=min(ans,d);
			d=yy2-y2+dis(x2,yy2,x1,yy1)+abs(y1-yy1);
			ans=min(ans,d);
		}
		if(y2<=yy1&&yy1<=y1){
			double d=y1-yy1+dis(x1,yy1,xx2,y2)+abs(xx2-x2);
			ans=min(ans,d);
			d=y1-yy1+dis(x1,yy1,x2,yy2)+abs(yy2-y2);
			ans=min(ans,d);
		}
		if(x2<=xx2&&xx2<=x1){
			double d=xx2-x2+dis(xx2,y2,x1,yy1)+abs(y1-yy1);
			ans=min(ans,d);
			d=xx2-x2+dis(xx2,y2,xx1,y1)+abs(x1-xx1);
			ans=min(ans,d);
		}
		if(x1<=xx1&&xx1<=x2){
			double d=x1-xx1+dis(xx1,y1,x2,yy2)+abs(yy2-y2);
			ans=min(ans,d);
			d=x1-xx1+dis(xx1,y1,xx2,y2)+abs(x2-xx2);
			ans=min(ans,d);
		}
	}
	cout<<fixed<<setprecision(10)<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}