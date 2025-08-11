#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ls;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                ls.push_back(asteroids[i]);
            } else {
                bool destroyed = false;
                while (!ls.empty() && ls.back() > 0) {
                    if (abs(asteroids[i]) > ls.back()) {
                        ls.pop_back(); 
                        continue;
                    } else if (abs(asteroids[i]) == ls.back()) {
                        ls.pop_back(); 
                        destroyed = true;
                        break;
                    } else { 
                        
                        destroyed = true;
                        break;
                    }
                }
                if (!destroyed) {
                    ls.push_back(asteroids[i]);
                }
            }
        }
        return ls;
    }
};
