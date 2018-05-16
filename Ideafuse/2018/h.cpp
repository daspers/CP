#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> data;
    while (cin >> n) {
        data.push_back(n);
    }

    vector<pair<int, int> > answers;

    int c = 1;
    for (size_t i = 1; i < data.size(); i++) {
        int p = data[i - 1];

        if (data[i] == p) {
            c++;

            if (c == 255) {
                answers.push_back({c, p});

                c = 0;
            }
        } else {
            answers.push_back({c, p});

            c = 1;
        }
    }
    answers.push_back({c, data.back()});

    cout << 2 * answers.size() << '\n';
    for (size_t i = 0; i < answers.size(); i++) {
        cout << answers[i].first << ' ' << answers[i].second
             << (i == answers.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
