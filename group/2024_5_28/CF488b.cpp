#include<bits/stdc++.h>
#define int long long
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
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	auto check = [&](vector<int>res)->bool{
		sort(res.begin()+1,res.end());
		int d1=(res[4]-res[1])*4;
		int d2=(res[3]+res[2])*2;
		int d3=res[1]+res[2]+res[3]+res[4];
		//dbg(d1,d2,d3);
		if(d1==d2&&d2==d3)return true;
		else return false;
	};
	if(n==4){
		if(check(a))cout<<"YES\n";
		else cout<<"NO\n";
	}else if(n==0){
		cout<<"YES\n";
		cout<<1<<'\n'<<1<<'\n'<<3<<'\n'<<3<<'\n';
		return ;
	}else if(n==2){
		int d1=a[1]*3;
		int d2=a[1]+d1-a[2];
		//dbg(d1,d2);
		vector<int>res(5);
		res[1]=a[1];
		res[2]=a[2];
		res[3]=d1;
		res[4]=d2;
		if(d2>=0){
			if(check(res)){
				cout<<"YES\n";
				cout<<d2<<'\n'<<d1<<'\n';
				return ;
			}
		}
		if(a[2]%3==0){
			d1=a[2]/3;
			d2=d1+a[2]-a[1];
			res[1]=a[1];
			res[2]=a[2];
			res[3]=d1;
			res[4]=d2;
			if(check(res)){
				cout<<"YES\n";
				cout<<d1<<'\n'<<d2<<'\n';
				return ;
			}
			
		}
		int sum=a[1]+a[2];
		if(sum%4==0){
			d1=sum/4;
			d2=sum/4*3;
			res[1]=a[1];
			res[2]=a[2];
			res[3]=d1;
			res[4]=d2;
			if(check(res)){
				cout<<"YES\n";
				cout<<d1<<'\n'<<d2<<'\n';
				return ;
			}
		}
		cout<<"NO\n";
		return ;
	}else if(n==1){
		cout<<"YES\n";
		cout<<a[1]<<'\n'<<3*a[1]<<'\n'<<3*a[1]<<'\n';
		return ;
	}else{
		int d1=a[3]*4-a[1]*4;
		int temp=d1-a[1]-a[2]-a[3];
		vector<int>res(5);
		res[1]=a[1];
		res[2]=a[2];
		res[3]=a[3];
		res[4]=temp;
		if(check(res)){
			cout<<"YES\n";
			cout<<temp<<'\n';
			return ;
		}
		d1=2*a[1]+2*a[2];
		temp=d1-a[1]-a[2]-a[3];
		if(temp>=0){
			res[1]=a[1];
			res[2]=a[2];
			res[3]=a[3];
			res[4]=temp;
			if(check(res)){
				cout<<"YES\n";
				cout<<temp<<'\n';
				return ;
			}
		}
		
		d1=2*a[2]+2*a[3];
		temp=d1-a[1]-a[2]-a[3];
		if(temp>=0){
			res[1]=a[1];
			res[2]=a[2];
			res[3]=a[3];
			res[4]=temp;
			if(check(res)){
				cout<<"YES\n";
				cout<<temp<<'\n';
				return ;
			}
		}
		cout<<"NO\n";
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