#ifndef INC_2NDTERM_PRODUCT_SOLD_H
#define INC_2NDTERM_PRODUCT_SOLD_H


#pragma once

#include "Product_Base.h"

class Product_Sold : public Product_Base {
public:
    Product_Sold(int &, string, string, bool);

    ~Product_Sold();

    double getCost();

    double getPrice();

    int getQuantity();

    double getIvaQuantity();

    double getTotal();

    void setCost(double);

    void setPrice(double);

    void setQuantity(int);

    void setTotal(double);

    void setIvaQuantity(double);

    void showInfo();

    double getProfit();

private:
    int _id;
    double _cost;
    double _price;
    int _quantity;
    double _total;
    double _ivaQuantity;
};

#endif //INC_2NDTERM_PRODUCT_SOLD_H
