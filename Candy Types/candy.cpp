class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int maxEat = candyType.size() / 2;
        
        int numType = 0;
        set<int> typeSet;
        for (int candy: candyType) {
            if (typeSet.count(candy) == 0) {
                numType++;
                typeSet.insert(candy);
            }
        }
        
        return min(numType, maxEat);
    }
};