class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int open = 0;
        int size = flowerbed.size();
        
        if (size == 1) {
            if (flowerbed[0] == 0) {
                flowerbed[0] = 1;
                open++;
            }
            return (open >= n);
        }
        
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            open++;
        }
        for (int i = 1; i < size - 1; i++) {
            if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                open++;
            }
        }
        if (flowerbed[size-2] == 0 && flowerbed[size-1] == 0) {
            flowerbed[size-1] = 1;
            open++;
        }
        
        return (open >= n);
    }
};