#include <bits/stdc++.h>
using namespace std;

typedef struct edge {
  int to;
  int nxt;
} edge_t;

int N, M;
int cnt = 1;
int heads[100010];
edge_t edges[100010];
int ans[100010];

int main() {
  memset(heads, -1, sizeof(heads));

  cin >> N >> M;

  for (int i = 1; i < M + 1; ++i) {
    int U, V;
    cin >> U >> V;
    edge_t* e = &edges[cnt];
    e->to = V;
    e->nxt = heads[U];
    heads[U] = cnt++;
  }

}