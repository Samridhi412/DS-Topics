#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
void solve(){
	int h,c,t;
	cin>>h>>c>>t;
	int dif=abs(t-h),cups=1;
	if(t==h){
		cout<<cups<<endl;
		return;
	}
	else if(t<=(h+c)/2){
		cups=2;
		dif=abs(t-(h+c)/2);
	}
	else{
		// int x=(t-c)/(2*t-(h+c));
		// int y=x+1;
		// double val1=(x*h+(x-1)*c)/2*x-1;
		// double val2=(y*h+(y-1)*c)/2*y-1;
		// double dif1=abs(t-val1);
		// double dif2=abs(t-val2);
		// if(dif1<=dif2){
		// 	cout<<2*x-1<<endl;
		// }
		// else{
		// 	cout<<2*y-1<<endl;
		// }
		if (2*t != h+c) {
			double critical = (t-c)/(2*t-h-c);
			double x1 = ceil(critical), x2 = floor(critical);
			if (x2 > 1) {
				double val1 = abs((x2*h+(x2-1)*c)/(2*x2-1) - t);
			//	cout << val1 << " " << x2 << "\n";
				if (val1 < dif) cups = 2*x2-1, dif = val1; 
			}
			if (x1 > 1) {
				double val1 = abs((x1*h+(x1-1)*c)/(2*x1-1) - t);
			//	cout << val1 << " " << x1 << "\n";
				if (val1 < dif) cups = 2*x1-1, dif = val1; 
			}
		}
		
	}
	cout << cups << "\n";
	

}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
		// cout<<"hi";
	}
	return 0;
}