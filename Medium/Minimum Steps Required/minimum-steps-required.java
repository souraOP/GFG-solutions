//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG{
	public static void main(String [] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test-- > 0) {
			String str = br.readLine();
			Solution obj = new Solution();
			System.out.println(obj.minSteps(str));
		}
	}
}

// } Driver Code Ends


//User function Template for Java

class Solution{
	int minSteps(String str) {
		//Write your code here
		int countA = 0, countB= 0, i;
		char cs[] = str.toCharArray();
		if(cs[0] == 'a'){
		    countA++;
		}else {
		    countB++;
		}
		for(i = 1; i < cs.length; i++){
	        if(cs[i-1] == 'a' && cs[i] == 'b'){
	            countB++;
	        }
	        if(cs[i - 1] == 'b' && cs[i] == 'a'){
	            countA++;
	        }
		}
	    return Math.min(countA, countB)+1;
	}
}