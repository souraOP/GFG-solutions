//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int>vi;
        vi=arr;
        sort(vi.begin(), vi.end());
        vector<long long> v(n,0), ans;
        v[0]=vi[0];
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+vi[i];
        }
        for(int i=0;i<n;i++){
            int x= lower_bound(vi.begin(), vi.end(), arr[i])-vi.begin();
            x--;
            if(x>=0){
                ans.push_back(v[x]);
            }
            else{
                ans.push_back(0);
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends