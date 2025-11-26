class Solution:
    def findEvenNumbers(self, digits: list[int]) -> list[int]:
        ans = []
        for n in range(100,1000,2):
            copy = digits.copy()
            if int(str(n)[0]) in copy:
                copy.remove(int(str(n)[0]))
                if int(str(n)[1]) in copy:
                    copy.remove(int(str(n)[1]))
                    if int(str(n)[2]) in copy:
                        ans.append(n)
        return ans