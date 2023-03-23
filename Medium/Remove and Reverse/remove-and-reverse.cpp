//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
       
       unordered_map<char,int> ct;
       
       for(int i=0; i<S.size(); i++){
           ct[S[i]]++;
       }
       
       bool f=0;
       int i=0;
     
     while(true){
         
         if(S.size()==1) return S;
         
         if(ct[S[i]]>1){
             ct[S[i]]--;
             S.erase(i,1);
             
             if(f==0){
                 i=S.size()-1;
                 f=1;
             }else{
                 i=0;
                 f=0;
             }
             
             continue;
         }else if(S.size()==ct.size()){
             if(f==1) reverse(S.begin(),S.end());
             return S;
         }
         
         if(f==0) i++;
         else i--;
     }
     
       
       return "";
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends