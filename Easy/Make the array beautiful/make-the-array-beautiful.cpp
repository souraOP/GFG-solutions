//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
    vector<int> ans;
        if(arr.empty()) return ans; 
        if(arr.size()<=1) return {arr[0]};
        
         ans.push_back(arr[0]);

        for(int i = 1 ; i < arr.size();i++){
            int n = ans.size();
            if(n>0){
                if(( arr[i]<0 && ans[n-1]>=0) || (arr[i]>=0 && ans[n-1]<0) ){
                    ans.pop_back();
                    continue;
                }
            }
                ans.push_back(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends