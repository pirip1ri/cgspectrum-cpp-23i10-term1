#include <iostream>

using namespace std;

int main()
{
    constexpr int kPlayMenu= 1;
    constexpr int kQuitMenu = 2;

    constexpr int kMaleGender = 1;
    constexpr int kFemaleGender = 2;
    constexpr int kOtherGender = 3;
 
    cout << "------------------ Welcome to the Amazing Guessing Game! -----------------" << endl;
    cout << "You have 3 guesses to correctly guess the correct number between 1 and 10." << endl;
    cout << "1) Play now" << endl;
    cout << "2) Quit" << endl;
    cout << "Select 1 or 2: " << endl;

    int input;
    cin >> input;

    switch (input)
    {
    case kPlayMenu:
    {
        cout << "What is your name: " << endl;
        string name;
        cin >> name;

        cout << "Welcome " << name << "!" << endl;

        cout << "What is your gender?" << endl;
        cout << "1) Male" << endl;
        cout << "2) Female" << endl;
        cout << "3) Other" << endl;
        cout << "Select 1, 2 or 3: ";

        int gender;
        cin >> gender;

        if (gender >= kMaleGender && gender <= kOtherGender)
        {
            cout << "How old are you: ";
            int age;
            cin >> age;

            string nickname;

            if (gender == kMaleGender)
            {
                if (age > 60)
                {
                    nickname = "sir";
                }
                else if (age < 14)
                {
                    nickname = "buddy";
                }
                else if (age >= 14 && age <= 60)
                {
                    nickname = "mate";
                }
            }
            else if (gender == kFemaleGender)
            {
                if (age > 60)
                {
                    nickname = "ma'am";
                }
                else if (age < 14)
                {
                    nickname = "little lady";
                }
                else  if (age >= 14 && age <= 60)
                {
                    nickname = "darl";
                }
            }
            else
            {
                nickname = "friend";
            }
         int randomNumber = 1 + rand() % 10;
         cout << "Guess 1: " << "Alright, time to play " << nickname << "! Please enter a number: ";
         int guess;
         cin >> guess;

         if (guess == randomNumber)
         {
             cout << "You guessed correctly! You win!" << endl;
         }
         else
         {
             if (guess > randomNumber)
             {
                 cout << "Your guess is too high, try again!" << endl;
             }
             else
             {
                 cout << "Your guess is too low, try again!" << endl;
             }
             
             cout << "Guess 2: " << "Alright " << nickname << ", please enter your second guess: ";
             cin >> guess;

             if (guess == randomNumber)
             {
                 cout << "You guessed correctly! You win!" << endl;
             }
             else
             {
                 if (guess > randomNumber)
                 {
                     cout << "Your guess is too high, try again!" << endl;
                 }
                 else
                 {
                     cout << "Your guess is too low, try again!" << endl;
                 }

                 cout << "Guess 3: " << "Last try " << nickname << ", please enter your last guess: ";
                 cin >> guess;

                 if (guess == randomNumber)
                 {
                     cout << "You guessed correctly! You win!" << endl;
                 }
                 else
                 {
                     cout << "You lose! Sorry " << nickname << ", the answer was: " << randomNumber << endl;
                 }
             }
         }
        }
        else
        {
            cout << "Invalid input. Goodbye!" << endl;
        } 
        break;
    }
    case kQuitMenu:
    {
        cout << "Goodbye!" << endl;
        break;
    }
    default:
    {
        cout << "Invalid Input. Goodbye!" << endl;
        break;
    }
    }

}
