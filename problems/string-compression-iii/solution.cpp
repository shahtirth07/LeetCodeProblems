class Solution
{
public:
    string compressedString(string word)
    {
        std::string print = ""; // Initialize result string

        for (int i = 0; i < word.length(); ++i)
        {
            char c = word[i];
            int count = 1;

            // Count consecutive occurrences of the character `c`
            while (i + 1 < word.length() && word[i + 1] == c && count < 9)
            {
                count++;
                i++;
            }

            // Append character and its count to the result string
            print += std::to_string(count);
            print += c;
        }

        return print;
    }
};