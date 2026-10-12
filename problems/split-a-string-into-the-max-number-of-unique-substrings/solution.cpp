class Solution
{
public:
    int maxUniqueSplit(std::string s)
    {
        std::unordered_set<std::string> seen;
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const std::string &s, int start, std::unordered_set<std::string> &seen)
    {
        if (start == s.length())
        {
            return 0; // No more characters to process
        }

        int maxCount = 0;

        // Try all possible end indices for the current substring
        for (int end = start + 1; end <= s.length(); ++end)
        {
            std::string currentSubstring = s.substr(start, end - start);

            if (seen.find(currentSubstring) == seen.end())
            {                                  // Unique substring
                seen.insert(currentSubstring); // Mark this substring as seen

                // Recur for the remaining string and update the maximum count
                maxCount = std::max(maxCount, 1 + backtrack(s, end, seen));

                seen.erase(currentSubstring); // Backtrack
            }
        }

        return maxCount; // Return the maximum count of unique substrings
    }
};