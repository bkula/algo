#include <iostream>
#include <string>
using namespace std;

int main()
{
    string txt;
    cin >> txt;

    for (int i = 0; i < txt.size(); i++) {
        int start = txt[i] >= 'a' && txt[i] <= 'z' ? 'a' : 'A';
        txt[i] = (txt[i] + 3 - start) % 26 + start;
    }

    cout << txt << "\n";
}
