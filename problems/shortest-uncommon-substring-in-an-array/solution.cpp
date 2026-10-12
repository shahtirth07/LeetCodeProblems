class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        def is_unique(sub, current_index):
            for i, string in enumerate(arr):
                if i != current_index and sub in string:
                    return False
            return True

        answer = []
        for i, string in enumerate(arr):
            n = len(string)
            found = False
            shortest = None
        
            for length in range(1, n + 1):
                substrings = sorted({string[j:j+length] for j in range(n - length + 1)})
                for sub in substrings:
                    if is_unique(sub, i):
                        if not found or sub < shortest:
                            shortest = sub
                            found = True
                if found:
                    break
        
            answer.append(shortest if found else "")
        return answer
