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
int tsp(int i,int** d,int mask,int n){
	if(mask==0){
		return d[i][0];
	}
	int mini=1e9;
	for(int j=0;j<n;j++){
		if(j!=i&&mask&(1<<j)){
			int min_dist=d[i][j]+tsp(j,d,mask^(1<<j),n);
			mini=min(mini,min_dist);
		}
	}
	return mini;
}
void solve(){
	ll n;
	cin>>n;
	int** dist=new int*[n];
	for(int i=0;i<n;i++){
		dist[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dist[i][j];
		}
	}
	int mask=((1<<n)-1)^(1);
	// cout<<mask;
	cout<<tsp(0,dist,mask,n);
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}