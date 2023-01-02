#include <string>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
		int l = word.length(), cnt = 0;
		for (int i = 0; i < l; i++) {
			if (isupper(word[i]))
				++cnt;
		}
		if (cnt == 1 && isupper(word[0]))
			return true;
		if (cnt == l || cnt == 0)
			return true;
		return false;
	}
};
// class Solution {
// private:
// enum {
// 	Lower = 0,
// 	Upper = 1,
// 	First = 2,
// };
// public:
//     bool detectCapitalUse(string word) {
// 		int flag = Lower;
// 		int l = word.length();
// 		for (int i = 0, l = word.length(); i < l; i++) {
// 			if (i == 0) {
// 				if (isupper(word[i]))
// 					flag = Upper;
// 			} else if (i == 1) {
// 				if (isupper(word[i])) {
// 					if (flag == Lower)
// 						return false;
// 				} else {
// 					if (flag == Upper)
// 						flag = First;
// 				}
// 			} else {
// 				if (flag == First || flag == Lower) {
// 					if (isupper(word[i]))
// 						return false;
// 				} else {
// 					if (islower(word[i]))
// 						return false;
// 				}
// 			}
// 		}
// 		return true;
//     }
// };