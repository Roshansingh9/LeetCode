class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int drunk = 0;

        while (numBottles > 0 || empty >= numExchange) {
            if (numBottles > 0) {
                drunk += numBottles;
                empty += numBottles;
                numBottles=0;
            }
            if(empty>=numExchange){
                empty-=numExchange;
                numBottles=1;
                numExchange++;
            }
        }
        return drunk;
    }
};