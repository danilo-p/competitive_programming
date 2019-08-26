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

int main() {
    int horses_count,
        soldiers_count,
        affinities_count,
        horse_capacity,
        vertex_count,
        source_index,
        sink_index,
        horse_index,
        soldier_index,
        instance_number = 1;

    while (cin >> horses_count >> soldiers_count >> affinities_count) {
        vertex_count = horses_count + soldiers_count + 2;
        Dinic my_dinic = Dinic(vertex_count);
        source_index = 0;
        sink_index = vertex_count - 1;

        // Source to horses
        for(int horse_index = 1; horse_index <= horses_count; horse_index++) {
            cin >> horse_capacity;
            my_dinic.addEdge(source_index, horse_index, horse_capacity);
        }

        // Soldiers to sink
        for(int soldier_index = 1; soldier_index <= soldiers_count; soldier_index++) {
            my_dinic.addEdge(horses_count + soldier_index, sink_index, 1);
        }
    
        for(int i = 0; i < affinities_count; i++) {
            cin >> horse_index >> soldier_index;
            my_dinic.addEdge(horse_index, horses_count + soldier_index, 1);
        }

        cout << "Instancia " << instance_number << endl;
        cout << my_dinic.maxFlow(source_index, sink_index) << endl << endl;

        instance_number++;
    }

    return 0;
}
