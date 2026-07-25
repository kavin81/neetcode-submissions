class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> remaining_courses(numCourses,0);

        // 1. build graph deps for (b -> a) + indegree for each course
        for(const vector<int>& edge: prerequisites){
            int course = edge[0]; // course a
            int prereq = edge[1]; // course b

            // graph 
            graph[prereq].push_back(course);
            // indegree for each course or pre-reqs for each course
            remaining_courses[course]++;
        }

        queue<int> ready_courses;

        // courses with no deps
        for (int course = 0; course < numCourses; course++) 
            if (remaining_courses[course] == 0) 
                ready_courses.push(course);

        vector<int> order;


        while(!ready_courses.empty()){
            int curr = ready_courses.front();
            ready_courses.pop();
            order.push_back(curr);

            for(int course: graph[curr])
                if(--remaining_courses[course] == 0)
                    ready_courses.push(course);
        }

        if(order.size() != numCourses)
            return {};

        return order;
    }
    
};
