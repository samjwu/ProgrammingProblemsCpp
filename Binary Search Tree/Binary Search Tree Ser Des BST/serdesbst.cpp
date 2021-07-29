/**
 * Definition for a binary tree node
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes tree to a single string
    string serialize(TreeNode* root) {
        string code = encodeHelper(root);
        
        return code;
    }
    
    string encodeHelper(TreeNode* root) {
        if (root == nullptr) {
            return " nil";
        }
        
        return " " + to_string(root->val) + encodeHelper(root->left) + encodeHelper(root->right);
    }

    // Decodes encoded data to tree
    TreeNode* deserialize(string data) {
        stringstream datastream(data);
 
        TreeNode* root = decodeHelper(datastream);
        
        return root;
    }
    
    TreeNode* decodeHelper(stringstream& datastream) {
        string val;
        datastream >> val;
        
        if (val == "nil") {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = decodeHelper(datastream);
        node->right = decodeHelper(datastream);
        
        return node;
    }
};

// Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;