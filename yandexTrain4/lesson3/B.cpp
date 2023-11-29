#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <cstdint>

using vecListPair = std::vector<std::list<std::pair<int, int>>>;

std::vector<std::pair<int, int>> dijkstra(size_t n, size_t s, size_t f, const vecListPair& v)
{
    std::vector<std::pair<int, int>> dist(n + 1, { INT32_MAX, -1 });
    std::vector<bool> visited(n + 1, false);
    std::set<int> st;
    st.insert(s);
    dist[s].first = 0;
    dist[s].second = s;
    int k = 0;
    while (!st.empty())
    {
        k = *st.begin();
        st.erase(st.begin());
        visited[k] = true;

        for (const auto& i : v[k])
        {
            if (dist[i.first].first > dist[k].first + i.second)
            {
                st.insert(i.first);
                dist[i.first].first = dist[k].first + i.second;
                dist[i.first].second = k;
            }
        }
    }
    std::vector<std::pair<int, int>> res;

    if (!visited[f])
        std::cout << -1;
    else
    {
        int fin = f;
        res.push_back({ 0, f });
        while (fin != s)
        {
            res.push_back({ dist[fin] });
            fin = dist[fin].second;
            //std::cout << f << ' ';
        }

        for (int i = res.size() - 1; i > -1; --i)
        {
            std::cout << res[i].second << ' ';
        }
    }
    return res;
}

int main()
{
    int n, s, f;
    std::ifstream file("input.txt");
    file >> n >> s >> f;
    vecListPair v(n + 1);
    for (size_t i = 1; i < n + 1; ++i)
    {
        for (size_t j = 1; j < n + 1; ++j)
        {
            int val;
            file >> val;
            if (val == -1 || i == j)
                continue;
            v[i].push_back(std::move(std::pair{ j, val }));
        }
    }
    dijkstra(n, s, f, v);

    return 0;
}