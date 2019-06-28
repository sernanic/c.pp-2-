
/************************************************************************************************************************

Name:  Lofton Bullard        Z#: Z111111111
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  06/05/2050           Due Time: 11:59 PM
Total Points: 2000
Assignment #: xyz.cpp

Description:

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;

const int SIZE = 50; //the capacity of the array which is the total amount
					  //of memory allocated to the array.  The is a static
					  //array, therefore the compiler will manage its memory,
					  //allocate and de-allocate the memory.


class order_record
{
public:
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
};


//Prototypes for your functions: input, output, process and tally_inventory will go here

void input(order_record  INV[ ], int & count);
void output(const order_record  INV[], const int  count);
void process(order_record  INV[], const int  count);
double tally_inventory(const order_record  INV[], const int count);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: the variables have not been initialized
//Postcondition: The variables are now initialized.
//Description:  Read contents from data file

//*************************************************************************************

void input(order_record  INV[], int & count)
{
	//declare an ifstream
	ifstream in;
	//open the ifstream with the data file name
	//use a while loop to read the data into the array INV
	in.open("purchase_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else{
		while (!in.eof() && count < SIZE)
			{

				in >> INV[count].cell_number >> INV[count].item_number>> INV[count].quantity
				>> INV[count].price>> INV[count].processing_plant;
			
				count++;
			}
	//close ifstream
		in.close();
	}
	
}

///*************************************************************************************
//Name:  output
//Precondition: All variables are initialized
//Postcondition: All variables are initialized.
//Description:  Prints the array to a datafile
//*************************************************************************************

void output(const order_record INV[ ], const int count)
{
	/********************************************/
	//declare an ofstream
	ofstream out;
	//open the ofstream with the data file name
	string fileName = "";
    cout<< "Enter name of file you want to put the order_record in"<<endl;
    cin>>fileName;
    out.open(fileName);
	//Use the following statement to help you format you our output. These statements are called the magic formula.
	out.setf(ios::showpoint); //remember, we are using out instead of cout
	out.precision(2);
	out.setf(ios::fixed);
	
	//use a for loop to print the data in the array INV
	for(int i=0; i<count; i++)// do not use SIZE
	{
		out << INV[i].cell_number << "\t"
		 << INV[i].item_number << "\t"
		 << INV[i].quantity << "\t"
		 << INV[i].price << "\t"
		 << INV[i].processing_plant << "\t"
	 	 << INV[i].tax_rate << "\t"
		 << INV[i].order_tax << "\t"
		 << INV[i].net_cost << "\t"
		 << INV[i].total_cost << "\t"
		<<endl;
	}
	//close the ouput file stream
	out.close();
}

///*************************************************************************************
//Name:  process
//Precondition: cell_number, item_number, quantity, price, and processing_plant initialized.
// tax_rate, tax_cost, net_cost, and total_cost not initialized.
//Postcondition: all variables are now initialized
//Description:  calculate tax rate, tax cost, net cost, and total cost.
//*************************************************************************************

void process(order_record INV[ ], const int count)
{
	//Remember to modify the code for an array
	//Hints: 
	//use a for loop to print the data in the array INV
	for(int i=0; i<count; i++)// do not use SIZE
	{
		// put your code here to process/calculate the tax_rate, order_tax, net_cost, and total_cost
		// calculate tax_rate
		if (0 <= INV[i].processing_plant && INV[i].processing_plant <= 50)
			INV[i].tax_rate = .06;
		else if (51 <= INV[i].processing_plant && INV[i].processing_plant <= 110)
			INV[i].tax_rate = .07;
		else if (111 <= INV[i].processing_plant && INV[i].processing_plant <= 200)
			INV[i].tax_rate = .08;
		else if (201 <= INV[i].processing_plant && INV[i].processing_plant <= 500)
			INV[i].tax_rate = .09;
		else if (501 <= INV[i].processing_plant)
			INV[i].tax_rate = .11;
		

		//calculate order tax
		INV[i].order_tax = INV[i].quantity * INV[i].price * INV[i].tax_rate;

		//calculate net cost of order
		INV[i].net_cost =  INV[i].quantity * INV[i].price;
		//calculate total cost of order
		INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
	}
	

}

///*************************************************************************************
//Name:  tally_results
//Precondition: you complete
//Postcondition: you complete
//Description: you complete
//*************************************************************************************
double tally_inventory(const order_record  INV[], const int  count)
{
	double average = 0.0; //you can call the average whatever you wish... This is just a hint
	for(int i=0; i<count; i++)// do not use SIZE
	{
		average += INV[i].total_cost;
		
	}
	average /= count;
	return average;
}

//Here is your driver to test the program
int main()
{
	int count = 0; //intializating count
	order_record INV[SIZE]; //declaring the static array

	//ADD ANY OTHER CODE YOU MAY NEED

	input(INV, count);
	process(INV, count);
	output(INV, count);
	cout << "Average Total Order Cost = " << tally_inventory(INV, count) << endl; 

	return 0;
}
