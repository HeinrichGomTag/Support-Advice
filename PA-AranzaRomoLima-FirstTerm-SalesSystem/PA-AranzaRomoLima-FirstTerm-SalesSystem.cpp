// PA-AranzaRomoLima-FirstTerm-SalesSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product
{
	int id{};
	string SKU;
	string name;
	string presentation;
	string laboratory;
	int stock{};
	float cost{};
	float sale{};
	string expiration;
	bool iva{};
};

struct Sale
{
	int odernum{};
	string date;
	vector<Product> products;
	vector<int> quantity;
	float subtotal{}; // without taxes
	float total{};
	string payment; // Cash or Card
	bool billed{};
};

struct Store
{
	vector<Product> products;
	vector<Sale> sales;
};

static void Menu()
{
	cout << "\nWelcome to San Pablo Drugstore " << endl;
	cout << "1. Add product" << endl;
	cout << "2. Create sale" << endl;
	cout << "3. Reports" << endl;
	cout << "4. Exit" << endl;
}

static void submenu()
{
	cout << "1. See specific sale information" << endl;
	cout << "2. List of all the sales" << endl;
	cout << "3. List of all the sales filtered" << endl;
	// Additional 1 point if you add a date filter by year, month, date range and only show those sales.
	cout << "4. List of sales by type of payment" << endl;
	cout << "5. List of sales according to billing" << endl;
	// Additional 0.5 points if you tell in the report the amount of taxes to pay(the summation of all the taxes that where not billed)

	cout << "6. See specific product information" << endl;
	cout << "7. List all the inventory" << endl;
	cout << "8. List of products by laboratory" << endl;
	cout << "9. List of products soon to expire" << endl; //Adicional
	cout << "10. List of all the sales according to the lab" << endl; //Adicional
}

vector<Product> ADDPRODUCTS(vector<Product> products)
{
	int actual_size = products.size();
	Product temp;
	temp.id = actual_size + 1;
	cout << "SKU: ";
	cin >> temp.SKU;
	cin.ignore();
	cout << "Name: ";
	getline(cin, temp.name);
	cout << "Presentation: ";
	getline(cin, temp.presentation);
	cout << "Laboratory: ";
	getline(cin, temp.laboratory);
	cout << "Stock: ";
	cin >> temp.stock;
	cin.ignore();
	cout << "Cost: $";
	cin >> temp.cost;
	cin.ignore();
	cout << "Sale: $";
	cin >> temp.sale;
	cin.ignore();

	cout << "Expiration date: " << endl;
	bool date = false;
	while (!date)
	{
		cout << "Year: ";
		int year;
		cin >> year;
		cin.ignore();

		cout << "Month: ";
		int month;
		cin >> month;
		cin.ignore();

		cout << "Day: ";
		int day;
		cin >> day;
		cin.ignore();

		int yearlenght = log10(year) + 1;

		if (yearlenght == 4 && (month >= 1 && month <= 12) && (day >= 1 && day <= 31))
		{
			temp.expiration = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
			date = true;
		}
		else
		{
			cout << "Invalid date" << endl;
		}
	}

	string iva;
	cout << "IVA (yes/no): ";
	cin >> iva;
	cin.ignore();
	temp.iva = (iva == "yes") ? true : false;

	products.push_back(temp);
	return products;
}

void ListAllInventory(vector<Product> products)
{
	cout << "ID\tName\tStock\tSale\tExpiration" << endl;
	for (int i = 0; i < products.size(); i++)
	{
		string iva;
		cout << products[i].id << "\t" << products[i].name << "\t" << products[i].stock << "\t";

		if (products[i].iva == true)
		{
			iva = "Yes";
			cout << "Sale: " << products[i].sale * 1.16 << "\t";
		}
		else
		{
			iva = "No";
			cout << products[i].sale << "\t";
		}
		cout << products[i].expiration << endl;
	}
}

Store ADDSALE(Store store)
{
	int actual_size = store.sales.size();
	Sale temp;
	temp.odernum = actual_size + 1;
	cout << "DATE" << endl;
	bool date = false;
	while (!date)
	{
		cout << "Year: ";
		int year;
		cin >> year;
		cin.ignore();

		cout << "Month: ";
		int month;
		cin >> month;
		cin.ignore();

		cout << "Day: ";
		int day;
		cin >> day;
		cin.ignore();

		int yearlenght = log10(year) + 1;

		if (yearlenght == 4 && (month >= 1 && month <= 12) && (day >= 1 && day <= 31))
		{
			temp.date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
			date = true;
		}
		else
		{
			cout << "Invalid date" << endl;
		}
	}

	cout << "Products: " << endl;
	cout << "ID\tName\tStock\tSale\tExpiration" << endl;
	for (int i = 0; i < store.products.size(); i++)
	{
		cout << store.products[i].id << "\t" << store.products[i].name << "\t" << store.products[i].stock << "\t" <<
			store.products[i].sale <<
			"\t" << store.products[i].expiration << endl;
	}


	cout << "How many products do you want to add? ";
	int num;
	cin >> num;
	cin.ignore();

	for (int i = 0; i < num; i++)
	{
		cout << "Product ID: ";
		int id;
		cin >> id;
		cin.ignore();

		cout << "Quantity: ";
		int quantity;
		cin >> quantity;
		cin.ignore();

		for (int j = 0; j < store.products.size(); j++)
		{
			if (store.products[j].id == id)
			{
				if (store.products[j].stock >= quantity)
				{
					store.products[j].stock -= quantity;
					temp.products.push_back(store.products[j]);
					temp.quantity.push_back(quantity);
				}
				else
				{
					cout << "Not enough stock" << endl;
				}
			}
		}
		float taxes = 0;
		for (int i = 0; i < temp.products.size(); i++)
		{
			temp.subtotal += (temp.products[i].sale * temp.quantity[i]);
			if (temp.products[i].iva == true)
			{
				taxes += (temp.products[i].sale * 0.16);
			}
		}
		temp.total = temp.subtotal + taxes;

		cout << "Payment method (Cash/Card): ";
		getline(cin, temp.payment);

		cout << "Was the order billed (yes/no): ";
		string billed;
		cin >> billed;
		cin.ignore();
		temp.billed = (billed == "yes") ? true : false;
	}
	store.sales.push_back(temp);
	return store;
}

void ListAllSales2(Store store)
{
	cout << "OrderID\tDate\tTotal\tPayment\tBilled" << endl;
	string billed;
	for (int i = 0; i < store.sales.size(); i++)
	{
		if (store.sales[i].billed == true)
		{
			billed = "yes";
		}
		else
		{
			billed = "no";
		}
		cout << store.sales[i].odernum << "\t" << store.sales[i].date << "\t" << store.sales[i].total << "\t" << store.
			sales[i].payment << "\t" << billed << endl;
	}
}

void SpecificSaleInfo(vector<Sale> sales)
{
	cout << "Order ID: ";
	int id;
	cin >> id;
	cin.ignore();

	for (int i = 0; i < sales.size(); i++)
	{
		if (sales[i].odernum == id)
		{
			cout << "Date: " << sales[i].date << endl;
			cout << "Products: " << endl;
			cout << "ID\tName\tStock\tSale\tExpiration\tQUANTITY" << endl;
			for (int j = 0; j < sales[i].products.size(); j++)
			{
				cout << sales[i].products[j].id << "\t" << sales[i].products[j].name << "\t" <<
					"\t" << sales[i].products[j].sale <<
					"\t" << sales[i].products[j].expiration << "\t" << sales[i].quantity[j] << endl;
			}

			cout << "Subtotal: " << sales[i].subtotal << endl;
			cout << "Total: " << sales[i].total << endl;
			cout << "Payment: " << sales[i].payment << endl;
			cout << "Billed: " << sales[i].billed << endl;
		}
	}
}

void ListAllSales(vector<Sale> sales)
{
	float sale_amount = 0;
	float card_amount = 0;
	float cash_amount = 0;

	int card_sales = 0;
	int cash_sales = 0;
	int bills = 0;

	for (int i = 0; i < sales.size(); i++)
	{
		sale_amount += sales[i].total;
		if (sales[i].payment == "Card")
		{
			card_amount += sales[i].total;
			card_sales++;
		}
		else if (sales[i].payment == "Cash")
		{
			cash_amount += sales[i].total;
			cash_sales++;
		}
		if (sales[i].billed == true)
		{
			bills++;
		}
	}

	cout << "Sales amount: $" << sale_amount << endl;
	cout << "Card sales: #" << card_sales << endl;
	cout << "Card sales: $" << card_amount << endl;
	cout << "Cash sales: #" << cash_sales << endl;
	cout << "Cash sales: $" << cash_amount << endl;
	cout << "Billed sales: #" << bills << endl;
}

void ListSalesByPayment(vector<Sale> sales)
{
	float amoun = 0;
	cout << "Payment method (Cash/Card): ";
	string payment;
	getline(cin, payment);
	cout << "OrderID\tDate\tTotal" << endl;

	for (int i = 0; i < sales.size(); i++)
	{
		if (sales[i].payment == payment)
		{
			amoun += sales[i].total;
			cout << sales[i].odernum << "\t" << sales[i].date << "\t" << sales[i].total << endl;
		}
	}

	cout << "Total amount: $" << amoun << endl;
}

void ListProductsByLab(vector<Product> products)
{
	float amount = 0;
	cout << "Laboratory: ";
	string laboratory;
	getline(cin, laboratory);
	cout << "ProdID\tName\tSale" << endl;

	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].laboratory == laboratory)
		{
			amount += products[i].sale;
			cout << products[i].id << "\t" << products[i].name << "\t" << products[i].sale << endl;
		}
	}

	cout << "Total amount: $" << amount << endl;
}

void SpecificProductInfo(vector<Product> products)
{
	cout << "Product ID: ";
	int id;
	cin >> id;
	cin.ignore();


	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].id == id)
		{
			cout << "SKU: " << products[i].SKU << endl;
			cout << "Name: " << products[i].name << endl;
			cout << "Presentation: " << products[i].presentation << endl;
			cout << "Laboratory: " << products[i].laboratory << endl;
			cout << "Stock: " << products[i].stock << endl;
			cout << "Cost: " << products[i].cost << endl;

			string iva;
			if (products[i].iva == true)
			{
				iva = "Yes";
				cout << "Sale: " << products[i].sale * 1.16 << endl;
			}
			else
			{
				iva = "No";
				cout << "Sale: " << products[i].sale << endl;
			}
			cout << "Expiration: " << products[i].expiration << endl;
			cout << "IVA: " << iva << endl;
		}
	}
}

void ListSalesByBilling(vector<Sale> sales)
{
	float amount = 0;
	float unbilled = 0;
	cout << "OrderID\tDate\tTotal" << endl;

	for (int i = 0; i < sales.size(); i++)
	{
		if (sales[i].billed == true)
		{
			amount += sales[i].total;
			cout << sales[i].odernum << "\t" << sales[i].date << "\t" << sales[i].total << endl;
		}
		else
		{
			for (int j = 0; j < sales[i].products.size(); j++)
			{
				if (sales[i].products[j].iva == true)
				{
					unbilled = sales[i].products[j].sale * 0.16;
				}
			}
		}
	}

	cout << "BILLED Total amount: $" << amount << endl;
	cout << "UNBILLED TAXES Total amount: $" << unbilled << endl;
}

void ListProductsToExpire(vector<Product> products)
{
	int year;
	cout << "Enter expiration year: ";
	cin >> year;
	cin.ignore();

	int yearlenght = log10(year) + 1;

	if (yearlenght == 4)
	{
		cout << "ID\tName\tStock\tSale\tExpiration" << endl;
		for (int i = 0; i < products.size(); i++)
		{
			int yearlenght2 = stoi(products[i].expiration.substr(0, 4));
			if (yearlenght2 == year)
			{
				string iva;
				cout << products[i].id << "\t" << products[i].name << "\t" << products[i].stock << "\t";

				if (products[i].iva == true)
				{
					iva = "Yes";
					cout << products[i].sale * 1.16 << "\t";
				}
				else
				{
					iva = "No";
					cout << products[i].sale << "\t";
				}
				cout << products[i].expiration << endl;
			}
		}
	}
	else
	{
		cout << "Invalid date" << endl;
	}
}

void ListSalesByLab(Store store)
{
	string lab;
	cout << "Laboratory: ";
	getline(cin, lab);

	float amount = 0;
	cout << "OrderID\tDate\tTotal" << endl;

	for (int i = 0; i < store.sales.size(); i++)
	{
		for (int j = 0; j < store.sales[i].products.size(); j++)
		{
			if (store.sales[i].products[j].laboratory == lab)
			{
				amount += store.sales[i].total;
				cout << store.sales[i].odernum << "\t" << store.sales[i].date << "\t" << store.sales[i].total << endl;
			}
		}
	}

	cout << "Total amount: $" << amount << endl;
}

void ListSalesByDate(vector<Sale> sales) // DO NOT ENTER SAME SEPARATE VALUES FOR START AND END DATE
{
	cout << "Enter start date (YYYY-MM-DD): ";
	string start;
	getline(cin, start);

	cout << "Enter end date (YYYY-MM-DD): ";
	string end;
	getline(cin, end);

	int startyear = stoi(start.substr(0, 4));
	int startmonth = stoi(start.substr(5, 2));

	int endyear = stoi(end.substr(0, 4));
	int endmonth = stoi(end.substr(5, 2));

	int startday = stoi(start.substr(8, 2));
	int endday = stoi(end.substr(8, 2));

	float amount = 0;
	cout << "OrderID\tDate\tTotal" << endl;
	for (int i = 0; i < sales.size(); i++)
	{
		int year = stoi(sales[i].date.substr(0, 4));
		int month = stoi(sales[i].date.substr(5, 2));
		int day = stoi(sales[i].date.substr(8, 2));

		if (year >= startyear && year <= endyear)
		{
			if (month >= startmonth && month <= endmonth)
			{
				if (day >= startday && day <= endday)
				{
					amount += sales[i].total;
					cout << sales[i].odernum << "\t" << sales[i].date << "\t" << sales[i].total << endl;
				}
			}
		}
	}
	cout << "Total amount: $" << amount << endl;
}

int main()
{
	Store myStore;
	int answer;
	bool runProgram = true;

	while (runProgram)
	{
		Menu();
		cout << "Please choose an option: ";
		cin >> answer;
		cin.ignore();

		switch (answer)
		{
		case 1:
			myStore.products = ADDPRODUCTS(myStore.products);
			break;
		case 2:
			if (myStore.products.empty() == true)
			{
				cout << "You must add products first." << endl;
			}
			else
			{
				myStore = ADDSALE(myStore);
			}
			break;
		case 3:
			{
				if (myStore.products.empty() == true)
				{
					cout << "You must add products first." << endl;
					break;
				}
				submenu();
				int response;
				cout << "Option: ";
				cin >> response;
				cin.ignore();
				switch (response)
				{
				case 1:
					ListAllSales2(myStore);
					SpecificSaleInfo(myStore.sales);
					break;
				case 2:
					ListAllSales(myStore.sales);
					break;
				case 3:
					ListSalesByDate(myStore.sales);
					break;
				case 4:
					ListSalesByPayment(myStore.sales);
					break;
				case 5:
					ListSalesByBilling(myStore.sales);
					break;
				case 6:
					ListAllInventory(myStore.products);
					SpecificProductInfo(myStore.products);
					break;
				case 7:
					ListAllInventory(myStore.products);
					break;
				case 8:
					ListProductsByLab(myStore.products);
					break;
				case 9:
					ListProductsToExpire(myStore.products);
					break;
				case 10:
					ListSalesByLab(myStore);
					break;
				default:
					cout << "Invalid option" << endl;
					break;
				}
				break;
			}

		case 4:
			runProgram = false;
			cout << "You have exited the program.";
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}
}
