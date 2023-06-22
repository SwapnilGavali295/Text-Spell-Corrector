#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define endl "\n"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

unordered_map<string, long long int> wordList;
unordered_map<string, string> corrections;

int editDistance(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row and first column
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // Fill in the remaining cells
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] });
            }
        }
    }

    return dp[n][m];
}


string spellCorrect(string& word) {
    // If word exists in the dictionary, return the word
    if (wordList.find(word) != wordList.end()) {
        return word;
    }

    // If word is already corrected
    if (corrections.find(word) != corrections.end()) {
        return corrections[word];
    }

    // Calculate edit distances for the current word and words in the dictionary
    map<int, vector<string>> distances;
    for (auto& word_freq : wordList) {
        int ed = editDistance(word_freq.first, word);
        distances[ed].push_back(word_freq.first);
    }

    // Take the words with the lowest edit distance, assuming they are the nearest correct words
    auto lowestDistance = distances.begin();
    pair<string, long long int> mostProbableWord = { "", -1 };

    // Among the nearest correct words, find the most probable word
    // The most probable word is the most frequently used word in English
    for (string& s : lowestDistance->second) {
        long long int s_freq = wordList[s];
        if (s_freq > mostProbableWord.second) {
            mostProbableWord = { s, s_freq };
        }
    }

    corrections[word] = mostProbableWord.first;
    return mostProbableWord.first;
}

int main() {
    // Reading the dictionary words and their frequencies
    fstream dictFile;
    fstream freqFile;
    dictFile.open("dict.txt", ios::in);
    freqFile.open("freq.txt", ios::in);

    if (dictFile.is_open() && freqFile.is_open()) {
        string s1, s2;
        while (getline(dictFile, s1) && getline(freqFile, s2)) {
            long long int currentFreq = stoll(s2);
            wordList[s1] = currentFreq;
        }
        dictFile.close();
        freqFile.close();
    } else {
        cout << "Cannot find required files" << endl;
        return 0;
    }

    // Reading the input sentence
    cout << "Please enter a paragraph:" << endl;
    cout << "---------------------------" << endl;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string inputString;
    getline(cin, inputString);
    int inputLength = inputString.length();

    cout << endl;
    cout << "Corrected paragraph is:" << endl;
    cout << "---------------------------" << endl;

    auto start1 = high_resolution_clock::now();  // Start the timer

    string word = "";
    bool capitalizeNext = true;  // Flag to capitalize the next word
    for (int i = 0; i < inputLength; i++) {
        if (isalpha(inputString[i]) || inputString[i] == '\'') {
            word.push_back(tolower(inputString[i]));  // Convert uppercase to lowercase
        } else {
            if (!word.empty()) {
                string correctWord = spellCorrect(word);
                if (capitalizeNext && islower(correctWord[0])) {
                    correctWord[0] = toupper(correctWord[0]);
                    capitalizeNext = false;
                }
                cout << correctWord;
                word.clear();
            }
            cout << inputString[i];
            if (inputString[i] == '!' || inputString[i] == '?' || inputString[i] == '.')
                {
                capitalizeNext = true;// Set flag to capitalize the next word after punctuation marks
            }
        }
    }

    if (!word.empty()) {
        string correctWord = spellCorrect(word);
        if (capitalizeNext && islower(correctWord[0])) {
            correctWord[0] = toupper(correctWord[0]);
        }
        cout << correctWord;
    }

    cout << endl << endl;
    cout << "--------------------------------" << endl;

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

    cout << "Execution Time: " << duration.count() / 1000.0 << " milliseconds" << endl;

    return 0;
}
