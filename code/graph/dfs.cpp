vector<bool> vis(1e5, 0);
vector<vi> gr(1e5);
void dfs(int node)
{
  if (vis[node])
    return;
  vis[node] = 1;
  cout << "Visitando: " << node << endl;
  forn(i, 0, gr[node].size()) dfs(gr[node][i]);
  return;
}
