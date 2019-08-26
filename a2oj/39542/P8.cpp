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
    ll people_count,
        interest_count,
        vertex_count,
        source_index,
        sink_index,
        person_1_index,
        person_2_index,
        max_flow;

    while (cin >> people_count >> interest_count) {
        vertex_count = (people_count * 2) + 2;
        Dinic my_dinic = Dinic(vertex_count);
        source_index = 0;
        sink_index = vertex_count - 1;

        // Source to people
        for(int person_1_index = 1; person_1_index <= people_count; person_1_index++)
            my_dinic.addEdge(source_index, person_1_index, 1);

        // People to sink
        for(int person_1_index = 1; person_1_index <= people_count; person_1_index++)
            my_dinic.addEdge(people_count + person_1_index, sink_index, 1);

        for(int i = 0; i < interest_count; i++) {
            cin >> person_1_index >> person_2_index;
            person_1_index++;
            person_2_index++;
            my_dinic.addEdge(person_1_index, people_count + person_2_index, 1);
        }

        max_flow = my_dinic.maxFlow(source_index, sink_index);
        cout << (max_flow == people_count ? "YES" : "NO") << endl;
    }

    return 0;
}
