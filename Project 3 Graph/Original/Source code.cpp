#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, e, u, v, w, src, dest;
    int g[20][20] = {0}, d[20], p[20], vis[20] = {0};

    cout << "Enter buildings and pathways: ";
    cin >> n >> e;

    if(n < 1 || n > 20 || e < 0) return 0;

    cout << "Enter pathways (u v distance):\n";
    for(int i=0; i<e; i++) {
        cin >> u >> v >> w;
        if(u<0 || u>=n || v<0 || v>=n || w<=0) return 0;
        if(g[u][v]==0 || w<g[u][v])
            g[u][v] = g[v][u] = w;
    }

    cout << "Enter source and destination: ";
    cin >> src >> dest;
    if(src<0 || src>=n || dest<0 || dest>=n) return 0;

    for(int i=0; i<n; i++) {
        d[i] = INT_MAX;
        p[i] = -1;
    }
    d[src] = 0;

    for(int i=0; i<n; i++) {
        u = -1;
        for(int j=0; j<n; j++)
            if(!vis[j] && (u==-1 || d[j]<d[u]))
                u = j;

        if(u==-1 || d[u]==INT_MAX) break;
        vis[u] = 1;

        for(v=0; v<n; v++)
            if(g[u][v] && !vis[v] && d[u]+g[u][v]<d[v]) {
                d[v] = d[u]+g[u][v];
                p[v] = u;
            }
    }

    cout << "\nShortest distances:\n";
    for(int i=0; i<n; i++) {
        cout << i << " : ";
        if(d[i]==INT_MAX) cout << "Unreachable\n";
        else cout << d[i] << " meters\n";
    }

    if(d[dest]==INT_MAX) {
        cout << "No route available";
        return 0;
    }

    int path[20], k=0;
    for(v=dest; v!=-1; v=p[v])
        path[k++] = v;

    cout << "\nShortest Route: ";
    while(k--) {
        cout << path[k];
        if(k) cout << " -> ";
    }

    cout << "\nDistance: " << d[dest] << " meters";
    return 0;
}

