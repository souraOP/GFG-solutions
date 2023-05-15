#User function Template for python3

from math import inf, log
class Solution:
    def cuts(self, s):
        n = len(s)
        dp = [inf]*n + [0]
        for i in range(n-1, -1, -1):
            if s[i] == '0':
                continue
            num = 0
            for j in range(i, n):
                num = num*2 + int(s[j])
                if 5**int(log(num, 5)) == num:
                    dp[i] = min(dp[i], dp[j+1] + 1)
    
        return dp[0] if dp[0] != inf else -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        print(solObj.cuts(s))

# } Driver Code Ends