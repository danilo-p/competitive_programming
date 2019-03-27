#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cfloat>
#include <cmath>

using namespace std;

typedef pair<double, double> freckle_t;
typedef pair<double, freckle_t> distance_and_freckle_t;

double freckles_distance(freckle_t freckle1, freckle_t freckle2) {
    return sqrt(
        pow((freckle1.first - freckle2.first), 2)
        + pow((freckle1.second - freckle2.second), 2)
    );
}

int main() {
    int cases, V, i, j;
    double x, y, distance, other_distance;
    freckle_t freckle, other_freckle;
    distance_and_freckle_t distance_and_freckle;
    vector<freckle_t> freckles;
    vector<double> freckles_keys;
    set<freckle_t> mst;
    priority_queue <
        distance_and_freckle_t,
        vector<distance_and_freckle_t>,
        greater<distance_and_freckle_t>
    > heap;
    map<freckle_t, freckle_t> parent_freckle;

    cin >> cases;
    while (cases--) {
        cin >> V;

        heap = priority_queue <
            distance_and_freckle_t,
            vector<distance_and_freckle_t>,
            greater<distance_and_freckle_t>
        >();
        mst.clear();
        parent_freckle.clear();
        freckles.clear();
        freckles_keys.clear();

        for (i = 0; i < V; i++) {
            cin >> x >> y;
            freckle = make_pair(x, y);
            if (i == 0) distance_and_freckle = make_pair(0, freckle);
            else distance_and_freckle = make_pair(DBL_MAX, freckle);
            heap.push(distance_and_freckle);
            freckles_keys.push_back(distance_and_freckle.first);
            freckles.push_back(freckle);
        }

        while (mst.size() < V) {
            distance_and_freckle = heap.top();
            heap.pop();
            freckle = distance_and_freckle.second;

            // Discard the freckle clone
            if (mst.find(freckle) != mst.end()) continue;

            mst.insert(freckle);

            for (i = 0; i < V; i++) {
                other_freckle = freckles[i];

                if (mst.find(other_freckle) != mst.end()) continue;

                other_distance = freckles_distance(freckle, other_freckle);
                
                // Intentionally push a freckle clone
                if (other_distance < freckles_keys[i]) {
                    parent_freckle[other_freckle] = freckle;
                    heap.push(make_pair(other_distance, other_freckle));
                    freckles_keys[i] = other_distance;
                }
            }
        }

        distance = 0;
        for (i = 1; i < V; i++) 
            distance += freckles_distance(freckles[i], parent_freckle[freckles[i]]);

        printf("%.2f\n", distance);
        if (cases > 0) cout << endl;
    }

    return 0; 
}