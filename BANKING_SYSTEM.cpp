#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    int user[100000]; // user IDs
    int bal[100000];  // balances
    int total;        // number of users

public:
    Bank()
    {
        total = 0;
    }

    // CREATE X Y
    int CREATE(int X, int Y)
    {
        for (int i = 0; i < total; i++)
        {
            if (user[i] == X)
            {
                bal[i] += Y;
                return 0;
            }
        }

        user[total] = X;
        bal[total] = Y;
        total++;

        return 1;
    }

    // DEBIT X Y
    int DEBIT(int X, int Y)
    {
        for (int i = 0; i < total; i++)
        {
            if (user[i] == X)
            {
                if (bal[i] < Y)
                {
                    return 0;
                }
                bal[i] -= Y;
                return 1;
            }
        }
        return 0;
    }

    // CREDIT X Y
    int CREDIT(int X, int Y)
    {
        for (int i = 0; i < total; i++)
        {
            if (user[i] == X)
            {
                bal[i] += Y;
                return 1;
            }
        }
        return 0;
    }

    // BALANCE X
    int BALANCE(int X)
    {
        for (int i = 0; i < total; i++)
        {
            if (user[i] == X)
            {
                return bal[i];
            }
        }
        return -1;
    }
};

int main()
{
    cout << "===== Bank Management System =====\n\n";

    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    Bank obj;

    while (Q--)
    {
        cout << "\nChoose operation:\n";
        cout << "CREATE X Y\n";
        cout << "DEBIT X Y\n";
        cout << "CREDIT X Y\n";
        cout << "BALANCE X\n";

        cout << "Enter command: ";
        string s;
        cin >> s;

        if (s == "CREATE")
        {
            int X, Y;
            cout << "Enter User ID and Amount: ";
            cin >> X >> Y;

            if (obj.CREATE(X, Y) == 1)
                cout << "New account created\n";
            else
                cout << "User exists, amount added\n";
        }
        else if (s == "DEBIT")
        {
            int X, Y;
            cout << "Enter User ID and Amount: ";
            cin >> X >> Y;

            if (obj.DEBIT(X, Y) == 1)
                cout << "Debit successful\n";
            else
                cout << "Debit failed (user not found or insufficient balance)\n";
        }
        else if (s == "CREDIT")
        {
            int X, Y;
            cout << "Enter User ID and Amount: ";
            cin >> X >> Y;

            if (obj.CREDIT(X, Y) == 1)
                cout << "Credit successful\n";
            else
                cout << "Credit failed (user not found)\n";
        }
        else if (s == "BALANCE")
        {
            int X;
            cout << "Enter User ID: ";
            cin >> X;

            int ans = obj.BALANCE(X);
            if (ans == -1)
                cout << "User not found\n";
            else
                cout << "Current Balance: " << ans << "\n";
        }
        else
        {
            cout << "Invalid command\n";
        }
    }
    return 0;
}