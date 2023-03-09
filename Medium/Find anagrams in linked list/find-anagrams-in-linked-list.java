//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class Node {
    char data;
    Node next;

    Node(char x) {
        data = x;
        next = null;
    }

    public static Node inputList(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine().trim()); // Length of Linked List

        String[] s = br.readLine().trim().split(" ");
        Node head = new Node((s[0].charAt(0))), tail = head;
        for (int i = 1; i < s.length; i++)
            tail = tail.next = new Node((s[i].charAt(0)));

        return head;
    }

    public static void printList(Node node, PrintWriter out) {
        while (node != null) {
            out.print(node.data + " ");
            node = node.next;
        }
        out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            Node head = Node.inputList(br);

            String S = br.readLine().trim();

            Solution obj = new Solution();
            ArrayList<Node> res = obj.findAnagrams(head, S);

            for (Node node : res) {
                Node temp = node;
                Node.printList(temp, out);
            }
            if (res.size() == 0) {
                out.println("-1");
            }
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java
/*

Definition for singly Link List Node
class Node
{
    char data;
    Node next;

    Node(char x){
        data = x;
        next = null;
    }
}

You can also use the following for printing the link list.
Node.printList(Node node);
*/

class Solution {
    public static Node createList(Node low, Node high){
        Node newList=new Node(' ');
        Node newListHead=newList;
        
        Node temp=low;
        while(temp!=high){
            char curr=temp.data;
            
            newList.next=new Node(curr);
            newList=newList.next;
            
            temp=temp.next;
        }
        
        return newListHead.next;
    }
    public static ArrayList<Node> findAnagrams(Node head, String s) {
        int savedTime=0;
        int time=1;
        int n=s.length();
        Map<Character, Integer> map=new HashMap<>();
        
        //store original string freq
        for(int i=0; i<n; i++){
            char curr=s.charAt(i);
            map.put(curr, map.getOrDefault(curr, 0) + 1);
        }
        
        Node low=head;
        Node high=head;
        Map<Character, Integer> currMap=new HashMap<>();
        ArrayList<Node> res=new ArrayList<>();
        
        //store initial freq
        int i=0;
        while(high!=null && i<n){
            char curr=high.data;
            
            //store into map
            currMap.put(curr, currMap.getOrDefault(curr, 0) + 1);
            
            high=high.next;
            i++;
            time++;
        }
        
        //check
        if(map.equals(currMap) && ((time-savedTime)>=n)){
            savedTime=time;
            //save
            Node list=createList(low, high);
            res.add(list);
        }
        
        //logic
        while(high!=null){
            char prev=low.data;
            char curr=high.data;
            
            //acquire
            currMap.put(curr, currMap.getOrDefault(curr, 0) + 1);
            
            //release
            if(currMap.get(prev)==1 ){
                currMap.remove(prev);
            }
            else{
                currMap.put(prev, currMap.get(prev) - 1);
            }
            
            //inc ptrs
            low=low.next;
            high=high.next;
            time++;
            
            //check
            if(map.equals(currMap) && ((time-savedTime)>=n)){
                savedTime=time;
                //save
                Node list=createList(low, high);
                res.add(list);
            }
            
        }
        
        return res;
    }
}