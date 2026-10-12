class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split both sentences into words
    vector<string> s1 = splitSentence(sentence1);
    vector<string> s2 = splitSentence(sentence2);

    // Ensure s1 is the shorter sentence for comparison
    if (s1.size() > s2.size()) {
        swap(s1, s2);
    }

    int n = s1.size();
    int m = s2.size();

    // Two pointers approach to match from the front and back simultaneously
    int i = 0;
    int j = 0;

    // Match prefix
    while (i < n && s1[i] == s2[i]) {
        i++;
    }

    // Match suffix
    while (j < n - i && s1[n - 1 - j] == s2[m - 1 - j]) {
        j++;
    }

    // If all words in s1 are matched either as prefix or suffix
    return i + j == n;
}

vector<string> splitSentence(const string& sentence) {
    vector<string> words;
    string word;
    stringstream ss(sentence);
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}
};