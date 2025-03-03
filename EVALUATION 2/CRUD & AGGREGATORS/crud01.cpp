#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_BOOKINGS = 100;

// Function Prototypes
void createBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &total_Bookings);
void displayBookings(const int booking_ids[], const int ticket_amounts[], const int food_amounts[], int totalBookings);
int findBookingIndexById(const int booking_ids[], int total_Bookings, int id);
void updateBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int total_Bookings);
void deleteBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &total_Bookings);
void printMenu();

void bookingTicketsTest(void) 
{
    int booking_ids[MAX_BOOKINGS] = {0};
    int ticket_amounts[MAX_BOOKINGS] = {0};
    int food_amounts[MAX_BOOKINGS] = {0};
    int total_Bookings = 0;

    int choice;

    do 
    {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                createBooking(booking_ids, ticket_amounts, food_amounts, total_Bookings);
                break;
            case 2:
                displayBookings(booking_ids, ticket_amounts, food_amounts, total_Bookings);
                break;
            case 3:
                updateBooking(booking_ids, ticket_amounts, food_amounts, total_Bookings);
                break;
            case 4:
                deleteBooking(booking_ids, ticket_amounts, food_amounts, total_Bookings);
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
    
    return 0;
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

void createBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &total_Bookings) 
{
    if (total_Bookings >= MAX_BOOKINGS) 
    {
        cout << "Error: Maximum booking limit reached.\n";
        return;
    }

    int id, ticketAmount, foodAmount;

    cout << "Enter Booking ID: ";
    cin >> id;

    if (findBookingIndexById(booking_ids, total_Bookings, id) != -1) 
    {
        cout << "Error: Booking ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Ticket Amount: ";
    cin >> ticketAmount;
    cout << "Enter Food Amount: ";
    cin >> foodAmount;

    booking_ids[total_Bookings] = id;
    ticket_amounts[total_Bookings] = ticketAmount;
    food_amounts[total_Bookings] = foodAmount;
    total_Bookings++;

    cout << "Total bookings till date: " << total_Bookings << endl;
    cout << "Booking created successfully.\n";
}

void displayBookings(const int booking_ids[], const int ticket_amounts[], const int food_amounts[], int total_Bookings) 
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
        cout << "| " << setw(10) << booking_ids[i] << " | "
             << setw(13) << ticket_amounts[i] << " | "
             << setw(12) << food_amounts[i] << " |\n";
    }
    cout << "------------------------------------------------\n";
}

int findBookingIndexById(const int booking_ids[], int total_Bookings, int id) 
{
    for (int i = 0; i < total_Bookings; i++) 
    {
        if (booking_ids[i] == id) {
            return i;
        }
    }
    return -1;
}

void updateBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int total_Bookings) 
{
    int id;
    cout << "Enter Booking ID to edit: ";
    cin >> id;

    int index = findBookingIndexById(booking_ids, total_Bookings, id);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    cout << "Current Details - Ticket Amount: " << ticket_amounts[index] 
         << ", Food Amount: " << food_amounts[index] << "\n";

    cout << "Enter New Ticket Amount: ";
    cin >> ticket_amounts[index];
    cout << "Enter New Food Amount: ";
    cin >> food_amounts[index];

    cout << "Booking updated successfully.\n";
}

void deleteBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &total_Bookings) 
{
    int id;
    cout << "Enter Booking ID to delete: ";
    cin >> id;

    int index = findBookingIndexById(booking_ids, total_Bookings, id);
    if (index == -1) 
    {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    for (int i = index; i < total_Bookings - 1; i++) 
    {
        booking_ids[i] = booking_ids[i + 1];
        ticket_amounts[i] = ticket_amounts[i + 1];
        food_amounts[i] = food_amounts[i + 1];
    }
    total_Bookings--;

    cout << "Booking deleted successfully.\n";
}
