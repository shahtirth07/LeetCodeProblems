class Solution {
public:
    int minAddToMakeValid(string s) {
         int leftCount = 0;
    int rightCount = 0;
    
    for (char c : s) {
        if (c == '(') {
            leftCount++;
        } else if (c == ')') {
            if (leftCount > 0) {
                leftCount--; // Match with a left parenthesis
            } else {
                rightCount++; // Unmatched right parenthesis
            }
        }
    }
    
    return leftCount + rightCount; // Unmatched left and right parentheses
}
};