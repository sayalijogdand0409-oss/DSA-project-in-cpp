#include <iostream>
#include <climits>
using namespace std;

int g[20][20], d[20], p[20], n;

void dijkstra(int src) {
    bool vis[20] = {0};

    for(int i=0; i<n; i++) {
        d[i] = INT_MAX;
        p[i] = -1;
    }
    d[src] = 0;

    for(int i=0; i<n; i++) {
        int u = -1;

        for(int j=0; j<n; j++)
            if(!vis[j] && (u==-1 || d[j]<d[u]))
                u = j;

        if(u==-1 || d[u]==INT_MAX) break;
        vis[u] = true;

        for(int v=0; v<n; v++)
            if(g[u][v]>0 && !vis[v] &&
               d[u]+g[u][v]<d[v]) {
                d[v] = d[u]+g[u][v];
                p[v] = u;
            }
    }

    cout<<"\nShortest Distances:\n";
    for(int i=0; i<n; i++) {
        cout<<src<<" to "<<i<<" = ";
        if(d[i]==INT_MAX) cout<<"Unreachable\n";
        else cout<<d[i]<<"\n";
    }
}

void path(int v) {
    if(p[v]!=-1) {
        path(p[v]);
        cout<<" -> ";
    }
    cout<<v;
}

int main() {
    int e,u,v,w,src,dest,ch;

    cout<<"Enter vertices and edges: ";
    cin>>n>>e;
    if(n<1 || n>20 || e<0) return 0;

    cout<<"Enter edges (u v weight):\n";
    for(int i=0; i<e; i++) {
        cin>>u>>v>>w;
        if(u<0 || u>=n || v<0 || v>=n || w<=0)
            return 0;
        g[u][v]=g[v][u]=w;
    }

    cout<<"Enter source: ";
    cin>>src;
    if(src<0 || src>=n) return 0;
    dijkstra(src);

    do {
        cout<<"\n1.Change Source";
        cout<<"\n2.Display Shortest Path";
        cout<<"\n3.Update Edge Weight";
        cout<<"\n4.Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch) {
        case 1:
            cout<<"Enter new source: ";
            cin>>src;
            if(src>=0 && src<n) dijkstra(src);
            else cout<<"Invalid source\n";
            break;

        case 2:
            cout<<"Enter destination: ";
            cin>>dest;
            if(dest<0 || dest>=n)
                cout<<"Invalid destination\n";
            else if(d[dest]==INT_MAX)
                cout<<"No path available\n";
            else {
                cout<<"Shortest Path: ";
                path(dest);
                cout<<"\nDistance: "<<d[dest]<<"\n";
            }
            break;

        case 3:
            cout<<"Enter edge (u v) and new weight: ";
            cin>>u>>v>>w;
            if(u>=0 && u<n && v>=0 && v<n &&
               g[u][v]>0 && w>0) {
                g[u][v]=g[v][u]=w;
                dijkstra(src);
            }
            else cout<<"Invalid edge or weight\n";
            break;
        }
    }while(ch!=4);

    return 0;
}
