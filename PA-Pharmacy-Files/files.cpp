#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Product_Sold.h"
using namespace std;

inline void make_file(){
    string filename = "Products_Sold.csv";
    ifstream ifile;
    ifile.open(filename);
    if (!ifile){
        ofstream myFileOutput(filename);
        myFileOutput << "ID, Name, Laboratory, Cost, Price, Quantity, IVA, Total" << endl;
        myFileOutput.close();
    }
}

inline void write_file(int id, string name, string laboratory, double cost, double price, int quantity, bool ivaValue){
    string filename = "Products_Sold.csv";
    ofstream myFileOutput(filename, ios::app);
    myFileOutput << id << "," << name << "," << laboratory << "," << cost << "," << price << "," << quantity << "," << ivaValue << endl;
    myFileOutput.close();
}

inline void read_file(vector<Product_Sold> &products){
    string line, colname;
    vector<string> headers;
    string value;

    ifstream myFileInput("Products_Sold.csv");
    if(!myFileInput.is_open()) throw runtime_error("Could not open file");
    if(myFileInput.good()){
        getline(myFileInput, line);
        stringstream ss(line);
        while(getline(ss, colname, ',')){
            headers.push_back(colname);
        }
    }
    while(getline(myFileInput, line)){
        stringstream ss(line);

        int colIdx = 0, _quantity = 0, _ivaValue = 0, _id = 0;
        string _name, _laboratory;
        double _cost, _price, _ivaQuantity, _total;
        bool _hasIVA;

        while(getline(ss, value, ',')){
            switch (colIdx) {
                case 0:
                    _id = stoi(value);
                    break;
                case 1:
                    _name = value;
                    break;
                case 2:
                    _laboratory = value;
                    break;
                case 3:
                    _cost = stod(value);
                    break;
                case 4:
                    _price = stod(value);
                    break;
                case 5:
                    _quantity = stoi(value);
                    break;
                case 6:
                    _total = stod(value);
                    break;
                case 7:
                    _ivaQuantity = stod(value);
                    break;
            }
            if(ss.peek() == ',') ss.ignore();
            colIdx++;
        }

        if(_ivaQuantity == 0) _hasIVA = false;
        else _hasIVA = true;

        Product_Sold Product(_id, _name, _laboratory, _hasIVA);
        Product.setCost(_cost);
        Product.setPrice(_price);
        Product.setQuantity(_quantity);
        Product.setTotal(_total);
        Product.setIvaQuantity(_ivaQuantity);

        products.push_back(Product);
    }
    myFileInput.close();
}