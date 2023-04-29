//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &arr,int k){
   
        int a=INT_MIN;
        for(int i=0;i<n;i++){
            a=max(a,arr[i][1]);
        }
        vector<int>v(a+3,0);
        for(int i=0;i<n;i++){
            v[arr[i][0]]+=1;
            v[arr[i][1]+1]-=1;
            
        }
        int ans=-1;
        for(int i=1;i<a+3;i++){
             v[i]=v[i-1]+v[i];
             if(v[i]>=k) ans=i;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends