#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAX_BOOKINGS = 100;

class Bookings
{
    public:
    int id;
    int ticketAmount;
    int foodAmount;
  

};
class BookingManager
{
    private:
    //attributes
        Bookings bookings[MAX_BOOKINGS];
        int total_Bookings;
    public:
        int findBookingIndexById(int id);
        //behaviours
        void create();
        void display();
        void updateByID();
        void deleteByID();
        //constructor
        BookingManager();
};

void printMenu();

void bookingTicketsTest(void) 
{
    BookingManager manager;

    int choice;

    do 
    {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                manager.create();
                break;
            case 2:
                manager.display();
                break;
            case 3:
                manager.updateByID();
                break;
            case 4:
                manager.deleteByID();
                break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);
}

int main(void)
{
    bookingTicketsTest();
    
    return EXIT_SUCCESS;
}


void printMenu() 
{
    cout << "\n=== Bus Ticket Booking Management System ===\n";
    cout << "1. Create Booking\n";
    cout << "2. Display All Bookings\n";
    cout << "3. Edit Booking\n";
    cout << "4. Delete Booking\n";
    cout << "5. Exit\n";
}

void BookingManager::create() 
{
    if (total_Bookings >= MAX_BOOKINGS) 
    {
        cout << "Error: Maximum booking limit reached.\n";
        return;
    }

    int id, ticketAmount, foodAmount;

    cout << "Enter Booking ID: ";
    cin >> id;

    if (findBookingIndexById(id) != -1) 
    {
        cout << "Error: Booking ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Ticket Amount: ";
    cin >> ticketAmount;
    cout << "Enter Food Amount: ";
    cin >> foodAmount;

    bookings[total_Bookings].id = id;
    bookings[total_Bookings].ticketAmount = ticketAmount;
    bookings[total_Bookings].foodAmount = foodAmount;
    total_Bookings++;

    cout << "Total bookings till date: " << total_Bookings << endl;
    cout << "Booking created successfully.\n";
}

void BookingManager::display() 
{
    if (total_Bookings == 0) 
    {
        cout << "No bookings available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "| Booking ID | Ticket Amount | Food Amount    |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < total_Bookings; i++) {
        cout << "| " << setw(10) << bookings[i].id << " | "
             << setw(13) << bookings[i].ticketAmount << " | "
             << setw(12) << bookings[i].foodAmount << " |\n";
    }
    cout << "------------------------------------------------\n";
}

int BookingManager::findBookingIndexById(int id) 
{
    for (int i = 0; i < total_Bookings; i++) 
    {
        if (bookings[i].id == id) {
            return i;
        }
    }
    return -1;
}

void BookingManager::updateByID() 
{
    int id;
    cout << "Enter Booking ID to edit: ";
    cin >> id;

    int index = findBookingIndexById(id);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }
    cout << "Current Details - Ticket Amount: " << bookings[index].ticketAmount 
         << ", Food Amount: " << bookings[index].foodAmount << "\n";


    cout << "Enter New Ticket Amount: ";
    cin >> bookings[index].ticketAmount;
    cout << "Enter New Food Amount: ";
    cin >> bookings[index].foodAmount;

    cout << "Booking updated successfully.\n";
}

void BookingManager::deleteByID() 
{
    int id;
    cout << "Enter Booking ID to delete: ";
    cin >> id;

    int index = findBookingIndexById(id);
    if (index == -1) 
    {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    for (int i = index; i < total_Bookings - 1; i++) 
    {
        bookings[i] = bookings[i + 1];
    }
    total_Bookings--;

    cout << "Booking deleted successfully.\n";
}

BookingManager::BookingManager()
{
    total_Bookings = 0;
}
