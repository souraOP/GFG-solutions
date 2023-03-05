//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int n;
            n = Integer.parseInt(br.readLine());
            
            Solution obj = new Solution();
            int res = obj.noConseBits(n);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int noConseBits(int n) {
        // code here
        String res = "";
            int curr = 0;
        for(int i = 31;i>=0;i--){
            // System.out.println(i+" "+(n & (1 << (i))));
            if((n & (1 << (i))) == 0) curr = 0;
            else  curr++;
            if(curr == 3){
                curr = 0;
                res += "0";
            }else{
                if((n & (1 << (i))) == 0) res += "0";
                else res += "1";
            }
        }
        int ans = 0;
        for(int i = 0;i<res.length();i++){
            if(res.charAt(i) == '1') ans += (int)Math.pow(2, 32-i-1);
        }
        
        return ans;
    }
}
        
