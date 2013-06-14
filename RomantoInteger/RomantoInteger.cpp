class Solution {
public:
    int romanToInt(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int hash[256];
		hash['I'] = 1; hash['V'] = 5; 
		hash['X'] = 10; hash['L'] = 50; 
		hash['C'] = 100; hash['D'] = 500;
		hash['M'] = 1000;

		int result = 0;
		int num = 0;
		for (size_t i = 0; i < s.size(); i++) {
			if (hash[s[i]] == num) {
				num += hash[s[i]];
			} 
			else if (hash[s[i]] > num) {
				if (num) {
					result += hash[s[i]] - num;
					num = 0;
				}
				else num = hash[s[i]];
			}
			else {
				result += num;
				num = hash[s[i]];
			}
		}
		if (num) result += num;
		return result;
	}
};