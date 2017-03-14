// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "controller.h"
#include "view.h"

unsigned long ValidInput(unsigned long min, unsigned long max);


int _tmain(int argc, _TCHAR* argv[])
{
    using std::cout;
    using std::endl;

    try
    {
        cout << "Enter number of clients: ";
        unsigned long clients = ValidInput(Constants::MIN_CLIENTS, Constants::MAX_CLIENTS);
        cout << "Start modelling. Press enter to quit. For results see log file."<<endl;
		Controller controller(clients);
		controller.Start();
        std::cin.get();		
		controller.StopAllThread();
		system("cls");
		cout << "All threads completed. Press enter to quit." << endl;
		std::cin.get();
    }
    catch (const std::bad_exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
        return 2;
    }
    return 0;
}

unsigned long ValidInput(unsigned long min, unsigned long max)
{
    using std::cin;
    using std::cout;

    unsigned long value{};
    cin >> value;
    while (cin.fail() || value < min || value > max)
    {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Bad entry. Enter a number in range ["
            << min << ", " << max << "]: ";
        cin >> value;
    }
    cin.ignore(cin.rdbuf()->in_avail());
    return value;
}
