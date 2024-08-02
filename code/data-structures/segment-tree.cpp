vll tr(4 * n, 0), ar(n);
void init(int node, int b, int e)
{
  if (b == e)
  {
    tr[node] = ar[b];
    return;
  }
  int mid = b + (e - b) / 2, l = node * 2 + 1, r = l + 1;
  init(l, b, mid);
  init(r, mid + 1, e);
  tr[node] = tr[l] + tr[r];
}
ll query(int node, int b, int e, int i, int j)
{
  if (b >= i && e <= j)
    return tr[node];
  int mid = b + (e - b) / 2, l = node * 2 + 1, r = l + 1;
  if (mid >= j)
    return query(l, b, mid, i, j);
  if (mid < i)
    return query(r, mid + 1, e, i, j);
  return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void update(int node, int b, int e, int pos, int val)
{
  if (b == e)
  {
    tr[node] = val;
    return;
  }
  int mid = b + (e - b) / 2, l = node * 2 + 1, r = l + 1;
  if (mid >= pos)
    update(l, b, mid, pos, val);
  else
    update(r, mid + 1, e, pos, val);
  tr[node] = tr[l] + tr[r];
}