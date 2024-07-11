#include <iostream>
#include <string>
#include <unordered_set>

std::string checkPangram(const std::string& text) {
    std::unordered_set<char> chars;

    for (char c : text) {
        if (isalpha(c)) {
            chars.insert(tolower(c));
        }
    }

    if (chars.size() == 26) {
        return "complete";
    } else {
        return "incomplete";
    }
}

int main() {
    std::string sentence = "The quick brown fox jumps over the lazy dog";
    std::cout << checkPangram(sentence) << std::endl;

    return 0;
}
