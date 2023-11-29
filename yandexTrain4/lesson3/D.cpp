#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <cstdint>

using vecListPair = std::vector<std::list<std::pair<int, long long>>>;

void dijkstra(size_t n, size_t s, size_t f, const vecListPair& v)
{
    std::vector<std::pair<int, long long>> dist(n + 1, { INT64_MAX, -1 });
    std::vector<bool> visited(n + 1, false);
    std::set<long long> st;
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
    int res = 0;

    if (!visited[f])
        std::cout << -1;
    else
    {
        int fin = f;
        while (fin != s)
        {
            res += dist[fin].first;
            fin = dist[fin].second;
            //std::cout << f << ' ';
        }
        std::cout << res;
    }
    return;
}

int main()
{
    int n, k, s, f;
    std::ifstream file("input.txt");
    file >> n >> k;
    vecListPair v(n + 1);
    for (size_t i = 0; i < k; ++i)
    {
        int a, b;
        long long l;
        file >> a >> b >> l;
        if (a == b)
            continue;
        v[a].push_back(std::move(std::pair{ b, l }));
        v[b].push_back(std::move(std::pair{ a, l }));
    }
    file >> s >> f;
    dijkstra(n, s, f, v);
    file.close();
    return 0;
}