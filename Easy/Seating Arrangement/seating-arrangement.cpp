//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        
        if(n == 0)return 1;
        
        for(int i = 0; i < m; i++) {
            if(seats[i] == 0) {
                int l = 0, r = 0;
                
                if(i > 0)l = seats[i-1];
                if(i+1 < m)r = seats[i+1];
                
                if(!l and !r) {
                    seats[i] = 1;
                    
                    if(--n == 0)return 1;
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends