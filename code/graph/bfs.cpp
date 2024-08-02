vector<vector<int>> gr(n);
queue<int> q;
vector<bool> vis(n, 0);
q.push(0);
vis[0] = 1;
while (q.size())
{
  int node = q.front();
  q.pop();
  forn(auto v : gr[node])
  {
    if (!vis[v])
    {
      q.push(v);
      vis[v] = 1;
    }
  }
}