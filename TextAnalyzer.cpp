#include "TextAnalyzer.h"
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

int countWordOccurrences(const string& sentence, const string& word) {
    int count = 0;
    size_t pos = 0;
    size_t wordLength = word.length();

    while ((pos = sentence.find(word, pos)) != string::npos) {
        if ((pos == 0 || !isalnum(sentence[pos - 1])) &&
            (pos + wordLength >= sentence.size() || !isalnum(sentence[pos + wordLength]))) {
            ++count;
        }
        pos += wordLength;
    }

    return count;
}

string analyseWithWordCount(const string& str, const string& word) {
    ostringstream result;
    string buf = "";
    string symbols = ".!?";

    for (char ch : str) {
        buf.push_back(ch);
        if (symbols.find(ch) != string::npos) {
            int count = countWordOccurrences(buf, word);
            result << buf << " (Слово \"" << word << "\" встретилось " << count << " раз)" << endl;
            buf.clear();
        }
    }
    if (!buf.empty()) {
        int count = countWordOccurrences(buf, word);
        result << buf << " (Слово \"" << word << "\" встретилось " << count << " раз)" << endl;
    }

    return result.str();
}
