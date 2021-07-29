class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentToFilePath; // eg: {"abcd", "root/a/1.txt"}
        vector<vector<string>> ans;
        
        string dir, fileInfo, fileName, content;
        for (string path: paths) {
            stringstream ss(path);
            ss >> dir;
            while (ss >> fileInfo) {
                size_t openBracket = fileInfo.find("(");
                fileName = fileInfo.substr(0, openBracket);
                content = fileInfo.substr(openBracket+1, fileInfo.length() - openBracket - 2);
                contentToFilePath[content].push_back(dir + "/" + fileName);
            }
        }
        
        for (auto pair: contentToFilePath) {
            if (pair.second.size() > 1) {
                ans.push_back(pair.second);
            }
        }
        
        return ans;
    }
};