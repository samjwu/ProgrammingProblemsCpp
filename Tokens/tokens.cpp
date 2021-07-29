class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size()-1;
        while (l <= r) {
            if (tokens[l] <= P) {
                cout<<"buy"<<" "<<tokens[l]<<endl;
                P -= tokens[l]; 
                l++;
                score++;
            } else if (score > 0 && l != r) {
                cout<<"sell"<<" "<<tokens[r]<<endl;
                P += tokens[r];
                r--;
                score--;
            } else {
                return score;
            }
        }
        return score;
    }
};