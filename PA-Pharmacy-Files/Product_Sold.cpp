#include "Product_Sold.h"

Product_Sold::Product_Sold(int &id, string name, string laboratory, bool ivaValue) {
    _id = id;
    _name = name;
    _laboratory = laboratory;
    _hasIva = ivaValue;
    _cost = 0.0;
    _price = 0.0;
    _quantity = 0;
    _total = 0.0;
    _ivaQuantity = 0.0;
}

Product_Sold::~Product_Sold() {
}

double Product_Sold::getCost() {
    return _cost;
}

double Product_Sold::getPrice() {
    return _price;
}

int Product_Sold::getQuantity() {
    return _quantity;
}

double Product_Sold::getIvaQuantity() {
    _ivaQuantity = _hasIva ? _quantity * _price * 0.16 : 0.0;
    return _ivaQuantity;
}

double Product_Sold::getTotal() {
    _total = _quantity * _price;
    return _total;
}

void Product_Sold::setCost(double cost) {
    _cost = cost;
}

void Product_Sold::setPrice(double price) {
    _price = price;
}

void Product_Sold::setQuantity(int quantity) {
    _quantity = quantity;
}

void Product_Sold::setTotal(double total) {
    _total = total;
}

void Product_Sold::setIvaQuantity(double ivaQuantity) {
    _ivaQuantity = ivaQuantity;
}

void Product_Sold::showInfo() {
    cout << _name << " " << _laboratory << " - x" << _quantity;
    cout << " - $" << _price;
    cout << " - $" << getIvaQuantity();
    cout << " - $" << getTotal() << endl;
}

double Product_Sold::getProfit() {
    return (_quantity * _price) - (_quantity * _cost);
}