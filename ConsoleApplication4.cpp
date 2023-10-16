//Check Salma's part.

//deleted owner's name
//combined the address
//Addafter is deleted
//function search_by_price is updated
#include <iostream>
#include <string>
using namespace std;

class Apartment
{
public:
    int status; // 1 if purchased, 2 if rented, 0 if none.
    int num_of_rooms;
    int num_of_toilets;
    int num_of_balconies;
    int area; // a default size
    int floor_num;
    int flat_num;
    string address; // default
    int rental_price; // per month
    int purchase_price;
    Apartment* next;

    Apartment(int num_of_rooms, int num_of_toilets, int num_of_balconies, int flat_num, int floor_num, int rental_price, int purchase_price, int duration)
    {
        this->num_of_rooms = num_of_rooms;
        this->num_of_toilets = num_of_toilets;
        this->num_of_balconies = num_of_balconies;
        this->flat_num = flat_num;
        this->floor_num = floor_num;
        this->rental_price = rental_price * duration;
        this->purchase_price = purchase_price;
        area = 250;
        address = "3354, South George St., Oklahoma";
        status = 0;
        next = NULL;
    }

    void display_apartment()
    {
        cout << "Number of rooms: " << num_of_rooms << endl;
        cout << "Number of toilets: " << num_of_toilets << endl;
        cout << "Number of balconies: " << num_of_balconies << endl;
        cout << "The area of the apartment: " << area << endl;
        cout << "Rental price: " << rental_price << endl;
        cout << "Purchase price: " << purchase_price << endl;
        cout << "Address: " << "apartment number " << flat_num << ", " << "floor number " << floor_num << ", " << address << endl;
        cout << "--------------------------------------------------" << endl << endl;
    }
};

class List
{
public:
    Apartment* head;

    List()
    {
        head = NULL;
    }

    void AddFirstNode(int num_of_rooms, int num_of_toilets, int num_of_balconies, int flat_num, int floor_num, int rental_price, int purchase_price, int duration)
    {
        Apartment* ap = new Apartment(num_of_rooms, num_of_toilets, num_of_balconies, flat_num, floor_num, rental_price, purchase_price, duration);
        ap->next = NULL;
        head = ap;
    }

    void Add_Node_Beginning(int num_of_rooms, int num_of_toilets, int num_of_balconies, int flat_num, int floor_num, int rental_price, int purchase_price, int duration)
    {
        Apartment* ap = new Apartment(num_of_rooms, num_of_toilets, num_of_balconies, flat_num, floor_num, rental_price, purchase_price, duration);
        ap->next = head;
        head = ap;
    }

    void AppendEnd(int num_of_rooms, int num_of_toilets, int num_of_balconies, int flat_num, int floor_num, int rental_price, int purchase_price, int duration)
    {
        Apartment* ap = new Apartment(num_of_rooms, num_of_toilets, num_of_balconies, flat_num, floor_num, rental_price, purchase_price, duration);
        if (head == NULL)
        {
            ap->next = NULL;
            head = ap;
        }
        else
        {
            Apartment* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = ap;
            ap->next = NULL;
        }
    }

    int search_by_price(int wanted_price, int duration)
    {
        Apartment* current = head;
        int node_num = 0;

        while (current != NULL)
        {
            if ((wanted_price * duration) == current->rental_price)
            {
                node_num++;
                return node_num;
            }
            else
            {
                current = current->next;
            }
        }

        return 0;
    }

    void display()
    {
        Apartment* current = head;

        while (current != NULL)
        {
            current->display_apartment();
            current = current->next;
        }
    }
};

int main()
{
    string choice;
    List V;
    int duration;

    cout << "Hello, Welcome to the real estate Project!" << endl;
    cout << "------------------------------------------" << endl;
    cout << "First, do you want to (BUY or RENT)?\n";
    cout << "If you want to buy, please press 'b' for BUY.\n";

    cout << "Choice: ";
    cin >> choice;

    if (choice == "r" || choice == "R")
    {
        cout << "How many months do you want to rent for? ";
        cin >> duration;
    }
    else if (choice == "b" || choice == "B")
    {
        duration = 1;
    }
    else
    {
        cout << "Invalid choice. Exiting program." << endl;
        return 0;
    }

    V.AddFirstNode(2, 1, 1, 101, 1, 1000, 200000, duration);
    V.AppendEnd(3, 2, 2, 201, 2, 1500, 300000, duration);
    V.Add_Node_Beginning(1, 1, 0, 301, 3, 800, 150000, duration);

    cout << "Apartments available: " << endl;
    V.display();

    int wanted_price;
    cout << "Enter the price you are looking for: ";
    cin >> wanted_price;

    int result = V.search_by_price(wanted_price, duration);
    if (result > 0)
    {
        cout << "Apartment found at node " << result << "!" << endl;
    }
    else
    {
        cout << "No apartment found with the specified price." << endl;
    }

    return 0;
}