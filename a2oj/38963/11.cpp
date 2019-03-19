#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <cfloat>
#include <cmath>

using namespace std;

int main() {
	int cases, V, i, j;
    priority_queue <
    	pair< double, pair<double,double> >,
    	vector< pair< double, pair<double, double> > >,
    	greater< pair< double, pair<double, double> > >
    > heap;
    vector< pair<double, double> > freckles;
    pair<double, double> coordinates, other_coordinates;
    pair< double, pair<double,double> > weight_with_coordinates;
    set< pair<double, double> > mst;
    double x, y, weight;


	cin >> cases;
	while (cases--) {
		cin >> V;

		freckles.clear();

		for (i = 0; i < V; i++) {
			cin >> x >> y;
			coordinates = make_pair(x, y);
			freckles.push_back(coordinates);
			if (i == 0) heap.push(make_pair(0, coordinates));
			else heap.push(DBL_MAX, coordinates);
		}

		while (mst.size() < V) {
			weight_with_coordinates = heap.top();
			weight = weight_with_coordinates.first;
			coordinates = weight_with_coordinates.second;
			mst.insert(coordinates);

			for (i = 0; i < V; i++) {
				other_coordinates = freckles[i];
				if (coordinates == other_coordinates) continue;

				
			}
		}
	}

	return 0;
}