#include <iostream>
#include <cmath>
#include <utility>

#define MAX_BULLETS 50
#define MAX_CAPACITY 100

using namespace std;

int main() {
    pair<int, int> bullets[MAX_BULLETS];
    int max_damage_with_bullets_and_capacity[MAX_BULLETS + 1][MAX_CAPACITY + 1];
    int cases, bullets_count, bullet_damage, bullet_weight, i, j, castle_resistance, cannon_capacity, partial_max_damage;

    cin >> cases;
    while (cases--) {
        cin >> bullets_count;

        for (i = 0; i < bullets_count; i++) {
            cin >> bullet_damage >> bullet_weight;
            bullets[i] = make_pair(bullet_damage, bullet_weight);
        }

        cin >> cannon_capacity >> castle_resistance;

        // No capacity, therefore no damage
        for (i = 0; i <= bullets_count; i++)
            max_damage_with_bullets_and_capacity[i][0] = 0;

        // No bullets, therefore no damage
        for (i = 0; i <= cannon_capacity; i++)
            max_damage_with_bullets_and_capacity[0][i] = 0;

        for (i = 1; i <= bullets_count; i++)
            for(j = 1; j <= cannon_capacity; j++) {
                partial_max_damage = 0;

                // With this bullet, if it fits on the cannon
                if (bullets[i - 1].second <= j)
                    partial_max_damage =
                        // Bullet damage
                        bullets[i - 1].first
                        // Max damage with the remaining capacity
                        + max_damage_with_bullets_and_capacity[i - 1][j - bullets[i - 1].second];

                max_damage_with_bullets_and_capacity[i][j] = max(
                    partial_max_damage,
                    // Damage without this bullet
                    max_damage_with_bullets_and_capacity[i - 1][j]
                );
            }

        if (max_damage_with_bullets_and_capacity[bullets_count][cannon_capacity] >= castle_resistance) {
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "Falha na missao" << endl;
        }
    }

    return 0;
}