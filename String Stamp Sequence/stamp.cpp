class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if (stamp.compare(target) == 0) {
            return {0};
        }
        
        vector<int> ans;
        int slen = stamp.length();
        int nstamps = target.length() - slen + 1;
        int i, j;
        bool sdiff;
        bool tdiff = true;
        
        while (tdiff) {
            tdiff = false;
            
            for (i=0; i<nstamps; i++) {
                sdiff = false;
                
                for (j=0; j<slen; j++) {
                    if (target[i+j] == '*') {
                        continue;
                    } else if (target[i+j] != stamp[j]) {
                        break;
                    } else {
                        sdiff = true;
                    }
                }
                
                if (j == slen && sdiff) {
                    tdiff = true;
                    
                    for (j=i; j<slen+i; j++) {
                        target[j] = '*';
                    }
                    
                    ans.push_back(i);
                }
            }
        }
        
        for (i=0; i<target.size(); i++) {
            if (target[i] != '*') {
                return {};
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};