class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if (k % 2 == 0 or k % 5 == 0):
            return -1
        
        num = 1
        while True:
            if (num % k == 0):
                return len(str(num))
            
            num = int(str(num) + "1")
    
