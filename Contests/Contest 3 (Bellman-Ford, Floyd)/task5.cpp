#include <iostream>
#include <vector>

struct ExchangePoint
{
    int A, B;
    double RAB, CAB, RBA, CBA;
};

bool can_increase_capital(int N, int M, int S, double V, const std::vector<ExchangePoint>& points)
{
    std::vector<double> capital(N + 1, 0.0);
    capital[S] = V;

    for (int i = 1; i < N; ++i)
    {
        for (const auto& point: points)
        {
            double new_capital_A = (capital[point.A] - point.CAB) * point.RAB;
            double new_capital_B = (capital[point.B] - point.CBA) * point.RBA;

            if (new_capital_A > capital[point.B])
            {
                capital[point.B] = new_capital_A;
            }
            if (new_capital_B > capital[point.A])
            {
                capital[point.A] = new_capital_B;
            }
        }
    }

    for (const auto& point: points)
    {
        double new_capital_A = (capital[point.A] - point.CAB) * point.RAB;
        double new_capital_B = (capital[point.B] - point.CBA) * point.RBA;

        if (new_capital_A > capital[point.B] || new_capital_B > capital[point.A])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int N, M, S;
    double V;
    std::cin >> N >> M >> S >> V;

    std::vector<ExchangePoint> points(M);
    for (int i = 0; i < M; ++i)
    {
        std::cin >> points[i].A >> points[i].B >> points[i].RAB >> points[i].CAB >> points[i].RBA >> points[i].CBA;
    }

    if (can_increase_capital(N, M, S, V, points))
    {
        std::cout << "YES" << '\n';
    }
    else
    {
        std::cout << "NO" << '\n';
    }

    return 0;
}
