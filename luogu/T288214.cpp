#include<bits/stdc++.h>
using namespace std;
const long long k=1e9+10;
vector<long long>res;
pair<long long,long long> gethuiwen(long long m){
	long long ans=m;
	long long ans2=m;
	long long temp=0;
	int cnt=0;
	while(m>0){
		temp=m&1;
		if(cnt!=0)
			ans2=(ans2<<1)+temp;
		ans=(ans<<1)+temp;
		m>>=1;
		cnt=1;
	}
	pair<long long,long long> p1=make_pair(ans,ans2);
	return p1;
}
int main(){
	for(long long i=1;i<100000000;i++){
		pair<long long,long long> p1=gethuiwen(i);
		res.push_back(p1.first);
		res.push_back(p1.second);
	}
	for(int i=0;i<res.size();i++){
		cout<<res[i];
	}
	return 0;
}
