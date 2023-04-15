//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int n, vector<int> &A, vector<int> &B) {
        // code here 
        long long int sa=0,sb=0;
        long long int oa=0,ob=0;
        vector<int>oaa,eaa,obb,ebb;
        for(auto x:A){
            sa+=x;
            if((x%2+2)%2==1){
                oa++;
                oaa.push_back(x);
            }
            else eaa.push_back(x);
        }
        for(auto x:B){
            sb+=x;
            if((x%2+2)%2==1){
                ob++;
                obb.push_back(x);
            }
            else ebb.push_back(x);
        }
        //cout<<sa<<" "<<sb<<" "<<oa<<" "<<ob<<endl;
        if(sa!=sb or oa!=ob)return -1;
        
        sort(oaa.begin(),oaa.end());
        sort(eaa.begin(),eaa.end());
        sort(obb.begin(),obb.end());
        sort(ebb.begin(),ebb.end());
        long long int ans=0;
        for(int i=0;i<oaa.size();i++){
            ans+=abs(oaa[i]-obb[i]);
        }
        for(int i=0;i<eaa.size();i++){
            ans+=abs(eaa[i]-ebb[i]);
        }
        
        return (ans)/4;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends