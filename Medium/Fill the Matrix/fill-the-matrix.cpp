//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
     int solve(int n, int m, int x, int y){
        int mat[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=0;
            }
        }
        x--;
        y--;
        mat[x][y]=1;
        int ans=0;
        int r[4]={-1,0,0,1};
        int c[4]={0,1,-1,0};
        queue<pair<pair<int,int>,int>>q;
        q.push({{x,y},0});
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int cnt=q.front().second;
            ans=cnt;
            for(int i=0;i<4;i++){
                int temprow=row+r[i];
                int tempcol=col+c[i];
                if(temprow<0 || tempcol<0 ||temprow>=n ||tempcol>=m) continue;
                if(mat[temprow][tempcol]==0){
                    q.push({{temprow, tempcol},cnt+1});
                    mat[temprow][tempcol]=1;
                }
            }
            q.pop();
        }
        return ans;
    }
    int manhattan_distance(int n, int m,int x, int y){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans=max(ans, abs(x-i)+abs(y-j));
            }
        }
        return ans;
    }
    int minIteration(int N, int M, int x, int y){    
        // return solve(N,M,x,y);
        return manhattan_distance(N,M,x,y);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends