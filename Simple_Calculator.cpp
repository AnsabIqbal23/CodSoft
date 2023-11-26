#include <iostream>

using namespace std;

float performOperation(float num1, float num2, char operation)
{

    switch (operation)
    {

    case '*':
        return (num1 * num2);
        break;

    case '/':
        return (num1 / num2);
        break;

    case '+':
        return (num1 + num2);
        break;

    case '-':
        return (num1 - num2);
        break;

    default:

        cout << "Invalid Operation" << endl;
        break;
    }
}

int main()
{

    float num1, num2, result;
    char operation;
    int check, change;

    cout << "************************ WELCOME TO SIMPLE CALCULATOR ************************" << endl
         << endl;

    do
    {

        cout << "Enter num1: ";
        cin >> num1;

        cout << "Enter num2: ";
        cin >> num2;

        cout << "Enter operation you want to perform" << endl;
        cout << "*" << endl
             << "/" << endl
             << "+" << endl
             << "-" << endl;
        cin >> operation;

        cout << "Do you want to change the numbers OR operation? (1 for num1, 2 for num2, 3 for operation, 0 for no): ";
        cin >> change;

        if (change == 1)
        {
            cout << "Enter num1: ";
            cin >> num1;
        }
        else if (change == 2)
        {
            cout << "Enter num2: ";
            cin >> num2;
        }
        else if (change == 3)
        {
            cout << "Enter operation you want to perform" << endl;
            cout << "*" << endl
                 << "/" << endl
                 << "+" << endl
                 << "-" << endl;
            cin >> operation;
        }

        result = performOperation(num1, num2, operation);
        cout << "Result is: " << result << endl;

        cout << "If you want to perform another operation (Press 1 for yes OR 0 for no): ";
        cin >> check;

    } while (check == 1);

    cout << endl
         << endl
         << "************************ THANK YOU FOR USING SIMPLE CALCULATOR ************************";

    return 0;
}