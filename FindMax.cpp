// Author Sean Davis

#include "FindMax.h"
#include <iostream>
#include <vector>

using namespace std;

void FindMax::Dijkstra(int n, int s, vertex *G, int d[], bool vis[])
{
    /*
     *   n:        顶点个数
     *   s:        源点
     *   G:        图的邻接矩阵
     * vis:        标记顶点是否已被访问
     *   d:        存储源点s到达其它顶点的最短距离
     * pre:        最短路径中v的前驱结点
     */

    // 初始化
    //bool vis= new bool[n] {false};
    d[s] = 0;

    // n次循环,确定d[n]数组
    for (int i = 0; i < n; i++)
    {
        // 找到距离s最近的点u,和最短距离d[u]
        int u = -1;
        int MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }

        // 找不到小于INF的d[u],说明剩下的顶点与起点s不连通
        if (u == -1)
        {
            return;
        }

        vis[u] = true;
        for (int k = 0; k < 4; k++)
        {
            // 遍历所有顶点，如果v未被访问 && 可以达到v && 以u为中介点使d[v]更小
            if (!vis[G[u].connectedPoint[k].pos] && G[u].connectedPoint[k].time != -1 && d[u] + G[u].connectedPoint[k].time < d[G[u].connectedPoint[k].pos])
            {
                d[G[u].connectedPoint[k].pos] = d[u] + G[u].connectedPoint[k].time;   // 更新d[v]
            }
        }
    }
}


FindMax::FindMax(int citySize, const StreetBlock *streets, int numStreets)
{
    v = citySize*citySize;
    size = citySize;
//    vector<int> inner(v, INF);
//    vector<vector<int> > a (v, inner);
    for (int i = 0; i < numStreets; i++)
    {
        int time, a, b;
        time = ((streets[i].endY - streets[i].startY) + (streets[i].endX - streets[i].startX)) * 1000000 / streets[i].speed;
        a = citySize * streets[i].startY + streets[i].startX;
        b = citySize * streets[i].startY + streets[i].startX;
        allVertex[a].connectedPoint[allVertex[a].pos].pos = b;
        allVertex[a].connectedPoint[allVertex[a].pos].time = time;
        allVertex[b].connectedPoint[allVertex[b].pos].pos = a;
        allVertex[b].connectedPoint[allVertex[b].pos].time = time;
        allVertex[a].pos++;
        allVertex[b].pos++;
    }
//    for (int i = 0; i < numStreets; i++)
//    {
//        int time;
//        time = streets[i].speed / 3600 * ((streets[i].endY - streets[i].startY) + (streets[i].endX - streets[i].startX));
//        a[citySize * streets[i].startY + streets[i].startX][citySize * streets[i].endY + streets[i].endX] = time;
//        a[citySize * streets[i].endY + streets[i].endX][citySize * streets[i].startY + streets[i].startX] = time;
//    }
//    for (int i = 0; i < citySize * citySize; i++)
//    {
//        a[i][i] = 0;
//    }
//    am = a;
} // FindMax()

void FindMax::find(Coordinate fireHouses[4], Coordinate *furthest, int *time)
{
    *time = 0;
    int d[4][v];
    for (int i = 0; i < 4; i++)
    {
        bool *vis= new bool[v] {false};
        Dijkstra(v, fireHouses[i].y * size + fireHouses[i].x, allVertex, d[i], vis);
    }
    int times[v];
    for (int i = 0; i < v; i++)
    {
        times[i] = INF;
        for (int j = 0; j < 4; j++)
        {
            if (d[j][i] < times[i])
            {
                times[i] = d[j][i];
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (times[i] != INF && times[i] > *time)
        {
            *time = times[i];
        }
    }

//    for (int i = 0; i < 4; i++)
//    {
//        int min = INF;
//        vector<bool> vis(v);
//        vector<int> d(v);
//        vector<int> pre(v);
//        Dijkstra(v, i, am, vis, d, pre);
//        for (int j = 0; j < 4; j++)
//        {
//            if (d[size * fireHouses[j].y + fireHouses[j].x] < min or min == -1)
//                min = d[size * fireHouses[j].y + fireHouses[j].x];
//            if (min != -1 && min < *time)
//            {
//                break;
//            }
//        }
//        if (min > *time)
//        {
//            *time = min;
//            furthest -> y = (i - (i % size)) / size;
//            furthest -> x = i % size;
//        }
//    }
} // find()

