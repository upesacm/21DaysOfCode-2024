#include <iostream>
#include <string>
#include <vector>

std::string checkSymmetry(const std::string& text) {
    std::vector<int> ascii_values;

    for (char c : text) {
        ascii_values.push_back(static_cast<int>(c));
    }

    int n = ascii_values.size();
    for (int i = 0; i < n / 2; ++i) {
        if (ascii_values[i] != ascii_values[n - i - 1]) {
            return "not symmetrical";
        }
    }

    return "symmetrical";
}

int main() {
    std::string input = "acxz";
    std::cout << checkSymmetry(input) << std::endl;

    return 0;
}
