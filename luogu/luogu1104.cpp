#include<bits/stdc++.h>
using namespace std;
struct person{
	string name;
	int year,month,day,id;
}res[105];
bool cmp(person x,person y){
	if(x.year!=y.year)return x.year<y.year;
	else if(x.month!=y.month)return x.month<y.month;
	else if(x.day!=y.day)return x.day<y.day;
	else return x.id>y.id;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i].name>>res[i].year>>res[i].month>>res[i].day;
		res[i].id=i;
	}
	sort(res+1,res+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<res[i].name<<'\n';
	}
	return 0;
}
