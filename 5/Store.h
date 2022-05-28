#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Product
{
private:
    string name;
    int price;

public:
    Product(string name, int price) : name(name), price(price){};

    void printProduct();
    bool operator==(Product &prod);
    int getPrice() const { return price; };
    string getName() const { return name; };
};

class Combo
{
private:
    int price;

public:
    vector<Product> products;

    Combo();
    Combo(Combo &c);

    void printProducts();
    void Add(Product &prod);
    void SetPrice(int price);
    int getPrice() const { return price; };
    bool isInCombo(Product &p);
    bool operator==(Combo &c);
    int getDiscount();

    friend Combo operator+(Combo &c, Product &p);
};

class Store
{
private:
    vector<Product> products;
    vector<string> buyProds;
    Combo myCombo;

    bool productExist(Product &p);
    bool productExist(string name);

public:
    Store(){};

    void Add(Product &p);
    void Add(Combo &c);
    void Buy(string name);
};

Combo operator+(Product &p, Product &q);