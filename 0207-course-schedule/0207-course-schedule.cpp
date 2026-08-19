class Solution {
public:

    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited) {
        
        if (visited[course] == 1)
            return false;   // cycle

        if (visited[course] == 2)
            return true;    // already checked

        visited[course] = 1;

        for (int next : graph[course]) {
            if (!dfs(next, graph, visited))
                return false;
        }

        visited[course] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, graph, visited))
                return false;
        }

        return true;
    }
};