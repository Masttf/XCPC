#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...)\
do{ \
cout<<#x<<"->";\
err(x);\
}while(0)

void err(){
	cout<<endl<<endl;
	return ;
}
template <class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}

void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	a[0]=INT_MAX;
	stack<int>mx;
	stack<int>mi;
	map<int,int>m1;
	map<int,int>m2;
	int ans=0;
	int sum=0;
	auto addmx = [&](int x)->void{
		while(!mx.empty()&&a[mx.top()]<a[x]){
			auto it=m2.lower_bound(mx.top());
			if(it!=m2.end()){
				//dbg("1?",sum);
				sum-=it->first-mx.top();
				//dbg("2?",sum);
				auto temp1=m1.lower_bound(mx.top());
				if(temp1!=m1.begin()){
					temp1--;
					//cout<<"OK"<<endl;
					if(it!=m2.begin()){
						auto temp2=it;
						temp2--;
						if(temp1->first>temp2->first){
							sum+=it->first-temp1->first;
						}
					}else{
						sum+=it->first-temp1->first;
					}
				}
			}
			m1.erase(mx.top());
			mx.pop();
		}
		mx.push(x);
		m1[x]=1;
		return ;
	};
	auto addmi = [&](int x)->void{
		//dbg("1","yes");
		while(!mi.empty()&&a[mi.top()]>a[x]){
			auto it=m1.upper_bound(mi.top());
			if(it!=m1.begin()){
				it--;
				auto temp1=m2.lower_bound(mi.top());
				if(temp1!=m2.begin()){
					temp1--;
					sum-=mi.top()-max(it->first,temp1->first);
				}else{
					sum-=mi.top()-it->first;
				}
			}
			m2.erase(mi.top());
			mi.pop();
		}
		m2[x]=1;
		mi.push(x);
		//dbg("yes");
		auto it=m1.upper_bound(x);
		if(it!=m1.begin()){
			it--;
			auto temp1=m2.lower_bound(x);
			if(temp1!=m2.begin()){
				temp1--;
				sum+=x-max(it->first,temp1->first);
			}else{
				sum+=x-it->first;
			}
		}
	};
	m1[0]=1;
	mx.push(0);
	
	for(int i=1;i<=n;i++){
		//cout<<"YES"<<endl;
		addmx(i);
		cout<<i<<' '<<sum<<' ';
		//cout<<"YES"<<endl;
		addmi(i);
		ans+=sum;
		cout<<sum<<endl;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}