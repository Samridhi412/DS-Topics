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
#define pi 3.1415927
#define mp make_pair
#define pb push_back
#define endl "\n"
void solve(){
	int r,a,b;
	cin>>r>>a>>b;
	double sum=0;
	bool flag=1;
	while(r>0){
		sum+=r*r;
		if(flag){
			r=r*a;
		}
		else{
			r=r/b;
		}
		flag=1-flag;
		
	}
// 	sum=pi*sum;

	cout<<fixed<<setprecision(6)<<pi*sum<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
	return 0;
}