



/************************************************************************************************************************

Name: Nicolas A. Serna                                 Z#:
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:                      Due Time:
Total Points: 20
Assignment #2: amazon_orders.cpp

Description:

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream> //you must include this library if you wish to do file i/o
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class order_record
{
public:
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	// ///////////////////////////////
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
};

//Prototypes for your functions: input, output, and process will go here

void input(ifstream &, order_record &);
void output(const order_record &);
void process(order_record &);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: the program has not gotten the information provided by the text file
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: the parameters cell_number, item_number, quantity, price, and processing_plant are obtained through the iput of the text file
// Example: the varaibles (formal parameters) have been initialized
//Description:
// Example:Get input (values of cell_number, item_number, quantity, price, processing_plant )
//from data file order record (p_record).

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream &in, order_record &p_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> p_record.cell_number;
	in >> p_record.item_number;
	in >> p_record.quantity;
	in >> p_record.price;
	in >> p_record.processing_plant;
}
///*************************************************************************************
//Name:  output
//Precondition: no data is displayed.
//Postcondition: all data is displayed .
//Description:  this function displays all the information from the class order_record
//*************************************************************************************

void output(const order_record &p_record)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	cout << p_record.cell_number << "\t" << p_record.item_number << "\t" << p_record.quantity << "\t" << p_record.price << "\t" << p_record.processing_plant << "\t" << //
		p_record.tax_rate << "\t" << p_record.order_tax << "\t" << p_record.net_cost << "\t" << p_record.total_cost << endl;
}

double taxRateResult(order_record &p_record)
{
	/*(0<= processing_plant <= 50 then
	tax_rate = 6%; 51<= processing_plant <=110 then tax_rate = 7%; 111<= processing_plant<=200 then tax_rate = 8%; 
	201<= processing_plant <=500 then tax_rate = 9%; processing_plant >500 then tax_rate =11%) .
	*/
	if (0 <= p_record.processing_plant && p_record.processing_plant <= 50)
	{
		return 0.06;
	}
	else if (51 <= p_record.processing_plant && p_record.processing_plant <= 110)
	{
		return 0.07;
	}
	else if (111 <= p_record.processing_plant && p_record.processing_plant <= 200)
	{
		return 0.08;
	}
	else if (201 <= p_record.processing_plant && p_record.processing_plant <= 500)
	{
		return 0.09;
	}
	else if (p_record.processing_plant > 500)
	{
		return 0.11;
	}
	else
	{
		return 0.0;
	}
}
///*************************************************************************************
//Name:  process
//Precondition: some values in the class order_record are equal to null.
//Postcondition: all values in the order_record class are processed and given a value based on certai equations.
//Description:  utilizes certain equation in order to assign a value to all the parameters in the class order_record.
//*************************************************************************************

//Note: there is one 1 input/output parameter
void process(order_record &p_record)
{

	//tax rate on an order
	p_record.tax_rate = taxRateResult(p_record);
	//tax on an order
	p_record.order_tax = p_record.quantity * p_record.price * p_record.tax_rate;
	//net cost
	p_record.net_cost = p_record.quantity * p_record.price;
	//total_cost
	p_record.total_cost = p_record.net_cost + p_record.order_tax;
}

//Here is your driver to test the program
int main()
{

	order_record customer_record;

	ifstream in; //declaring an input file stream
	in.open("purchase_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{
			input(in, customer_record);
			process(customer_record);
			output(customer_record);
		}
	}

	in.close();

	return 0;
}
