class Solution:
	def printString(self, s, ch, count):
		c = 0
        for i in range(len(s)):
            if s[i] == ch:
                c += 1
                if count == c:
                    return s[i+1:]
        return ""


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()
        ch = input()[0]
        count = int(input())
        ob = Solution()
        answer = ob.printString(s, ch, count)

        print(answer)