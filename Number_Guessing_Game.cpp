#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

    srand(time(0));

    int num = rand() % 100000 + 1; // Generate numbers from 0 to 100000

    cout << "************************ WELCOME TO NUMBER GUESSING GAME ************************" << endl
         << endl;

    int guess, tries = 0;

    cout << "Enter a number you guess: ";
    cin >> guess;

    do
    {
        if (guess > num)
        {
            cout << "Guess is too high. Try Again" << endl;
            tries++;
        }

        else if (guess < num)
        {
            cout << "Guess is too low. Try Again" << endl;
            tries++;
        }

        cout << "Enter a number you guess: ";
        cin >> guess;

    } while (guess != num);

    cout << endl
         << "CONGRATULATIONS! YOUR GUESS IS CORRECT. After " << tries << " tries" << endl;

    cout << endl
         << endl
         << "************************ THANK YOU FOR PLAYING NUMBER GUESSING GAME ************************";

    return 0;
}