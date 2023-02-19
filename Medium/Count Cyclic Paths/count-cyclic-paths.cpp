//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    #define mod 1000000007

    int countPaths(int N){

        vector<long long int>dp(N+1,0);

        dp[1]=0;

        dp[2]=3;

        long long sum=0;

        

        for(int i=3;i<=N;i++)

        {

            

            if(i%2==0)

            {

                sum=sum%mod+dp[i-1]%mod;

                dp[i]=(2*sum)%mod+3;

            }

            else

            {

                sum=sum%mod+dp[i-1]%mod;

                dp[i]=2*sum%mod;

            }

        }

        return dp[N]%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends