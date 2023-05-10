//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String s;
            s = br.readLine();

            Solution obj = new Solution();
            int res = obj.minimumSum(s);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int minimumSum(String str) {
        int n =  str.length(), l = 0, h = n-1, sum = 0;
        char prev = '1';
        while(l<=h){
            if(str.charAt(l) == '?' && str.charAt(h) == '?'){
                // no need to do anything
            }else if(str.charAt(l) == str.charAt(h)){
                if(prev != '1') sum += Math.abs((int)(prev-str.charAt(l)));  
                 prev = str.charAt(l);
            }else if(str.charAt(l) != '?' && str.charAt(h) == '?'){
                if(prev != '1') sum += Math.abs((int)(prev-str.charAt(l)));  
                prev = str.charAt(l);
            }else if(str.charAt(l) == '?' && str.charAt(h) != '?'){
                if(prev != '1') sum += Math.abs((int)(prev-str.charAt(h)));  
                prev = str.charAt(h);
            }else{
                return -1;
            }
            
                l++;
                h--;
        }

        return sum*2;
    }
}
