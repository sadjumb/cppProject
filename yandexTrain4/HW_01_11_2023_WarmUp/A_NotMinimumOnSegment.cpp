#include <iostream>
#include <vector>

int main()
{
    size_t N, M;
    std::cin >> N >> M;
    std::vector<int> v(N);
    for (size_t i = 0; i < N; ++i)
        std::cin >> v[i];

    size_t l = 0, r = 0;
    for (size_t i = 0; i < M; ++i)
    {
        std::cin >> l >> r;
        int min = v[l];
        for (l; l <= r; ++l)
        {
            if (v[l] < min)
            {
                std::cout << min << std::endl;
                break;
            }
            else if (v[l] > min)
            {
                std::cout << v[l] << std::endl;
                break;
            }
        }
        if (l > r)
            std::cout << "NOT FOUND\n";
    }
}