vector<vll> gr(n + 1, vll(n + 1, INF));
forn(i, 1, n + 1) gr[i][i] = 0;
forn(k, 1, n + 1)
{
  forn(i, 1, n + 1)
  {
    forn(j, 1, n + 1)
    {
      gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
    }
  }
}