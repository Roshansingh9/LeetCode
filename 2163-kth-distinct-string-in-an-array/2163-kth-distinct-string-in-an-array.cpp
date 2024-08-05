#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequency;
        
        
        for (const string& str : arr) {
            frequency[str]++;
        }
        
        
        vector<string> distinctStrings;
        for (const string& str : arr) {
            if (frequency[str] == 1) {
                distinctStrings.push_back(str);
            }
        }
        
       
        if (k <= distinctStrings.size()) {
            return distinctStrings[k - 1];
        } else {
            return "";
        }
    }
};
