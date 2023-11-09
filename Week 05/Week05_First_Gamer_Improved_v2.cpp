#include <iostream>

using namespace std;

constexpr int g_PlayMenu = 1;
constexpr int g_QuitMenu = 2;

constexpr int g_MaleGender = 1;
constexpr int g_FemaleGender = 2;
constexpr int g_OtherGender = 3;

int displayWelcomeMessage();
void displayMessage(string message);
string getName();
int askForGender();
int getAge();
string makeNickname(int gender, int age);

void playGame();

int main()
{
    bool keepPlaying = true;
    
    do
    {
        int input = displayWelcomeMessage();

        switch (input)
        {
            case g_PlayMenu:
            {
             playGame();
             break;
            }

            case g_QuitMenu:
            {
             displayMessage("Goodbye!");
             keepPlaying = false;
             break;
            }

            default:
            {
             system("cls");
             displayMessage("Invalid Input. Try Again!");
             break;
            }
        }
    } while (keepPlaying);
}

int displayWelcomeMessage()
{
    int input;
    
    do
    {
     cout << "------------------ Welcome to the Amazing Guessing Game! -----------------" << endl;
     cout << "You have 3 guesses to correctly guess the correct number between 1 and 10." << endl;
     cout << "1) Play now" << endl;
     cout << "2) Quit" << endl;
     cout << "Select 1 or 2: " << endl;

     cin >> input;
     if (cin.fail())
     {
         cin.clear();
         cin.ignore(99, '\n');
         system("cls");
         cout << "Invalid input, please try again.";
     }
     else
     {
         break;
     }
    } while (true);

    return input;
}
void displayMessage(string message)
{
    cout << message << endl;
}
string getName()
{
    displayMessage("What is your name: ");
    string name;
    cin >> name;

    return name;
}
int askForGender()
{
    int gender;
    do
    {
     displayMessage("What is your gender?");
     displayMessage("1) Male");
     displayMessage("2) Female");
     displayMessage("3) Other");
     displayMessage("Select 1, 2 or 3: ");

     cin >> gender;

     if (cin.fail())
     {
         cin.clear();
         cin.ignore(99, '\n');
         system("cls");
         cout << "Invalid input, please try again.";
     }
     else
     {
         break;
     }

    } while (true);

    return gender;
}
int getAge()
{
    int age;
    do
    {
     displayMessage("How old are you: ");
     cin >> age;

     if (cin.fail())
     {
         cin.clear();
         cin.ignore(99, '\n');
         system("cls");
         cout << "Invalid input, please try again.";
     }
     else
     {
         break;
     }

    } while (true);

    return age;
}
string makeNickname(int gender, int age)
{
    string nickname;

    if (gender == g_MaleGender)
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
    else if (gender == g_FemaleGender)
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
    return nickname;
}

void playGame()
{
    string name = getName();
    cout << "Welcome " << name << '!' << endl;
    int gender = askForGender();
    int age = getAge(); 

    if (gender >= g_MaleGender && gender <= g_OtherGender)
    {
        string nickname = makeNickname(gender, age);

        int randomNumber = 1 + rand() % 10;

        cout << "Guess 1: " << "Alright, time to play " << nickname << "! Please enter a number: ";
        int guess;
        cin >> guess;
        int attempts = 0;

        do
        {
            if (attempts > 0)
            {
                std::cout << "Guess " << (attempts + 1) << ": Alright, " << nickname << "! Please enter a number: ";
            }
            else
            {
                std::cout << "Guess 1: Alright, time to play " << nickname << "! Please enter a number: ";
            }

            std::cin >> guess;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(99, '\n');
                displayMessage("Invalid input. Please enter a valid number.");
            }
            else
            {
                if (guess == randomNumber)
                {
                    displayMessage("You guessed correctly! You win!");
                    break;
                }
                else if (guess > randomNumber)
                {
                    displayMessage("Your guess is too high, try again!");
                }
                else
                {
                    displayMessage("Your guess is too low, try again!");
                }

                attempts++;
            }
        } while (attempts < 3);

        if (attempts >= 3)
        {
            cout << "Sorry " << nickname << ", the answer was " << randomNumber;
        }
    }
}
