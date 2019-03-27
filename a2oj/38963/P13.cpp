#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
    int cases_count,
        candidates_count,
        i,
        j,
        votes_count,
        ballots[1000][20],
        candidate_balance[20],
        tie_count,
        best_candidate,
        worst_candidate,
        remaining_candidates;
    char aux[81];
    string candidates_names[20], vote;
    bool voting_end, candidates_out[20];

    scanf("%d\n", &cases_count);
    while (cases_count--) {

        scanf("%d\n", &candidates_count);
        for (i = 0; i < candidates_count; i++)
            getline(cin, candidates_names[i]);

        votes_count = 0;
        while (getline(cin, vote) && vote.length() > 0) {
            istringstream iss(vote);
            for (i = 0; i < candidates_count; i++)
                iss >> ballots[votes_count][i];
            votes_count++;
        }

        for (i = 0; i < candidates_count; i++)
            candidates_out[i] = false;

        voting_end = false;
        while (!voting_end) {
            // Count votes
            for (i = 0; i < candidates_count; i++)
                candidate_balance[i] = 0;
            for (i = 0; i < votes_count; i++)
                for (j = 0; j < candidates_count; j++)
                    if (!candidates_out[ballots[i][j] - 1]) {
                        candidate_balance[ballots[i][j] - 1]++;
                        break;
                    }

            // Get best and worst candidates
            best_candidate = -1;
            worst_candidate = -1;
            for (i = 0; i < candidates_count; i++) {
                if (candidates_out[i])
                    continue;

                if (best_candidate == -1 || candidate_balance[best_candidate] < candidate_balance[i])
                    best_candidate = i;
           
                if (worst_candidate == -1 || candidate_balance[worst_candidate] > candidate_balance[i])
                    worst_candidate = i;
            }

            // Check if the voting is finished
            voting_end = candidate_balance[best_candidate] > votes_count / 2;
            if (!voting_end) {
                tie_count = 0;
                remaining_candidates = candidates_count;
                for (i = 0; i < candidates_count; i++) {
                    if (candidate_balance[best_candidate] == candidate_balance[i])
                        tie_count++;

                    if (candidates_out[i])
                        remaining_candidates--;
                }

                voting_end = tie_count > 1 && tie_count == remaining_candidates;
                if (!voting_end)
                    for (i = 0; i < candidates_count; i++)
                        if (candidate_balance[i] == candidate_balance[worst_candidate])
                            candidates_out[i] = true;
            }
        }

        for (i = 0; i < candidates_count; i++)
            if (candidate_balance[i] == candidate_balance[best_candidate])
                cout << candidates_names[i] << endl;

        if (cases_count > 0) {
            cout << endl;
        }
    }

    return 0;
}