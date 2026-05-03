#include <iostream>
#include <string>
using namespace std;

class MovieTicket
{
private:
    int u[100000];
    int m[100000];
    int total;

    int c[1001];
    int maxTickets;

public:
    MovieTicket()
    {
        total = 0;
        maxTickets = 100;

        for (int i = 0; i <= 1000; i++)
        {
            c[i] = 0;
        }
    }

    int BOOK(int X, int Y)
    {
        for (int i = 0; i < total; i++)
        {
            if (u[i] == X && m[i] == Y)
            {
                return 0;
            }
        }

        if (c[Y] >= maxTickets)
        {
            return 0;
        }

        u[total] = X;
        m[total] = Y;
        total++;

        c[Y]++;
        return 1;
    }

    int CANCEL(int X, int Y)
    {
        for (int i = 0; i < total; i++)
        {
            if (u[i] == X && m[i] == Y)
            {

                for (int j = i; j < total - 1; j++)
                {
                    u[j] = u[j + 1];
                    m[j] = m[j + 1];
                }

                total--;
                c[Y]--;
                return 1;
            }
        }
        return 0;
    }

    int IS_BOOKED(int X, int Y)
    {
        for (int i = 0; i < total; i++)
        {
            if (u[i] == X && m[i] == Y)
            {
                return 1;
            }
        }
        return 0;
    }

    int AVAILABLE_TICKETS(int Y)
    {
        return maxTickets - c[Y];
    }
};

int main()
{
    cout << "\n\n********Movie Ticket System ***********\n\n";

    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    MovieTicket obj;

    while (Q--)
    {
        cout << "\nChoose operation:\n";
        cout << "1. BOOK \n";
        cout << "2. CANCEL \n";
        cout << "3. IS_BOOKED \n";
        cout << "4. AVAILABLE_TICKETS \n";
        cout << "Enter command: ";

        string s;
        cin >> s;

        if (s == "BOOK")
        {
            int X, Y;
            cout << "Enter User ID and Movie ID: ";
            cin >> X >> Y;

            if (obj.BOOK(X, Y) == 1)
                cout << "Booking successful\n";
            else
                cout << "Booking failed\n";
        }
        else if (s == "CANCEL")
        {
            int X, Y;
            cout << "Enter User ID and Movie ID: ";
            cin >> X >> Y;

            if (obj.CANCEL(X, Y) == 1)
                cout << "Cancellation successful\n";
            else
                cout << "Cancellation failed\n";
        }
        else if (s == "IS_BOOKED")
        {
            int X, Y;
            cout << "Enter User ID and Movie ID: ";
            cin >> X >> Y;

            if (obj.IS_BOOKED(X, Y) == 1)
                cout << "Yes, ticket is booked\n";
            else
                cout << "No, ticket is not booked\n";
        }
        else if (s == "AVAILABLE_TICKETS")
        {
            int Y;
            cout << "Enter Movie ID: ";
            cin >> Y;

            cout << "Available Tickets: " << obj.AVAILABLE_TICKETS(Y) << "\n";
        }
        else
        {
            cout << "Invalid command\n";
        }
    }
    return 0;
}