//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int helper(int ind, vector<int> &arr,vector<int> &dp){

        

        int n=arr.size();

        if(ind>=n || ind<0) return 1;  

        if(dp[ind]>=1){

             return dp[ind];

        }

        

        if(dp[ind]==0){

            return 2;

        }

        

        dp[ind]=0;  // index is in processing 

        int a=ind+arr[ind];

       

        dp[ind]=helper(a,arr,dp);

       

        return dp[ind];   // index calculated 

    }

    int goodStones(int n,vector<int> &arr){

        // Code here

        int ans=0;

        vector<int> dp(n,-1);

        for(int i=0;i<n;++i){

            if(dp[i]==-1){

                helper(i,arr,dp);

            }

        }

        for(int i=0;i<n;++i){

            if(dp[i]==1)

               ans++;

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
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends