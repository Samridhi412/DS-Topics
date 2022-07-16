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
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll k;
	cin>>k;
	
	int j=0;
	int i=0;
	ll sum=0;
	ll total=0;
	ll maxi=INT_MIN;
	while(j<n){
		// cout<<j<<endl;
		sum+=arr[j];
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			// cout<<sum<<endl;
			total+=sum;
			maxi=max(maxi,sum);
			sum-=arr[i];
			i++;
			j++;
		}	
		
	}
	cout<<total<<" "<<maxi<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}