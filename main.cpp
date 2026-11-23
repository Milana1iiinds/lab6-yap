#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isEnd(char c) {
    return c == '.' || c == '!' || c == '?';
}

vector<string> splitSentences(const string& text) {
    vector<string> sentences;
    string current;
    for (size_t i = 0; i < text.size(); i++) {
        current += text[i];
        if (isEnd(text[i])) {
            sentences.push_back(current);
            current = "";
        }
    }
    if (!current.empty()) {
        sentences.push_back(current);
    }
    return sentences;
}

int main() {
    string text = "Привет, мир!  Как у тебя дела? Сегодня отличная погода. Мы пойдём гулять в парк";
    vector<string> sentences = splitSentences(text);
    cout << "Текст: " << text << endl;
    cout << endl;
    cout << "Предложения:" << endl;
    for (size_t i = 0; i < sentences.size(); i++) {
        cout << i + 1 << ". " << sentences[i] << endl;
    }
    return 0;
}
