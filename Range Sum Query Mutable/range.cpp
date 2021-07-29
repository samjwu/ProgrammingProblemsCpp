class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        numBlocks = (int) ceil((double) n / sqrt((double) n));
        blocks = vector<int>(numBlocks);
        for (int i=0; i<n; i++) {
            blocks[i / numBlocks] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int blockIndex = index / numBlocks;
        blocks[blockIndex] += val - nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int startBlock = left / numBlocks;
        int endBlock = right / numBlocks;
        
        if (startBlock == endBlock) {
            for (int i=left; i<=right; i++) {
                sum += nums[i];
            }   
        } else {
            for (int i=left; i<=(startBlock + 1)*numBlocks - 1; i++) {
                sum += nums[i];
            }
            for (int i=startBlock + 1; i<=endBlock-1; i++) {
                sum += blocks[i];
            }
            for (int i=endBlock*numBlocks; i<=right; i++) {
                sum += nums[i];
            }
        }
        return sum;
    }
    
private:
    int n, numBlocks;
    vector<int> nums;
    vector<int> blocks;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */