//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        
        int one=colors[0][0];
        int two=colors[0][1];
        int three=colors[0][2];
        int t1, t2, t3;
        for(int i=1 ; i < N ; i++){
            t1=one;
            t2=two;
            t3=three;
            one=colors[i][0] + min(t2,t3) ;
            two=colors[i][1] + min(t1,t3);
            three=colors[i][2] + min(t1,t2);
        }
        return min({one, two, three});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends