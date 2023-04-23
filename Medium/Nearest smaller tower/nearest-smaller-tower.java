//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG{
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test-- > 0) {
			int n = Integer.parseInt(br.readLine());
			int [] arr = new int[n];
			String [] str = br.readLine().trim().split(" ");
			for(int i = 0; i < n; i++)
				arr[i] = Integer.parseInt(str[i]);
			Solution ob = new Solution();
			int [] ans = ob.nearestSmallestTower(arr);
			for(int i = 0; i < n; i++)
				System.out.print(ans[i]+" ");
			System.out.println();
		}
		
	}
}
// } Driver Code Ends


//User function Template for Java


class Solution{
	int [] nearestSmallestTower(int [] arr){
		Stack<Integer> s1=new Stack<>();
		Stack<Integer> s2=new Stack<>();
        int[] res=new int[arr.length];
        for(int i=0;i<arr.length;i++){
            if(s1.isEmpty()){
                s1.push(i); res[i]=Integer.MAX_VALUE;
            }
            else {
                while(!s1.isEmpty()&&arr[i]<=arr[s1.peek()])
                    s1.pop();
                res[i]=s1.isEmpty() ? Integer.MAX_VALUE : s1.peek();
                s1.push(i);
            }
        }
        for(int i=arr.length-1;i>=0;i--){
            if(s2.isEmpty()){
                s2.push(i);
            }
            else {
                while(!s2.isEmpty()&&arr[i]<=arr[s2.peek()])
                    s2.pop();
                int x=s2.isEmpty()?Integer.MAX_VALUE : s2.peek();
                if(res[i]==Integer.MAX_VALUE)
                    res[i]=x;
                else if(x==Integer.MAX_VALUE){}
                else {
                    if(x-i<i-res[i])
                        res[i]=x;
                    else if(x-i==(i-res[i])&&arr[x]<arr[res[i]])
                        res[i]=x; 
                }
                s2.push(i);
            }
        }
        for(int i=0;i<res.length;i++){
            if(res[i]==Integer.MAX_VALUE)
                res[i]=-1;
        }
        return res;
	}
}