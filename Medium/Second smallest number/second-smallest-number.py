#User function Template for python3

class Solution:
    def secondSmallest(self, s, D):
        num = [None]*D
        for i in range(D-1, 0, -1):
            d = min(s-1, 9)
            num[i] = d
            s -= d
        if s > 9:
            return "-1"
        num[0] = s
        
        i = D-1
        while i > 0:
            if num[i] != 0 and num[i-1] != 9:
                num[i] -= 1
                num[i-1] += 1
                return "".join(str(x) for x in num)
            i -= 1
        return "-1"

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S,D=map(int,input().strip().split(" "))

        ob = Solution()
        print(ob.secondSmallest(S,D))
# } Driver Code Ends