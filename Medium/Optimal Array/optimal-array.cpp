//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &arr){
        vector<int> ans;
        vector<int> sum(n,0);
        sum[0]=arr[0];
        ans.push_back(0);
        for(int i=1;i<n;i++)
        {
            sum[i]+=sum[i-1]+arr[i];
            int curr=0;
            if(i%2==0) // Odd no. of elements
            {
                int j=i/2;
                int sum1 = sum[j-1];
                int sum2 = sum[i]- sum[j];
                curr=sum2-sum1;
            }
            else // Even no. of elements
            {
                int j=i/2;
                int sum1=sum[j];
                int sum2=sum[i]-sum[j];
                curr=sum2-sum1;
            }
            ans.push_back(curr);
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends