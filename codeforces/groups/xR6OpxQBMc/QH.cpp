#include <bits/stdc++.h>

using namespace std;

bool perm(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }

    long long int i;
    long long int s1_count[128] = {0};
    long long int s2_count[128] = {0};

    for (i = 0; i < s1.size(); i++) {
        s1_count[s1[i]]++;
        s2_count[s2[i]]++;
    }

    for (i = 0; i < 128; i++) {
        if (s1_count[i] != s2_count[i]) {
            return false;
        }
    }

    return true;
}

pair<string, string> get_red_mid(string w, long long int p, long long int s) {
    string red = "", mid = "";
    long long int i, j;
    for (i = 0; i < p && i < w.size(); i++)
        red += w[i];

    j = (i > w.size() - s) ? i : w.size() - s;
    for (; i < j; i++)
        mid += w[i];

    for (i = j; i < w.size(); i++)
        red += w[i];

    return make_pair(red, mid);
}

int main() {
    set<string> dic;
    map<string, string> dic_mid;
    pair<string, string> red_mid, red_mid2;
    string w, red, mid;
    long long int n, p, s, m, i, j, k;

    cin >> n >> p >> s;
    for (i = 0; i < n; i++) {
        cin >> w;
        red_mid = get_red_mid(w, p, s);
        dic.insert(red_mid.first);
        dic_mid[red_mid.first] = red_mid.second;
    }

    cin >> n;
    bool sim = true;
    for (i = 0; i < n; i++) {
        cin >> w;

        red_mid = get_red_mid(w, p, s);

        if (dic.find(red_mid.first) == dic.end()) {
            sim = false;
            break;
        }

        if (!perm(dic_mid[red_mid.first], red_mid.second)) {
            sim = false;
            break;
        }
    }

    if (sim) cout << "sim" << endl;
    else cout << "nao" << endl;

    return 0;
}