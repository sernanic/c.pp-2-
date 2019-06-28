

//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name:                                 Z#:
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:                      Due Time:
Total Points: 20
Assignment #: amazon_purchase_recs.cpp

Description:

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;



class record{
    public:
        string cell_number;
        string item_number;
        int quantity;
        double price;
        int processing_plant;
        double tax_rate;
        double order_tax;
        double net_cost;
        double total_cost;
};

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, item_number, quantity, price, processing_plant ) 
//from data file.

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream & in, record *order_record)
{
	in >> order_record->cell_number >> order_record->item_number >> order_record->quantity>>
    order_record->price >> order_record->processing_plant;

}

///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************


void output(ofstream & output_to_file,record *order_record)
{

	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	output_to_file.setf(ios::showpoint);
	output_to_file.precision(2);
	output_to_file.setf(ios::fixed);
	/********************************************/


	output_to_file << order_record->cell_number << "\t" << order_record->item_number<<"\t"<<order_record->quantity
    <<"\t"<<order_record->price<<"\t"<<order_record->processing_plant<<"\t"<<order_record->tax_rate *100 <<"\t"<<
    order_record->order_tax<<"\t"<<order_record->net_cost<<"\t"<<order_record->total_cost<<endl;
	//add more code to print all the variables


}




///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************


//Note: there is one 1 input/output parameter
void process(record &order_record)
{
    // solve for tax_rate
    if(0<=order_record.processing_plant && order_record.processing_plant <= 50){
        order_record.tax_rate = 0.06;
    }
    if(51<=order_record.processing_plant && order_record.processing_plant <= 110){
        order_record.tax_rate = 0.07;
    }
    if(110<=order_record.processing_plant && order_record.processing_plant <= 200){
        order_record.tax_rate = 0.06;
    }
    if(0<=order_record.processing_plant && order_record.processing_plant <= 50){
        order_record.tax_rate = 0.08;
    }
    if(201<=order_record.processing_plant && order_record.processing_plant <= 500){
        order_record.tax_rate = 0.09;
    }
    if (order_record.processing_plant > 500)
    {
        order_record.tax_rate = 0.11;
    }// end of tax_rate
    order_record.order_tax = (order_record.quantity) *(order_record.price) *(order_record.tax_rate);
    order_record.net_cost =  order_record.quantity * order_record.price;
    order_record.total_cost = order_record.net_cost + order_record.order_tax;

}

//Here is your driver to test the program
int main()
{

	ifstream in;    //declaring an input file stream
    ofstream outputFile;
    record order_record;
    string fileName = "";
    cout<< "Enter name of file you want to put the order_record in"<<endl;
    cin>>fileName;
	in.open("purchase_data.txt");
    outputFile.open(fileName);
	if (in.fail() || outputFile.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{

			input(in,&order_record);
			process(order_record);
			output(outputFile,&order_record);
		}
	}

	in.close();

	return 0;
}


