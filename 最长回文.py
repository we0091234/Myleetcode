

def longestPalindrome(s: str) -> str:
        n = len(s)
        res = ""
        def helper(i,j):
            while i >= 0 and j < n and s[i] == s[j]:
                i -= 1
                j += 1
            if len(res) < j - i -1 :
                res = s[i+1:j]
        for i in range(n):
            helper(i,i)
            helper(i,i+1)
        return res

print(longestPalindrome("abca"))