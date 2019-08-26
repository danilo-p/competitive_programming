#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct Edge
{
    int v, rev;
    ll cap;
    Edge(int v_, ll cap_, int rev_) : v(v_), rev(rev_), cap(cap_) {}
};

struct Dinic
{
    vector<vector<Edge> > g;
    vector<int> level;
    queue<int> q;
    ll flow;
    int n;

    Dinic(int n_) : g(n_), level(n_), n(n_) {}

    void addEdge(int u, int v, ll cap)
    {
        if(u == v) return;
        Edge e(v, cap, int(g[v].size()));
        Edge r(u, 0, int(g[u].size()));
        g[u].push_back(e);
        g[v].push_back(r);
    }

    bool buildLevelGraph(int src, int sink)
    {
        fill(level.begin(), level.end(), -1);
        while(not q.empty()) q.pop();
        level[src] = 0;
        q.push(src);
        while(not q.empty())
        {
            int u = q.front();
            q.pop();
            for(vector<Edge>::iterator e=g[u].begin();e!=g[u].end();e++)
            {
                if(not e->cap or level[e->v] != -1) continue;
                level[e->v] = level[u] + 1;
                if(e->v == sink) return true;
                q.push(e->v);
            }
        }
        return false;
    }

    ll blockingFlow(int u, int sink, ll f)
    {
        if(u == sink or not f) return f;
        ll fu = f;
        for(vector<Edge>::iterator e=g[u].begin();e!=g[u].end();e++)
        {
            if(not e->cap or level[e->v] != level[u] + 1) continue;
            ll mincap = blockingFlow(e->v, sink, min(fu, e->cap));
            if(mincap)
            {
                g[e->v][e->rev].cap += mincap;
                e->cap -= mincap;
                fu -= mincap;
            }
        }
        if(f == fu) level[u] = -1;
        return f - fu;
    }

    ll maxFlow(int src, int sink)
    {
        flow = 0;
        while(buildLevelGraph(src, sink))
            flow+= blockingFlow(src, sink, numeric_limits<ll>::max());
        return flow;
    }
};
int main()
{
   int n,m;
   cin>>n>>m;
   Dinic my_dinic = Dinic(n); // vertices 0 a n-1
   for(int i=0;i<m;i++)
   {
      int u,v,c;
      cin>>u>>v>>c;
      u--, v--;
      my_dinic.addEdge(u,v,c);
      my_dinic.addEdge(v,u,c);
   }
   cout<<my_dinic.maxFlow(0,n-1)<<endl;
   return 0;
}
