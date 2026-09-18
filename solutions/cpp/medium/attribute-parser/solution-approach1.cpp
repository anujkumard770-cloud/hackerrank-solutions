// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/attribute-parser/problem?isFullScreen=true
// Problem     Attribute Parser
// Difficulty  Medium
// Subdomain   Strings
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-18, 11:21 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    map<string, string> attrMap;
    vector<string> tagStack;

    for (int i = 0; i < n; ++i) {
        string line;
        // Puri line read karne ke liye taaki spaces handle ho sakein
        if (i == 0) {
            string dummy;
            getline(cin, dummy); // Pehle ke newline ko clear karne ke liye
        }
        getline(cin, line);

        if (line.empty()) continue;

        if (line[1] == '/') {
            // Yeh ek closing tag hai, toh stack se remove kar do
            if (!tagStack.empty()) {
                tagStack.pop_back();
            }
        } else {
            // Yeh ek opening tag hai
            stringstream ss(line);
            string tagPart, attr, eq, val;
            ss >> tagPart; // Jaise <tag1 ya <tag2

            // '<' hata do
            string tagName = tagPart.substr(1);
            // Agar tag ke sath hi '>' laga hai (bina attributes ke)
            if (tagName.back() == '>') {
                tagName.pop_back();
            }

            // Current tag ka full path taiyar karo
            string fullPath = "";
            for (const string& t : tagStack) {
                fullPath += t + ".";
            }
            fullPath += tagName;
            tagStack.push_back(tagName);

            // Attributes parse karna: format -> attr_name = "value"
            while (ss >> attr >> eq >> val) {
                // val ke end mein agar '>' hai (jaise value="HelloWorld">), toh use hata do
                if (val.back() == '>') {
                    val.pop_back();
                }
                // Quotes (" ") hatane ke liye
                string cleanVal = val.substr(1, val.length() - 2);

                // Map mein store karo: path~attribute -> value
                attrMap[fullPath + "~" + attr] = cleanVal;
            }
        }
    }

    // Queries handle karna
    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;

        if (attrMap.find(query) != attrMap.end()) {
            cout << attrMap[query] << "\n";
        } else {
            cout << "Not Found!\n";
        }
    }

    return 0;
}
