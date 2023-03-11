//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {

        //code here

        int max = -1;

        int row_num =0;

        vector<int> res;

        for(int i= 0 ; i<N ; i++){

            int one_count = count(mat[i].begin(), mat[i].end(),1);

            if(one_count>max){

                max = one_count;

                row_num = i;

            }

        }

        res.push_back(row_num);

        res.push_back(max);

        return res;

    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends