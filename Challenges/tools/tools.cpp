#include"tools.h"


vector<string> split(const string& text, char delimiter) {
    vector<string> segments;
    stringstream ss(text);
    string segment;
    while (getline(ss, segment, delimiter)) {
        if (segment != "") {segments.push_back(segment);}
    }
    return segments;
}

vector<string> split(ifstream& file, char delimiter) {
    stringstream text;
    text << file.rdbuf();
    return split(text.str(), delimiter);
}