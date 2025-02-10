#include<bits/stdc++.h>
using namespace std;
struct dot{
	double x,y,z;
}res[50005];
bool cmp(dot x,dot y){
	return x.z<y.z;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i].x>>res[i].y>>res[i].z;
	}
	sort(res+1,res+1+n,cmp);
	double sum=0;
	for(int i=2;i<=n;i++){
		sum+=sqrt(pow(res[i].x-res[i-1].x,2)+pow(res[i].y-res[i-1].y,2)+pow(res[i].z-res[i-1].z,2));
	}
	printf("%.3f",sum);
	return 0;
}
