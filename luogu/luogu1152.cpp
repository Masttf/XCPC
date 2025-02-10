#include<bits/stdc++.h>
using namespace std;
int res[1005],a[1005];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		res[i]=fabs(a[i]-a[i+1]);
	}
	sort(res+1,res+n);
	int flag=1;
	for(int j=1;j<n;j++){
		if(res[j]!=j){
			flag=0;
			break;
		}
	}
	if(flag)
		cout<<"Jolly";
	else
		cout<<"Not jolly";
	return 0;
}
