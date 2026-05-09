#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Check empty input
    if (name.empty()) {
        cout << "Name cannot be empty!" << endl;
        return 0;
    }

    // Roast templates
    vector<string> roasts = {
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} writes comments like they're hiding secrets from the FBI.",
        "Even Google gives up trying to understand {name}'s code.",
        "{name}'s typing speed is slower than a turtle on vacation.",
        "If procrastination were a profession, {name} would be the CEO.",
        "{name}'s laptop asks for sick leave every time coding starts.",
        "{name} writes code so confusing that even AI gets emotional.",
        "The bugs in {name}'s program filed a harassment complaint.",
        "{name}'s coding style is copy, paste, pray, and panic.",
        "{name} debugs code by staring at the screen dramatically."
    };

    // Random roast selection
    srand(time(0));
    int index = rand() % roasts.size();

    string roast = roasts[index];

    // Replace {name} with actual name
    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    // Display roast
    cout << "\nRoast Generator\n";
    cout << roast << endl;
return 0;
}