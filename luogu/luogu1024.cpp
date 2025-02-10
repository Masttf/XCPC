#include<iostream>
using namespace std;
double a,b,c,d;
const double eps=1e-4;
double fc(double x){
	double sum=a*x*x*x+b*x*x+c*x+d;
	return sum;
}
int main(){
	cin>>a>>b>>c>>d;
	int cnt=0;
	for(int i=-100;i<=100;i++){
		double x1=i,x2=i+1;
		if(!fc(x1)){
			if(cnt<2)
				printf("%.2f ",x1);
			else printf("%.2f",x1);
			cnt++;
			continue;
		}
		else if(fc(x1)*fc(x2)<0){
			double left=x1,right=x2;
			while(left+eps<=right){
				double mid=(left+right)/2;
				double temp=fc(mid);
				double temp2=fc(left);
				if(temp*temp2>0)left=mid;
				else if(temp*temp2<0)right=mid;
				else if(temp==0){
					left=temp;break;
				}
			}
			if(cnt<2)
				printf("%.2f ",left);
			else printf("%.2f",left);
			cnt++;
		}
	}
	return 0;
}
