#include <iostream>
#include <map>
#include <vector>
#include <cmath>

int convertToDecimal(const std::string& value, int base) {
    int result = 0;
    int power = 1;
    for (int i = value.length() - 1; i >= 0; --i) {
        result += (value[i] - '0') * power;
        power *= base;
    }
    return result;
}

double lagrangeInterpolation(const std::vector<std::pair<int, int>>& points) {
    double constantTerm = 0.0;
    int k = points.size();
    for (int i = 0; i < k; ++i) {
        double term = points[i].second;
        for (int j = 0; j < k; ++j) {
            if (i != j) {
                term *= (0 - points[j].first) / static_cast<double>(points[i].first - points[j].first);
            }
        }
        constantTerm += term;
    }
    return constantTerm;
}

int main() {
    std::map<int, std::pair<int, std::string>> input = {
        {1, {10, "4"}},
        {2, {2, "111"}},
        {3, {10, "12"}},
        {6, {4, "213"}}
    };
    
    std::vector<std::pair<int, int>> points;
    
    for (const auto& entry : input) {
        int x = entry.first;
        int base = entry.second.first;
        std::string encodedValue = entry.second.second;
        int y = convertToDecimal(encodedValue, base);
        points.push_back({x, y});
    }

    double constantTerm = lagrangeInterpolation(points);

    std::cout << "Constant term (c) of the polynomial: " << constantTerm << std::endl;

    return 0;
}
