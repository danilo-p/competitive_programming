#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

#define ASCII_A 65
#define PLACES_COUNT 26

using namespace std;

typedef pair<int, int> street_t;

set<street_t> only_young_streets, only_miguel_streets;
set<int> reachable_by_young, reachable_by_miguel;
vector<int> reachable_by_both;
vector< pair<int, char> > reachable_by_both_distances;
int city_map[PLACES_COUNT][PLACES_COUNT];

void reset_city() {
    only_young_streets.clear();
    only_miguel_streets.clear();
    reachable_by_young.clear();
    reachable_by_miguel.clear();
    reachable_by_both.clear();
    reachable_by_both_distances.clear();
    for (int i = 0; i < PLACES_COUNT; i++)
        for (int j = 0; j < PLACES_COUNT; j++)
            city_map[i][j] = -1;
}

bool can_young_use(street_t street) {
    return only_young_streets.find(street) != only_young_streets.end();
}

bool can_miguel_use(street_t street) {
    return only_miguel_streets.find(street) != only_miguel_streets.end();
}

void discover_reachable_places(bool young, int current_place) {
    street_t street;

    if (!young) {
        reachable_by_miguel.insert(current_place);
    } else {
        reachable_by_young.insert(current_place);
        if (reachable_by_miguel.find(current_place) != reachable_by_miguel.end()) {
            reachable_by_both.push_back(current_place);
        }
    }

    for (int i = 0; i < PLACES_COUNT; i++) {
        if (
            // If the street exists
            city_map[current_place][i] != -1
            // If can navigate
            && (
                (young && can_young_use(make_pair(current_place, i)))
                || (!young && can_miguel_use(make_pair(current_place, i)))
            )
            // If didn't pass before
            && (
                (young && reachable_by_young.find(i) == reachable_by_young.end())
                || (!young && reachable_by_miguel.find(i) == reachable_by_miguel.end())
            )
        ) {
            discover_reachable_places(young, i);
        }
    }
}

int minimum_distance_not_in_set(int dist[], bool spt[]) {
    int min_dist = INT_MAX, min_index = -1;

    for (int i = 0; i < PLACES_COUNT; i++)
        if (!spt[i] && dist[i] < min_dist) {
            min_dist = dist[i];
            min_index = i;
        }

    return min_index;
}

int minimum_distance(bool young, int src, int dest) {
    int dist[PLACES_COUNT], i, j, min_dist_index;
    bool spt[PLACES_COUNT];

    for (i = 0; i < PLACES_COUNT; i++) {
        dist[i] = INT_MAX;
        spt[i] = false;
    }

    dist[src] = 0;
    for (i = 1; i < PLACES_COUNT; i++) {
        min_dist_index = minimum_distance_not_in_set(dist, spt);
        if (min_dist_index == -1) break;

        spt[min_dist_index] = true;
        for (j = 0; j < PLACES_COUNT; j++) {
            if (
                !spt[j]
                && city_map[min_dist_index][j] != -1
                && (
                    (young && can_young_use(make_pair(min_dist_index, j)))
                    || (!young && can_miguel_use(make_pair(min_dist_index, j)))
                )
                && dist[min_dist_index] != INT_MAX
                && (dist[min_dist_index] + city_map[min_dist_index][j] < dist[j])
            ) {
                dist[j] = dist[min_dist_index] + city_map[min_dist_index][j];
            }
        }
    }

    return dist[dest];
}

int main() {
    int streets_count,
        street_length,
        i,
        miguel_initial_place,
        young_initial_place,
        miguel_distance,
        young_distance,
        total_distance,
        dest;
    char young_modifier, direction_modifier, place1, place2;
    street_t street;

    cin >> streets_count;
    while (streets_count) {
        reset_city();

        // Build the city
        for (i = 0; i < streets_count; i++) {
            cin >> young_modifier >> direction_modifier >> place1 >> place2 >> street_length;

            street = make_pair(place1 - ASCII_A, place2 - ASCII_A);

            city_map[street.first][street.second] = street_length;
            if (direction_modifier == 'B')
                city_map[street.second][street.first] = street_length;

            if (young_modifier == 'Y') {
                only_young_streets.insert(make_pair(street.first, street.second));
                only_young_streets.insert(make_pair(street.second, street.first));
            } else {
                only_miguel_streets.insert(make_pair(street.first, street.second));
                only_miguel_streets.insert(make_pair(street.second, street.first));
            }
        }

        cin >> place1 >> place2;
        young_initial_place = place1 - ASCII_A;
        miguel_initial_place = place2 - ASCII_A;

        discover_reachable_places(false, miguel_initial_place);
        discover_reachable_places(true, young_initial_place);

        if (reachable_by_both.size() > 0) {
            sort(reachable_by_both.begin(), reachable_by_both.end());

            for (i = 0; i < reachable_by_both.size(); i++) {
                dest = reachable_by_both[i];
                young_distance = minimum_distance(true, young_initial_place, dest);
                miguel_distance = minimum_distance(false, miguel_initial_place, dest);
                place1 = dest + ASCII_A;
                total_distance = young_distance + miguel_distance;
                reachable_by_both_distances.push_back(make_pair(total_distance, place1));
            }

            sort(reachable_by_both_distances.begin(), reachable_by_both_distances.end());

            total_distance = reachable_by_both_distances[0].first;
            cout << total_distance;

            i = 0;
            while (reachable_by_both_distances[i].first == total_distance && i < reachable_by_both_distances.size()) {
                place1 = reachable_by_both_distances[i].second;
                cout << " " << place1;
                i++;
            }

            cout << endl;
        } else {
            cout << "You will never meet." << endl;
        }

        cin >> streets_count;
    }

    return 0;
}