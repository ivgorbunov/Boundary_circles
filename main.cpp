#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int MAXN = 1000;

vector<size_t> g[MAXN * 2];
vector<bool> used(MAXN);

void dfs(size_t v) {
    used[v] = true;
    for (auto u: g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main() {
    string s;
    cout << "Please input character in which every letter presents 2 times\n";
    cin >> s;
    size_t n = s.size();
    for (size_t i = 1; i < 2 * n; i += 2) {
        size_t j = (i + 1) % (2 * n);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                g[2 * i].push_back(2 * j + 1);
                g[2 * j + 1].push_back(2 * i);
                g[2 * i + 1].push_back(2 * j);
                g[2 * j].push_back(2 * i + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    }
    if (ans == 1) {
        cout << "There is ";
    } else {
        cout << "There are ";
    }
    cout << ans << " boundary ";
    if (ans == 1) {
        cout << "circle";
    } else {
        cout << "circles";
    }
}