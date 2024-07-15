#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int getuserinput() {
    int userinput;
    while (true) {
        cin >> userinput;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPease enter a valid integer value between 0 and 100.\n\n>>";
        } else if (userinput > 100 || userinput < 0) {
            cout << "\nPease enter a valid integer value between 0 and 100.\n\n>>";
        }
        else {
            return userinput;
        }
    }
}

void play(int randnum) {
    int i = 8;
    cout << "I found my favorite number (between 0 & 100). Your turn, enter your guess!\n\n";
    while (i >= 0) {
        cout << ">>";
        int userinput = getuserinput();
        i--;
        if (i != 0) {
            if (userinput == randnum) {
                cout << "\nYou won! But it's not going to make me a loser.\n\n\n\n";
                break;
            } else if (userinput > randnum) {
                cout << "\nMine is less!!\nGuess agaian. You have only " << i << " attempts left :)\n\n";
            } else if (userinput < randnum) {
                cout << "\nMine is More!!\nGuess agaian. You have only " << i << " attempts left :)\n\n";
            }
        } else if (i == 0 && userinput == randnum) {
            cout << "\nYou won! But it's not going to make me a loser.\n\n\n\n";
            break;
        } else if (i == 0 && userinput != randnum) {
            cout << "\nYou loser Boy!! you lost all of your attempts. hahahaha...";
            cout << "\nHowever, this was my number : " << randnum << "\n\n\n\n";
            break;
        }
    }
}

int main() {
    srand(time(0));
    int randnum = rand() % 101;
    play(randnum);

    return 0;
}
