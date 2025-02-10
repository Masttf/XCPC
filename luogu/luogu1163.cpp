#include<bits/stdc++.h>
using namespace std;
const double eps=1e-5;
double n,m,k;
bool check(double x){
	double a=n*(1+x)-m;
	for(int i=2;i<=k;i++){
		a*=(1+x);
		a-=m;
	}
	return a<=0;
}
int main(){
	cin>>n>>m>>k;
	double ans=0,left=0,right=5;
	while(left+eps<=right){
		double mid=(left+right)/2;
		if(check(mid))ans=mid,left=mid;
		else right=mid;
	}
	printf("%.1f",ans*100);
	return 0;
}
