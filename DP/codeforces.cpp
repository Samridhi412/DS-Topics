#include<bits/stdc++.h>
using namespace std;
int main(){
    long long test;
    cin>>test;
    while(test--){
        long long n;
        cin>>n;
        int flag=0;
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long temp=arr[0];
        for(int i=1;i<n;i++){
                if(arr[i]%temp!=0)
                    {flag=1;
                        cout<<"hello";
                     break;}
        }
        if(flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}