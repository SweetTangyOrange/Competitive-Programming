#include <iostream>
#include <algorithm>
#include <array>
#include <cstdio>
using namespace std;

int main() {
     freopen("blocks.in", "r", stdin);
     freopen("blocks.out", "w", stdout);

     int n {};
     cin >> n;

     array<int, 26> a {};
     fill(a.begin(), a.end(), 0);

     for (int i {0}; i < n; ++i) {
         string first {};
         string second {};

         cin >> first;
         cin >> second;

         for (int j {0}; j < 26; ++j) {
             int letter_first {0};
             int letter_second {0};

             for (char letter : first) {
                 if (letter == static_cast<char>(97 + j)) {
                     ++letter_first;
                 }
             }

             for (char letter : second) {
                 if (letter == static_cast<char>(97 + j)) {
                     ++letter_second;
                 }
             }

             a[j] += (max(letter_first, letter_second));
         }
     }

     for (int i {0}; i < 26; ++i) {
         cout << a[i] << "\n";
     }
}