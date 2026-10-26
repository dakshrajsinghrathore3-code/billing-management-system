#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class product
{
private:
    int product_id = 0;
    string product_name;
    float price;
    int quantity;
    void add_product();
    void search_product();
    void display_all_products();

public:
    void product_menu();
};
void product::search_product()
{
    string name;
    cout << "enter the name of productt u want to search" << endl;
    cin >> name;

    ifstream products("product.txt");
    int product_id;
    string product_name;
    float price;
    int quantity;
    bool found = false;
    while (products >> product_id >> product_name >> price >> quantity)
    {
        if (product_name == name)
        {
            found = true;
            cout << "product id is:" << product_id << endl;
            cout << "product name is:" << product_name << endl;
            cout << "product price is:" << price << endl;
            cout << "product quantity is:" << quantity << endl;
            cout << endl;
        }
    }
    products.close();
    if (found == false)
    {
        cout << "no product found" << endl;
    }
}
void product::add_product()
{

    ifstream check("product.txt");
    int last_id = 0, quantity;
    string product_name;
    float price;
    while (check >> last_id >> product_name >> price >> quantity)
    {
    }
    check.close();

    product_id = last_id + 1;
    ofstream products("product.txt", ios::app);

    cout << "enter the product name" << endl;
    cin >> product_name;
    cout << "enter the product price" << endl;
    cin >> price;
    cout << "enter the quantiy of product" << endl;
    cin >> quantity;
    products << product_id << " " << product_name << " " << price << " " << quantity << endl;
    products.close();
    cout << "product added successfully!" << endl;
}
void product::display_all_products()

{
    ifstream products("product.txt");
    int product_id;
    string product_name;
    float price;
    int quantity;
    cout << "-----product list is : -----" << endl;
    while (products >> product_id >> product_name >> price >> quantity)
    {

        cout << "product id is:" << product_id << endl;
        cout << "product name is:" << product_name << endl;
        cout << "product price is:" << price << endl;
        cout << "product quantity is:" << quantity << endl;
        cout << endl;
    }
    products.close();
}
void product::product_menu()

{
    while (true)
    {
        cout << "--------------------" << endl;
        cout << " Product Management " << endl;
        cout << "--------------------" << endl;
        cout << "1.Add product" << endl;
        cout << "2.search product" << endl;
        cout << "3.display all products" << endl;
        cout << "4.back" << endl;
        int choice;
        cout << "enter the choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_product();
            break;
        case 2:
            search_product();
            break;
        case 3:
            display_all_products();
            break;
        case 4:
            return;
        default:
            cout << "invalid choice" << endl;
        }
    }
}

class customer
{
private:
    int customer_id = 0;
    string customer_name;
    long long phone_number;
    void add_customer();
    void search_customer();
    void display_all_customer();

public:
    void customer_menu();
};

void customer::customer_menu()
{

    while (true)
    {
        cout << "---------------------" << endl;
        cout << " Customer Management " << endl;
        cout << "---------------------" << endl;
        cout << "1.add customer" << endl;
        cout << "2.search customer" << endl;
        cout << "3.display all customer" << endl;
        cout << "4.exit" << endl;

        int choice;
        cout << "enter the choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_customer();
            break;
        case 2:
            search_customer();
            break;
        case 3:
            display_all_customer();
            break;
        case 4:
            return;
        default:
            cout << "invalid choice" << endl;
        }
    }
}
void customer::add_customer()
{
    ifstream check2("customers.txt");
    int last_id = 0;
    string customer_name;
    long long phone_number;

    while (check2 >> last_id >> customer_name >> phone_number)
    {
    }
    check2.close();

    customer_id = last_id + 1;
    ofstream customers("customers.txt", ios::app);
    cout << "enter customer name" << endl;
    cin >> customer_name;
    cout << "enter phone number" << endl;
    cin >> phone_number;

    customers << customer_id << " " << customer_name << " " << phone_number << endl;
    customers << endl;

    customers.close();
}
void customer::search_customer()
{
    ifstream customers("customers.txt");
    string name;
    cout << "enter name of customer u  want to search" << endl;
    cin >> name;

    string customer_name;
    long long phone_number;
    bool found = false;

    while (customers >> customer_id >> customer_name >> phone_number)
    {
        if (customer_name == name)
        {
            found = true;
            cout << "customer name is :" << customer_name << endl;
            cout << "mobile number is :" << phone_number << endl;
        }
    }
    if (found == false)
    {
        cout << "no customer found" << endl;
    }
    customers.close();
}
void customer::display_all_customer()
{
    ifstream customers("customers.txt");

    string customer_name;
    long long phone_number;

    while (customers >> customer_id >> customer_name >> phone_number)
    {
        cout << "customer name is :" << customer_name << endl;
        cout << "mobile number is :" << phone_number << endl;
        cout << endl;
    }
    customers.close();
}

class bill
{
    char que;
    int billing_id = 0;
    string buy_product;
    int buy_quantity;
    string name;
    bool found = false;
    void add_product();
    void show_cart();
    void total_bill();

public:
    void bill_menu();
};

void bill::bill_menu()
{
    while (true)
    {

        cout << "--------------------" << endl;
        cout << "   Bill Management  " << endl;
        cout << "--------------------" << endl;
        cout << "1.add items" << endl;
        cout << "2.show items" << endl;
        cout << "3.total bill" << endl;
        cout << "4.exit" << endl;
        int choice;
        cout << "enter the value" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_product();
            break;

        case 2:
            show_cart();
            break;

        case 3:
            total_bill();
            break;

        case 4:
            return;
            break;

        default:
            cout << "invalid choice" << endl;
        }
    }
}
void bill::add_product()
{
    char que;
    cout << "are u a regular customer(y/n)" << endl;
    cin >> que;
    cout << "please enter your name" << endl;
    cin >> name;

    ifstream customers("customers.txt");
    string customer_name;
    int customer_id;
    long long phone_number;
    while (customers >> customer_id >> customer_name >> phone_number)
    {
        if (customer_name == name)
        {
            found = true;
        }
    }
    if (found == false)
    {
        cout << "you are not regular customer" << endl;
    }
    customers.close();
    cout << "enter the product u want to purchase" << endl;
    cin >> buy_product;

    ifstream products("product.txt");
    int product_id;
    string product_name;
    float price;
    int quantity;
    bool product_found = false;
    float item_price = 0;
    int item_qty = 0;

    while (products >> product_id >> product_name >> price >> quantity)
    {
        if (product_name == buy_product)
        {
            product_found = true;
            item_price = price;
            item_qty = quantity;
            break;
        }
    }
    products.close();

    if (product_found == false)
    {
        cout << "no product found" << endl;
        return;
    }
    cout << "enter the quantity" << endl;
    cin >> buy_quantity;

    if (buy_quantity > item_qty)
    {
        cout << "insufficient quantity. " << item_qty << endl;
        return;
    }

    ofstream cart("cart.txt", ios::app);
    cart << buy_product << " " << item_price << " " << buy_quantity << endl;
    cart.close();

    ifstream read_prod("product.txt");
    ofstream write_prod("temp_product.txt");

    while (read_prod >> product_id >> product_name >> price >> quantity)
    {
        if (product_name == buy_product)
        {
            quantity = quantity - buy_quantity;
        }
        write_prod << product_id << " " << product_name << " " << price << " " << quantity << endl;
    }
    read_prod.close();
    write_prod.close();

    remove("product.txt");
    rename("temp_product.txt", "product.txt");

    cout << "product added to cart successfully" << endl;
}

void bill::show_cart()
{
    ifstream cart("cart.txt");
    if (!cart)
    {
        cout << "cart is empty" << endl;
        return;
    }

    string product_name;
    float price;
    int quantity;
    bool empty = true;

    cout << "--- Cart Items ---" << endl;
    while (cart >> product_name >> price >> quantity)
    {
        empty = false;
        cout << "product name is:" << product_name << endl;
        cout << "price:" << price << endl;
        cout << "quantity:" << quantity << endl;
        cout << "total:" << (price * quantity) << endl;
        cout << "--------------------" << endl;
    }
    cart.close();

    if (empty)
    {
        cout << "cart is empty" << endl;
    }
}

void bill::total_bill()
{
    ifstream cart("cart.txt");
    if (!cart)
    {
        cout << "cart is empty" << endl;
        return;
    }

    string product_name;
    float price;
    int quantity;
    float total = 0;

    string bill_filename = name + "_bill.txt";
    ofstream customer_bill(bill_filename, ios::app);

    customer_bill << "================ Final Bill ================" << endl;
    customer_bill << "Billing ID: " << billing_id << endl;
    customer_bill << "Customer Name: " << name << endl;

    while (cart >> product_name >> price >> quantity)
    {
        float item_total = price * quantity;
        total = total + item_total;

        cout << product_name << " x " << quantity << " = " << item_total << endl;
        customer_bill << product_name << " x " << quantity << " = " << item_total << endl;
    }
    cart.close();

    cout << "--------------------------------------------" << endl;
    cout << "subtotal: " << total << endl;
    customer_bill << "--------------------------------------------" << endl;
    customer_bill << "subtotal: " << total << endl;

    float discount = 0;
    if (found == true)
    {
        discount = total * 0.10f;
        cout << "discount (10%): " << discount << endl;
        customer_bill << "discount (10%): " << discount << endl;
    }

    float final_bill = total - discount;
    cout << "total bill: " << final_bill << endl;
    cout << "============================================" << endl;

    customer_bill << "total bill: " << final_bill << endl;
    customer_bill << "============================================\n\n";
    customer_bill.close();

    remove("cart.txt");
    found = false;
}

class payment
{
public:
    payment()
    {
        cout << "please select your payment method" << endl;
    }
    void cash();
    void upi();

    void payment_method()
    {
        int que2;
        cout << "1.cash" << endl;
        cout << "2.upi" << endl;
        cout << "please enter your choice" << endl;
        cin >> que2;
        switch (que2)
        {
        case 1:
            cash();
            break;
        case 2:
            upi();
            break;
        default:
            cout << "invalid choice" << endl;
        }
    }
};

void payment::cash(){
  cout<<"please pay money in cash at counter"<<endl;
}

void payment::upi(){
    string upi_id;
    cout<<"please enter ur upi id"<<endl;
    cin>>upi_id;
    cout<<"thanks for the id"<<endl;
    cout<<"notification has been sent successfully"<<endl;

}

int main()
{

    product p;
    customer c;
    bill b;
    payment p1;

    while (true)
    {
        cout << "---------------------------" << endl;
        cout << " Billing Management System " << endl;
        cout << "---------------------------" << endl;
        cout << "1.product management" << endl;
        cout << "2.customer management" << endl;
        cout << "3.bill management" << endl;
        cout << "4.payment" << endl;
        cout << "5.exit" << endl;

        int choice;
        cout << "enter the choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.product_menu();
            break;
        case 2:
            c.customer_menu();
            break;
        case 3:
            b.bill_menu();
            break;
        case 4:
            p1.payment_method();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "invalid choice" << endl;
        }
    }
}