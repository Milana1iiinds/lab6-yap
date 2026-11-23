#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isEnd(char c) {
    return c == '.' || c == '!' || c == '?';
}

string trim(const string& text) {
    size_t start = 0;
    while (start < text.size() && isspace((unsigned char)text[start])) {
        start++;
    }
    size_t end = text.size();
    while (end > start && isspace((unsigned char)text[end - 1])) {
        end--;
    }
    return text.substr(start, end - start);
}

vector<string> splitSentences(const string& text) {
    vector<string> sentences;
    string current;
    for (size_t i = 0; i < text.size(); i++) {
        current += text[i];
        if (isEnd(text[i])) {
            string sentence = trim(current);
            if (!sentence.empty()) {
                sentences.push_back(sentence);
            }
            current = "";
        }
    }
    string last = trim(current);
    if (!last.empty()) {
        sentences.push_back(last);
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
