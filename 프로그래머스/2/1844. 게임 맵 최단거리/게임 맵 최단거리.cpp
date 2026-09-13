#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size(), m = maps.at(0).size();
    queue<vector<int>> q;
    
    int dy[4] = {0,0,1,-1}, dx[4] = {1,-1,0,0};
    vector<vector<bool>> vis(n);
    for (int i=0; i<n; i++)
        vis.at(i).resize(m, false);
    
    q.push({0,0});
    vis.at(0).at(0) = true;
    
    vector<vector<int>> dist(n);
    for (int i=0; i<n; i++)
        dist.at(i).resize(m, 0);
    dist.at(0).at(0) = 1;
    
    while (!q.empty() && !vis.at(n-1).at(m-1)){
        vector<int> pos = q.front();
        q.pop();
        int y=pos.at(0), x=pos.at(1);
        
        for (int i=0; i<4; i++){
            int ny=y+dy[i], nx=x+dx[i];
            
            if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if (maps.at(ny).at(nx) == 0) continue;
            if (vis.at(ny).at(nx)) continue;
            
            q.push({ny, nx});
            vis.at(ny).at(nx) = true;
            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
        }
    }
    
    if (vis.at(n-1).at(m-1)) return dist.at(n-1).at(m-1);
    else return -1;
}