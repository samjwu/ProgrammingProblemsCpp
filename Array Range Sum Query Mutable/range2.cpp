struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode *left, *right;
    
    SegmentTreeNode(int a, int b) {
        start = a;
        end = b;
        sum = 0;
        left = nullptr;
        right = nullptr;
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        updateTree(index, val, root);
    }
    
    int sumRange(int left, int right) {
        return getSum(left, right, root);
    }
    
private:
    SegmentTreeNode *root;
    
    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        SegmentTreeNode *root = new SegmentTreeNode(start,end);
        
        if (start == end) {
            root->sum = nums[start];
            return root;
        }
        
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid+1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    int updateTree(int i, int val, SegmentTreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int diff;
        
        if (root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        
        if (i <= mid) {
            diff = updateTree(i, val, root->left);
        } else {
            diff = updateTree(i, val, root->right);
        }
        
        root->sum += diff;
        
        return diff;
    }
    
    int getSum(int i, int j, SegmentTreeNode *root) {
        if (!root) {
            return 0;
        }
        
        if (root->start == i && root->end == j) {
            return root->sum;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        
        if (j <= mid) {
            return getSum(i, j, root->left);
        } 
        if (i > mid) {
            return getSum(i, j, root->right);
        }
        
        return getSum(i, mid, root->left) + getSum(mid+1, j, root->right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */