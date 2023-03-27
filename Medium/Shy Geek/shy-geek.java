//{ Driver Code Starts
import java.util.*;
import java.io.*;

public class Main{
    static BufferedReader br;
    static PrintWriter ot;
    public static void main(String[] args) throws IOException{
        
        br = new BufferedReader(new InputStreamReader(System.in));
        ot = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine());
        

        while(t-->0){
            Shop shop = new Shop();

            String s[] = br.readLine().trim().split(" ");
            
            int n = Integer.parseInt(s[0]);
            long k = Long.parseLong(s[1]);

            s = br.readLine().trim().split(" ");

            for(String x: s){
                shop.addChocolate(Integer.parseInt(x));
            }
            
            ot.println(new Solution(shop).find(n, k));
        }
        ot.close();
    }
    
    
}
class Shop{
    private static List<Integer> chocoloates;
    private static int countOfCalls;
    Shop(){
        chocoloates = new ArrayList<>();
        countOfCalls = 0;
    }
    public static void addChocolate(int price){
        chocoloates.add(price);
    }

    public static int get(int i){
        countOfCalls++;
        if(countOfCalls > 50 || i >= chocoloates.size() || i < 0)
            return -1;
        return chocoloates.get(i);
    }
}
// } Driver Code Ends


//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    
    static Shop shop;
    Solution(Shop shop){
        this.shop = shop;
    }
    static long find(int n, long k){
        long count = 0;
        int left = 0, right = n-1;
        
        // iterate until we spend our whole money
        while(k > 0){
            // placeholder to get max. choco price for curreny money{k} that we have
            int currMax = -1;
            
            // find max cost using Binary Search and assign it to {currMax}
            while(left <= right){
                int mid = (left+right)/2;
                int cost = shop.get(mid);
                
                if(cost > k){
                    // geek can not afford to buy
                    right = mid-1;
                } else {
                    // geek can buy and this cost might be a possible ans, but we will check for bigger
                    currMax = cost;
                    left = mid+1;
                }
            }
            // if no cost found, we got our ans, {or all the chocos are more costly than current* {k} value}
            if(currMax == -1) break;
            
            // count the no. of choco we can buy with {currMax}
            count += k/currMax;
            
            // update the rest coins left after buying
            k = k%currMax;
            
            // set low pointer to {0}, 
            // no need to set high pointer to end of the array as we can not afford those choco
            left = 0;
        }
        
        return count;
    }

}