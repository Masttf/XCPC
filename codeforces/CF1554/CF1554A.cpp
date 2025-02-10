#include<iostream>
#include<vector>
using namespace std;
vector<long long> res;
long long ans=0;
long long temp;
int main(){
	int t;cin>>t;
	while(t--){
		res.push_back(0);
		int n;cin>>n;
		long long y;
		for(int i=1;i<=n;i++)
		{	
			cin>>y;
			res.push_back(y);
			temp=res[i]*res[i-1];
			if(temp>=ans)
				ans=temp;
		}	
		cout<<ans<<'\n';
		ans=0;
		res.clear();
	}
	return 0;
}
