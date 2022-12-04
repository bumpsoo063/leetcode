#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        for (auto i = ++word1.begin(); i != word1.end(); i++) {
			*word1.begin() += *i; 
		}
		for (auto i = ++word2.begin(); i != word2.end(); i++) {
			*word2.begin() += *i; 
		}
		return *word1.begin() == *word2.begin();
    }
};