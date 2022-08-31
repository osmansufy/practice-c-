#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;
    int n;

public:
    void setMenu()
    {
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> food_item_codes[i];
            cin.ignore();
            getline(cin, food_item_names[i]);
            cin >> food_item_prices[i];
        }
    }

public:
    void showMenu()
    {
        cout << "\t\tMake Bill" << endl;
        cout << setw(12) << "Item Code" << setw(12) << "Item Name" << setw(12) << "Item Price" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(12) << food_item_codes[i];
            cout << setw(12) << food_item_names[i];
            cout << setw(12) << food_item_prices[i] << endl;
        }
    }
    // Now take some inputs from the user. You need to take the table number of the customer, and the m number of items the customer has taken as input. After that, take all the item's code and quantity as input.
    // At last calculate the tax amount that is 5% of the total amount. And last show the net total that is the sum of tax and total amount.

public:
    void makeBill()
    {
        // dynamic array of size m to store the item code and quantity of the food items. You can use this array to calculate the total amount.
        int m;
        int table_number;
        cin >> table_number;
        std::cin >> m;
        string *table_item_names = new string[m];
        int *table_item_code = new int[m];
        int *table_item_quantity = new int[m];
        int *table_item_prices = new int[m];
        int *table_item_total_price = new int[m];
        for (int i = 0; i < m; i++)
        {
            cout << "Enter the " << i + 1 << "item code:";
            cin >> table_item_code[i];
            cout << "Enter the " << i + 1 << "item quantity:";
            cin >> table_item_quantity[i];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (table_item_code[i] == food_item_codes[j])
                {
                    table_item_names[i] = food_item_names[j];
                    table_item_prices[i] = food_item_prices[j];
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            table_item_total_price[i] = table_item_prices[i] * table_item_quantity[i];
        }
        cout << "\t\tBill Summary" << endl;
        cout << "Table Number:" << table_number << endl;
        cout << setw(12) << "Item Code";
        cout << setw(12) << "Item Name";
        cout << setw(12) << "Item Price";
        cout << setw(12) << "Item Quantity";
        cout << setw(12) << "Item Total Price";
        cout << endl;
        for (int i = 0; i < m; i++)
        {
            cout << setw(12) << table_item_code[i];
            cout << setw(12) << table_item_names[i];
            cout << setw(12) << table_item_prices[i];
            cout << setw(12) << table_item_quantity[i];
            cout << setw(12) << table_item_total_price[i];
            cout << endl;
        }
    }
};

int main()
{
    Restaurant r;
    r.setMenu();
    r.showMenu();
    r.makeBill();
    return 0;
}