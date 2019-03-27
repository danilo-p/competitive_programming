#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

#define MAX_STREETS 1000

using namespace std;

typedef pair<int, int> crossing_t;
typedef pair<int, crossing_t> edge_t;

// Global structures
int union_find[MAX_STREETS];
vector<edge_t> edges, mst_edges;

// Union Find
int uf_find(int x) {
    if (union_find[x] == x) return x;
    return uf_find(union_find[x]);
}
void uf_union(int x, int y) {
    int parent_x = uf_find(x), parent_y = uf_find(y);
    union_find[parent_x] = parent_y;
}

// Utility
int find_max_sound(int current_street, int target_street, int last_street, int max_sound_level_found) {
    edge_t edge;
    crossing_t crossing;
    int sound_level, max_found, i;

    // Check if we can find a way to target_street directly from current_street
    for (i = 0; i < mst_edges.size(); i++) {
        edge = mst_edges[i];
        sound_level = edge.first;
        crossing = edge.second;
        if (crossing == make_pair(current_street, target_street) || crossing == make_pair(target_street, current_street))
            return max(max_sound_level_found, sound_level);
    }

    // Recursively calls for all edges connected to current_street
    for (i = 0; i < mst_edges.size(); i++) {
        edge = mst_edges[i];
        sound_level = edge.first;
        crossing = edge.second;

        // Don't look back
        if (crossing == make_pair(current_street, last_street) || crossing == make_pair(last_street, current_street))
            continue;

        max_found = INT_MIN;

        if (crossing.first == current_street)
            max_found = find_max_sound(crossing.second, target_street, crossing.first,
                max(max_sound_level_found, sound_level));
        else if (crossing.second == current_street)
            max_found = find_max_sound(crossing.first, target_street, crossing.second,
                max(max_sound_level_found, sound_level));
        
        if (max_found > INT_MIN)
            return max_found;
    }

    return INT_MIN;
}

int main() {
    int streets, crossings, queries, i, street1, street2, sound_level, cases = 0;
    edge_t edge;
    crossing_t crossing;

    cin >> streets >> crossings >> queries;
    while (streets != 0 && crossings != 0 && queries != 0) {
        // Reset structures
        for (i = 0; i < streets; i++) union_find[i] = i;
        edges.clear();
        mst_edges.clear();

        // Fill the graph
        for (i = 0; i < crossings; i++) {
            cin >> street1 >> street2 >> sound_level;
            edges.push_back(make_pair(sound_level, make_pair(street1 - 1, street2 - 1)));
        }

        // Get the MST
        sort(edges.begin(), edges.end());

        i = 0;
        while (i < edges.size() && mst_edges.size() < streets - 1) {
            edge = edges[i];
            i++;

            crossing = edge.second;
            street1 = uf_find(crossing.first);
            street2 = uf_find(crossing.second);

            if (street1 != street2) {
                mst_edges.push_back(edge);
                uf_union(street1, street2);
            }
        }

        // Respond to queries
        if (cases > 0) cout << endl;
        cases++;
        cout << "Case #" << cases << endl;
        for (i = 0; i < queries; i++) {
            cin >> street1 >> street2;
            sound_level = find_max_sound(street1 - 1, street2 - 1, -1, INT_MIN);
            if (sound_level == INT_MIN) cout << "no path" << endl;
            else cout << sound_level << endl;
        }

        cin >> streets >> crossings >> queries;
    }

    return 0;
}