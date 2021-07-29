class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int n = courses.size();
        int taken = 0;
        int time = 0;
        
        for (int i=0; i<n; i++) {
            if (time + courses[i][0] <= courses[i][1]) {
                time += courses[i][0];
                courses[taken++] = courses[i];
            } else {
                int notTaken = i;
                
                for (int j=0; j<taken; j++) {
                    if (courses[j][0] > courses[notTaken][0]) {
                        notTaken = j;
                    }
                }
                
                if (courses[notTaken][0] > courses[i][0]) {
                    time += courses[i][0] - courses[notTaken][0];
                    courses[notTaken] = courses[i];
                }
            }     
        }
        
        return taken;
    }
};