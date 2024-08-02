vector<vector<pair<ll, ll>>> gr(n + 1);
vll dis(n + 1, INF);
dis[1] = 0;
forn(i, 0, n - 1)
{
  bool modif = 0;
  forn(node, 1, n + 1)
  {
    if (dis[node] == INF)
      continue;
    for (auto [v, w] : gr[node])
      if (dis[node] + w < dis[v])
      {
        dis[v] = dis[node] + w;
        modif = 1;
      }
  }
  if (!modif)
    break;
}
// Cycle Check
bool cycle = 0;
forn(node, 1, n + 1)
{
  if (dis[node] == INF)
    break;
  for (auto [v, w] : gr[node])
    if (dis[node] + w < dis[v])
      cycle = 1;
  if (cycle)
    break;
}