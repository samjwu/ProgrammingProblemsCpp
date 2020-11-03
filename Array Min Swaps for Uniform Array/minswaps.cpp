class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int flips = -1;
        unordered_map<int, int> mapa, mapb, mapab;
        for (int i=0; i<A.size(); i++) {
            mapa[A[i]]++;
            mapb[B[i]]++;
            if (A[i] == B[i]) {
                mapab[A[i]]++;
            }
        }
        for (int i=1; i<=6; i++) {
            if ((mapa[i] + mapb[i] - mapab[i]) == A.size()) {
                flips = A.size() - max(mapa[i], mapb[i]);
                return flips;
            }
        }
        return flips;
    }
};