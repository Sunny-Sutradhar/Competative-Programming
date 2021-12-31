#include<bits/stdc++.h>
using namespace std;
# define INF 9999999

typedef pair<int, int> edgeWeightPair;

class Graph
{
    int V;
    list<edgeWeightPair> *adj;
    vector<int> dist;

public:
    Graph(int V) ///Constructer
    {
        this->V = V;
        adj = new list<edgeWeightPair> [V];
        vector<int> temp(V,INF);
        dist = temp;
    }
    void addEdge(int u, int v, int w) ///adjacency List Development
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void Dijkstra(int src)
    {
        priority_queue< edgeWeightPair, vector <edgeWeightPair> , greater<edgeWeightPair> > pq;
        //vector<int> dist(V, INF); /// iiii
        ///vector<int> parent(V, -1);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty()) ///while(PQ is not empty)
        {
            int u = pq.top().second; ///u = PQ.top.second() ///u=src
            pq.pop();
            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) ///for(all the adjacent pairs  i ----> begin--end)
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight) ///Relaxation
                {
                    dist[v] = dist[u] + weight; /// dist[v] UPDATE
                    ///parent[v] = u;
                    pq.push(make_pair(dist[v], v)); ///PUSH INTO PQ
                }
            }
        }
    
    }
    int minimumCost(int x){
         return dist[x];
    }
};

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        Graph g(n);
        int x,y,c;
        for(int i=0;i<m;i++){
           cin>>x>>y>>c;
           //cout<<x-1<<" "<<y-1<<" "<<c<<endl; 
           g.addEdge(x-1,y-1,c);
        }

        g.Dijkstra(0);

        int q;
        cin>>q;
        while(q--){
            int a,k;
            cin>>a>>k;
            int cost = g.minimumCost(a-1);
            cost*=2;
            if(cost>=k)cout<<0<<endl;
            else{
               cout<<k-cost<<endl;
            }

        }

    }
}