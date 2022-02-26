#ifndef _FINDMAX_H
#define	_FINDMAX_H

#include <vector>
#include "RunFind.h"

using namespace std;

struct CVertex{
    int pos{};
    int time = -1;
};

struct vertex{
    int pos = 0;
    CVertex *connectedPoint = new CVertex[4];
};

class FindMax {
public:
  FindMax(int citySize, const StreetBlock *streets, int numStreets);
  void find(Coordinate fireHouses[4], Coordinate *furthest, int *time);
  const int INF = 1e9;
  int v;
  int size;
  vertex *allVertex = new vertex[v];
  vector<vector<int>> am;
  void Dijkstra(int n, int s, vertex *G, int d[], bool vis[]);
}; // class FindMax

#endif	/* _FINDMAX_H */

