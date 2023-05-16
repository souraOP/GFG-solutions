//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String srgs[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String s1[] = in.readLine().trim().split("\\s+");
            int n = Integer.parseInt(s1[0]);
            int m = Integer.parseInt(s1[1]);
            String s = in.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.isPossible(n, m, s));
        }
    }
}
// } Driver Code Ends


// User function Template for 

class Solution{
    static int isPossible(int n, int m, String s){
        // code here
        int lowr = 0, lowc = 0, highr = 0, highc = 0, r = 0, c= 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'L'){
                c--;
            }
            if(s.charAt(i) == 'R'){
                c++;
            }
            if(s.charAt(i) == 'D'){
                r--;
            } 
            if(s.charAt(i) == 'U'){
                r++;
            }
            lowr = Math.min(lowr, r);
            lowc = Math.min(lowc, c);
            highr = Math.max(highr, r);
            highc = Math.max(highc, c);
        }
        if(highr - lowr < n && highc - lowc < m){
            return 1;
            
        }
        return 0;
        
    }
}