#include <iostream>
#include <string>
#include <sstream>
#include "Store.h"

using namespace std;

void Product::printProduct()
{
    cout << this->name << " " << this->price << endl;
}

bool Product::operator==(Product &prod)
{
    return ((this->name == prod.name) && (this->price == prod.price));
}

Combo::Combo()
{
    this->price = 0;
}

Combo::Combo(Combo &c)
{
    for (int i = 0; i < c.products.size(); i++)
        this->products.push_back(c.products[i]);

    this->price = c.price;
}

void Combo::Add(Product &prod)
{
    this->products.push_back(prod);
}

void Combo::SetPrice(int price)
{
    this->price = price;
}

void Combo::printProducts()
{
    for (int i = 0; i < this->products.size(); i++)
        this->products[i].printProduct();

    cout << "Total price: " << this->price << endl;
}

bool Combo::operator==(Combo &c)
{
    if (this->products.size() == c.products.size())
    {
        for (int i = 0; i < this->products.size(); i++)
            if (!c.isInCombo(this->products[i]))
                return false;
        return true;
    }
    return false;
}

bool Combo::isInCombo(Product &p)
{
    for (int i = 0; i < this->products.size(); i++)
        if (this->products[i] == p)
            return true;

    return false;
}

int Combo::getDiscount()
{
    int sum = 0;
    for (int i = 0; i < this->products.size(); i++)
        sum += this->products[i].getPrice();

    return sum - this->price;
}

Combo operator+(Combo &c, Product &p)
{
    Combo temp(c);
    temp.Add(p);
    return temp;
}

Combo operator+(Product &p, Product &q)
{
    Combo temp;
    temp.Add(p);
    temp.Add(q);

    return temp;
}

void Store::Add(Product &p)
{
    this->products.push_back(p);
}

void Store::Add(Combo &c)
{
    for (int i = 0; i < c.products.size(); i++)
    {
        bool exists = productExist(c.products[i]);

        if (!exists)
        {
            cout << "Product not exist." << endl;
            return;
        }
    }

    if (c.getPrice() == 0)
    {
        cout << "The combination has no set price." << endl;
        return;
    }

    this->myCombo = c;
}

bool Store::productExist(Product &p)
{
    for (int i = 0; i < this->products.size(); i++)
        if (p == this->products[i])
            return true;

    return false;
}

bool Store::productExist(string name)
{
    for (int i = 0; i < this->products.size(); i++)
        if (name == this->products[i].getName())
            return true;

    return false;
}

void Store::Buy(string name)
{
    bool isPlus = false;
    for (int i = 0; i < name.size(); i++)
        if (name[i] == '+')
            isPlus = true;

    if (!isPlus)
    {
        bool isAvailable = productExist(name);
        if (!isAvailable)
        {
            cout << name << " is not in store." << endl;
            return;
        }
        // this->buyProds.push_back();
    }
    else
    {
    }
}
