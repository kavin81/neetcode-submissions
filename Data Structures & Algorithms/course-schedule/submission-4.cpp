#include <vector>
#include <queue>

using namespace std;

class Solution { 
public: 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { 
        vector<vector<int>> graph(numCourses); 
        vector<int> remaining_prereqs(numCourses, 0); 
        
        for(const vector<int>& edge : prerequisites){ 
            int course = edge[0]; 
            int prereq = edge[1]; 
            graph[prereq].push_back(course); 
            remaining_prereqs[course]++; 
        } 
        
        queue<int> ready_courses; 
        for(int course = 0; course < numCourses; course++) {
            if(remaining_prereqs[course] == 0) {
                ready_courses.push(course); 
            }
        }
        
        int completed_courses = 0; 
        while(!ready_courses.empty()){ 
            int curr = ready_courses.front(); 
            ready_courses.pop(); 
            completed_courses++; 
            
            for(int course : graph[curr]){ 
                remaining_prereqs[course]--; 
                if(remaining_prereqs[course] == 0) {
                    ready_courses.push(course); 
                }
            } 
        } 
        
        return completed_courses == numCourses; 
    } 
};
