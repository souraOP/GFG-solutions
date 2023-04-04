//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    static class FastReader{ 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
            } 
            return st.nextToken(); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
            return str; 
        } 

        Integer nextInt(){
            return Integer.parseInt(next());
        }

        Long nextLong(){
            return Long.parseLong(next());
        }
    }
    
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        int t = sc.nextInt(); // Inputting the testcases
        PrintWriter out = new PrintWriter(System.out);
        while (t-- > 0) {

            int i = 0;
            int N = sc.nextInt();

            int arr[] = new int[(int)(N)];

            for (i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }

            Solution ob = new Solution();
            out.println(ob.countSpecialNumbers(N, arr));
        }
        out.flush();
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int countSpecialNumbers(int N, int arr[]) {
        // Code here
        int answer = 0;
        int max = 0;
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<N;i++){
            max = Math.max(max,arr[i]);
            if(map.containsKey(arr[i])){
                map.put(arr[i],map.get(arr[i])+1);
            }else{
                map.put(arr[i],1);
            }
        }
        for(int i=0;i<N;i++){
            int num = arr[i];
            if(map.get(num)>1){
                answer++;
                continue;
            }
            if(num == 1){
                continue;
            }
            ArrayList<Integer> al = fun(arr[i]);
            for(int j: al){
                if(j != 1 && (map.containsKey(j) || map.containsKey(num/j))){
                    answer++;
                    break;
                }else if(j== 1 && map.containsKey(j)){
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
    public ArrayList<Integer> fun(int b){
        ArrayList<Integer> al =new ArrayList<>();
        al.add(1);
        for(int i=2;i*i<=b;i++){
            if(b%i == 0){
                al.add(i);
            }
        }
        return al;
    }
    
}