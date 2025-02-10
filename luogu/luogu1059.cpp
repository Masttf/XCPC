#include<bits/stdc++.h>
using namespace std;
int res[105];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	sort(res+1,res+1+n);
	int fast=0;
	int slow=0;
	while(fast<=n){
		if(res[fast]!=res[slow])
		{
			slow++;
			res[slow]=res[fast];
		}
		fast++;
	}
	cout<<slow<<'\n';
	for(int i=1;i<=slow;i++){
		cout<<res[i]<<' ';
	}
	return 0;
}
