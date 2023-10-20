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
const ll range=1e9+2;
vector<bool> primes(range,true);
vector<int> prefix_sums(range,0);
void funct(){
	primes[0]=primes[1]=false;
	for(ll i=2;i*i<=range;i++){
		if(primes[i]==true){
			for(ll j=i*i;j<=range;j+=i){
			primes[j]=false;	
			}
		}
	}
}
void solve(){
	ll m,n;
	cin>>m>>n;
	for(ll i=m;i<=n;i++){
		if(primes[i]==true){
			cout<<i<<endl;
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	funct();
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}