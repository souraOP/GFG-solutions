//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        vector<vector<int>> col_cost = costs;
        int n = costs.size();
        int k = costs[0].size();
        
        if(k == 1 && n > 1) return -1;
        else if(k == 0 || n == 0)   return -1;
        
        int f_min = INT_MAX, s_min = INT_MAX;
        for(int i = 0; i < k; i++){
            if(col_cost[0][i] < f_min){
                s_min = f_min;
                f_min = col_cost[0][i];
            }
            else if(col_cost[0][i] < s_min)
                s_min = col_cost[0][i];
        }
        for(int i = 1; i < n; i++){
            int n_f_min = INT_MAX, n_s_min = INT_MAX;
            for(int col = 0; col < k; col++){
                if(col_cost[i - 1][col] == f_min)
                    col_cost[i][col] += s_min;
                else
                    col_cost[i][col] += f_min;
                    
                if(col_cost[i][col] < n_f_min){
                    n_s_min = n_f_min;
                    n_f_min = col_cost[i][col];
                }
                else if(col_cost[i][col] < n_s_min)
                    n_s_min = col_cost[i][col];
            }
            f_min = n_f_min;
            s_min = n_s_min;
        }
        return f_min;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends