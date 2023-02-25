#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Sale
{
	int ordnum;
	string date;

	string name;
	float subtotal;
	string presentation;
	string laboratory;
	bool iva;

	int quantity;
	float total;
	string typepay;
	bool bill;
};

struct Product
{
	int ID;
	string name;

	string presentation;
	string laboratory;
	int stock;
	float cvalue;
	float svalue;

	int expiration;
	bool IVA;
};

struct Store
{
	vector<Product> myProducts;
	vector<Sale> mySales;
};

static void Menu()
{
	cout << "\nWelcome to San Pablo Drugstore " << endl;
	cout << "1. Add product" << endl;
	cout << "2. Create sale" << endl;
	cout << "3. Reports" << endl; //De reports sale el submenu
	cout << "4. Exit" << endl;
}

static void submenu()
{
	cout << "1. See specific sale information" << endl;
	cout << "2. List of all the sales" << endl;
	cout << "3. List of all the sales filtered" << endl;
	cout << "4. List of sales by type of payment" << endl;
	cout << "5. List of sales according to billing" << endl;
	cout << "6. List sales" << endl;
	cout << "7. See specific product information" << endl;
	cout << "8. List all the inventory" << endl;
	cout << "9. List of products by laboratory" << endl;
	cout << "10. List of products soon to expire" << endl; //Adicional
	cout << "11. List of all the sales according to the lab" << endl; //Adicional
}

static vector<Product> ADDPRODUCTS(vector<Product> temporal_product)
{
	int producto;
	cout << "\nDear customer how many products would you like to add?: ";
	cin >> producto;
	cin.ignore();
	for (int i = 0; i < producto; i++)
	{
		Product temp;
		temp.ID = i + 1;

		cout << "\nEnter the name of the product " << i + 1 << ": ";
		getline(cin, temp.name);

		cout << "Enter the presentation of the product (tablet/syrup) & (mg / ml): ";
		getline(cin, temp.presentation);

		cout << "Enter the laboratory of the product " << i + 1 << ": ";
		getline(cin, temp.laboratory);

		cout << "Enter how many products do you have in stock? ";
		cin >> temp.stock;
		cin.ignore();

		cout << "Enter the cost value of the product " << i + 1 << ": $";
		cin >> temp.cvalue;
		cin.ignore();

		cout << "Enter the Price of the product " << i + 1 << ": $";
		cin >> temp.svalue;
		cin.ignore();

		cout << "Enter the expiration year: ";
		cin >> temp.expiration;
		cin.ignore();

		string validator1;
		cout << "Does the product has iva? (yes/no): ";
		getline(cin, validator1);
		temp.IVA = validator1 == "yes" ? true : false;

		temporal_product.push_back(temp);
	}
	return temporal_product;
}

static Store ADDSALE(Store store_temporal)
{
	Sale temp;
	cout << "Products" << endl;
	cout << "ID" << "\t" << "Name" << "\t" << "Stock" << "\t" << "Price" << endl;
	for (int i = 0; i < store_temporal.myProducts.size(); i++)
	{
		cout << i + 1 << "\t" << store_temporal.myProducts[i].name << "\t" << store_temporal.myProducts[i].stock << "\t"
			<< store_temporal.myProducts[i].svalue << endl;
	}
	int producto2;
	cout << "Dear customer enter the ID of the product that you would like to buy: ";
	cin >> producto2;
	cin.ignore();

	temp.ordnum = store_temporal.mySales.size() + 1;
	temp.name = store_temporal.myProducts[producto2 - 1].name;

	cout << "Enter the date of the sale: ";
	getline(cin, temp.date);

	int quantity;
	cout << "Enter the quantity of the product: ";
	cin >> quantity;
	cin.ignore();

	temp.subtotal = store_temporal.myProducts[producto2 - 1].svalue;
	temp.total = store_temporal.myProducts[producto2 - 1].svalue * quantity;
	temp.presentation = store_temporal.myProducts[producto2 - 1].presentation;
	temp.laboratory = store_temporal.myProducts[producto2 - 1].laboratory;
	temp.iva = store_temporal.myProducts[producto2 - 1].IVA;

	cout << "Enter the type of payment (credit/debit): ";
	cin >> temp.typepay;
	cin.ignore();

	string bill;
	cout << "Do you want a bill? (yes/no): ";
	cin >> bill;
	cin.ignore();
	temp.bill = bill == "yes" ? true : false;

	store_temporal.mySales.push_back(temp);

	return store_temporal;
}

static void SPECIFICINFOPRODU(vector<Product> myProducts)
{
	cout << "Products" << endl;
	cout << "ID" << "\t" << "Name" << "\t" << "Stock" << "\t" << "Price" << endl;
	for (int i = 0; i < myProducts.size(); i++)
	{
		cout << i + 1 << "\t" << myProducts[i].name << "\t" << myProducts[i].stock << "\t" << myProducts[i].svalue <<
			endl;
	}
	cout << "Please enter the ID of the product you want to see the information: ";
	int id;
	cin >> id;
	cin.ignore();
	for (int i = 0; i < myProducts.size(); i++)
	{
		if (id == myProducts[i].ID)
		{
			cout << "Name: " << myProducts[i].name << endl;
			cout << "Presentation: " << myProducts[i].presentation << endl;
			cout << "Laboratory: " << myProducts[i].laboratory << endl;
			cout << "Stock: " << myProducts[i].stock << endl;
			cout << "Cost Value: " << myProducts[i].cvalue << endl;
			cout << "Price: " << myProducts[i].svalue << endl;
			cout << "Expiration: " << myProducts[i].expiration << endl;
			string iva = myProducts[i].IVA ? "Yes" : "No";
			cout << "IVA: " << iva << endl;
		}
	}
}

static void BYLAB(vector<Product> myProducts)
{
	string lab;
	cout << "Enter the name of the laboratory: ";
	getline(cin, lab);
	cout << "ID" << "\t" << "Name" << "\t" << "Stock" << "\t" << "Price" << endl;
	for (int i = 0; i < myProducts.size(); i++)
	{
		if (lab == myProducts[i].laboratory)
		{
			cout << i + 1 << "\t" << myProducts[i].name << "\t" << myProducts[i].stock << "\t" << myProducts[i].svalue
				<<
				endl;
		}
	}
}

static void ALLPRODUCTS(vector<Product> myProducts)
{
	cout << "ID" << "\t" << "Name" << "\t" << "Stock" << "\t" << "Price" << endl;
	for (int i = 0; i < myProducts.size(); i++)
	{
		cout << i + 1 << "\t" << myProducts[i].name << "\t" << myProducts[i].stock << "\t" << myProducts[i].svalue <<
			endl;
	}
}

void EXPIRING(vector<Product> myProducts)
{
	vector<Product> temp = myProducts;
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp.size() - 1; j++)
		{
			if (temp[j].expiration > temp[j + 1].expiration)
			{
				Product tempo = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tempo;
			}
		}
	}
	cout << "ID" << "\t" << "Name" << "\t" << "Stock" << "\t" << "Price" << "\t" << "Expiration" << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << i + 1 << "\t" << temp[i].name << "\t" << temp[i].stock << "\t" << temp[i].svalue << "\t" <<
			temp[i].expiration << endl;
	}
}

void ALLSALES(vector<Sale> sales)
{
	cout << "ID" << "\t" << "Name" << "\t" << "Date" << "\t" << "Bill" << endl;
	for (int i = 0; i < sales.size(); i++)
	{
		cout << i + 1 << "\t" << sales[i].name << "\t" << sales[i].date << "\t" << sales[i].bill << endl;
	}
}

void SALESBYBILLING(vector<Sale> sales)
{
	string bill;
	cout << "Sales with bill? (yes/no): ";
	cin >> bill;
	cin.ignore();
	cout << "ID" << "\t" << "Name" << "\t" << "Date" << "\t" << "Bill" << endl;
	for (int i = 0; i < sales.size(); i++)
	{
		if (bill == "yes")
		{
			if (sales[i].bill == true)
			{
				cout << i + 1 << "\t" << sales[i].name << "\t" << sales[i].date << "\t" << sales[i].bill << endl;
			}
		}
		else if (bill == "no")
		{
			if (sales[i].bill == false)
			{
				cout << i + 1 << "\t" << sales[i].name << "\t" << sales[i].date << "\t" << sales[i].bill << endl;
			}
		}
	}
}

void SALESBYPAYMENT(vector<Sale> sales)
{
	string payment;
	cout << "Sales with payment? (credit/debit): ";
	cin >> payment;
	cin.ignore();
	cout << "ID" << "\t" << "Name" << "\t" << "Date" << "\t" << "Bill" << endl;

	for (int i = 0; i < sales.size(); i++)
	{
		if (payment == "credit")
		{
			if (sales[i].typepay == "credit")
			{
				cout << i + 1 << "\t" << sales[i].name << "\t" << sales[i].date << "\t" << sales[i].bill << endl;
			}
		}
		else if (payment == "debit")
		{
			if (sales[i].typepay == "debit")
			{
				cout << i + 1 << "\t" << sales[i].name << "\t" << sales[i].date << "\t" << sales[i].bill << endl;
			}
		}
	}
}

void SPECIFICSALEINFO(vector<Sale> sales)
{
	cout << "ID" << "\t" << "Name" << "\t" << "Date" << "\t" << "Bill" << endl;
	for (int i = 0; i < sales.size(); i++)
	{
		cout << i + 1 << "\t" << sales[i].name << "\t" << sales[i].date << "\t" << sales[i].bill << endl;
	}

	int ordernum;
	cout << "Enter the order number: ";
	cin >> ordernum;
	cin.ignore();

	Sale temp = sales[ordernum - 1];
	cout << "Name: " << temp.name << endl;
	cout << "Date: " << temp.date << endl;
	cout << "Bill: " << temp.bill << endl;
	cout << "Payment: " << temp.typepay << endl;
	cout << "Quantity: " << temp.quantity << endl;
	cout << "Total: " << temp.total << endl;
}

int main()
{
	Store myStore;

	int answer;
	bool correrprograma = true;
	bool products_added = false;
	while (correrprograma)
	{
		Menu();
		cout << "Please choose an option: ";
		cin >> answer;
		cin.ignore();

		switch (answer)
		{
		case 1:
			if (products_added == true)
			{
				cout << "You already added products." << endl;
			}
			else
			{
				myStore.myProducts = ADDPRODUCTS(myStore.myProducts);
				products_added = true;
			}
			break;
		case 2:
			if (products_added == false)
			{
				cout << "You must add products first." << endl;
			}
			else
			{
				cout << "Create sale" << endl;
				myStore = ADDSALE(myStore);
			}
			break;
		case 3:
			if (products_added == false)
			{
				cout << "You must add products first." << endl;
			}
			else
			{
				cout << "\nReports" << endl;
				submenu();
				int response;
				cout << "Dear customer please select an option: ";
				cin >> response;
				cin.ignore();
				switch (response)
				{
				case 1:
					SPECIFICSALEINFO(myStore.mySales);
					break;
				case 2:
					ALLSALES(myStore.mySales);
					break;
				case 3:
					cout << "Filtered sales" << endl;
				// FILTEREDSALES();//TODO CRITERIO????
					break;
				case 4:
					SALESBYPAYMENT(myStore.mySales);
					break;
				case 5:
					SALESBYBILLING(myStore.mySales);
					break;
				case 6:
					cout << "Sales by CRITERIO???" << endl; //TODO CRITERIO????
					break;
				case 7:
					SPECIFICINFOPRODU(myStore.myProducts);
					break;
				case 8:
					ALLPRODUCTS(myStore.myProducts);
					break;
				case 9:
					BYLAB(myStore.myProducts);
					break;
				case 10:
					EXPIRING(myStore.myProducts);
					break;
				case 11:
					//SALESBYLAB(myStore.mySales); //TODO LABORATORIO SOBRE PRODUCTO?
					break;
				default:
					cout << "Please select a valid option: " << endl;
					break;
				}
			}
			break;


		case 4:
			correrprograma = false;
			cout << "You have exited the program.";
			break;
		default:
			cout << "Option not valid.";
			break;
		}
	}
	return 0;
}
