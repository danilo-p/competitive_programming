#include <iostream>
#include <utility>
#include <cmath>

#define MAX_BULLETS_COUNT 50
#define MAX_CANNON_CAPACITY 100

using namespace std;

pair<int, int> bullets[MAX_BULLETS_COUNT];
int min_castle_resistance_memo[MAX_BULLETS_COUNT][MAX_CANNON_CAPACITY];

void reset_min_castle_resistance_memo(int bullets_count, int cannon_capacity, int castle_resistance) {
	for (int i = 0; i < bullets_count; i++)
		for (int j = 0; j < cannon_capacity; j++)
			min_castle_resistance_memo[i][j] = castle_resistance;
}

int min_castle_resistance(int bullets_count, int cannon_capacity, int castle_resistance, int i, int current_weight, int current_castle_resistance) {
	if (i == bullets_count || current_castle_resistance <= 0)
		return current_castle_resistance;

	if (min_castle_resistance_memo[i][current_weight] < castle_resistance)
		return min_castle_resistance_memo[i][current_weight];

	int partial_min_castle_resistance = castle_resistance;
	if (current_weight + bullets[i].second <= cannon_capacity)
		partial_min_castle_resistance = min_castle_resistance(
			bullets_count, cannon_capacity, castle_resistance,
			i + 1,
			current_weight + bullets[i].second,
			current_castle_resistance - bullets[i].first
		);

	partial_min_castle_resistance = min(partial_min_castle_resistance, min_castle_resistance(
		bullets_count, cannon_capacity, castle_resistance,
		i + 1,
		current_weight,
		current_castle_resistance
	));

	min_castle_resistance_memo[i][current_weight] = partial_min_castle_resistance;

	return partial_min_castle_resistance;
}

int main() {
	int c, bullets_count, destruction_power, projectil_weight, cannon_capacity, castle_resistance, i, j;

	cin >> c;
	while (c--) {
		cin >> bullets_count;

		for (i = 0; i < bullets_count; i++) {
			cin >> destruction_power >> projectil_weight;
			bullets[i] = make_pair(destruction_power, projectil_weight);
		}

		cin >> cannon_capacity;
		cin >> castle_resistance;

		reset_min_castle_resistance_memo(bullets_count, cannon_capacity, castle_resistance);

		if (min_castle_resistance(bullets_count, cannon_capacity, castle_resistance, 0, 0, castle_resistance) <= 0) {
			cout << "Missao completada com sucesso" << endl;
		} else {
			cout << "Falha na missao" << endl;
		}
	}

	return 0;
}