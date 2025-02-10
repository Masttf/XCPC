#include<bits/stdc++.h>
using namespace std;
int res[1005];
int main(){
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		sum+=res[i];
	}
	sum/=n;
	int cnt=0;
	for(int i=1;i<n;i++){
		if(res[i]<sum){
			cnt++;
			res[i+1]-=sum-res[i];
		}else if(res[i]>sum){
			cnt++;
			res[i+1]+=res[i]-sum;
		}
	}
	cout<<cnt;
	return 0;
}
