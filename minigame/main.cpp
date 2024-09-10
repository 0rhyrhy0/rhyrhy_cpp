#include <iostream>
#include <sstream>
#include <conio.h> // _getch
using namespace std;

// #define PRINT_WITH_HASH

int main() {
    cout << "\033[2J\033[H";
    cout << "Enter small alphabets and they'll be counted." << endl;
    cout << "Enter zero to end the program." << endl;
    cout << "Press enter to start.";
    while(_getch() != '\r');
    cout << "\033[2J\033[H";

    char x;
    int counts[26] {0, };
    ostringstream oss;

    while(true) {
        x = _getch();

        if(x == '0') break;
        if(x < 'a' || x > 'z') continue;

        counts[x-'a']++;

        oss << "\033[H";
        for(int i=0 ; i<26 ; i++) {
            // if(!counts[i]) continue; // comment out this line to always show all alphabets
            oss << static_cast<char>(i + 'a') << " : ";

            #ifdef PRINT_WITH_HASH
                for(int x=0 ; x<counts[i] ; x++) oss << '#';
            #else
                oss << counts[i];
                oss << string(30, ' ');
            #endif

            oss << endl;
        }

        cout << oss.str();
        oss.str("");

    }
}
