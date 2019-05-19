/****SAMPLE PROGRAM HEADER*******************************************************
Lofton Bullard	        Total Points:  10
Due Date:  2/4/2013
Course:  C0P3014
Assignment:  Assignment 1
Professor: Dr. Lofton Bullard

Description: (Your program description goes here -- what it does--In the program we processed....


*************************************************************/
#include <iostream> //standard library for i/o
#include <string>   // always include this when you use the string class

using namespace std;
double tax_rate_result(int number_relays)
{
	double answer = 0.0;
	if (0 <= number_relays && number_relays <= 5)
	{
		answer = 0.01;
	}
	else if (6 <= number_relays && number_relays <= 11)
	{
		answer = 0.03;
	}
	else if (12 <= number_relays && number_relays <= 20)
	{
		answer = 0.05;
	}
	else if (21 <= number_relays && number_relays <= 50)
	{
		answer = 0.08;
	}
	else if (number_relays > 50)
	{
		answer = 0.12;
	}
	return answer;
}
double call_net_cost(int number_relays, double call_length)
{
	return (number_relays / 50.0 * 0.40 * call_length);
}
int main()
{
	string user_response = "y";
	string cell_num = "0";
	int relays = 0;
	double call_length = 0.0;
	double tax_rate = 0.0;
	double net_cost = 0.0;
	double call_tax = 0.0;
	double total_cost = 0.0;
	while (user_response == "y" || user_response == "Y")
	{
		//The code to get the user's input, perform the calculations, and print
		cout << "Please enter the cellphone number." << endl;
		cin >> cell_num;
		cout << "Please enter the the number of relays." << endl;
		cin >> relays;
		cout << "Please enter the the call length." << endl;
		cin >> call_length;
		// the results to the screen should go here.
		tax_rate = tax_rate_result(relays);
		net_cost = call_net_cost(relays, call_length);
		call_tax = net_cost * tax_rate;
		total_cost = net_cost + call_tax;
		//this is how you round to the hundreds place
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << "Cell Phone"
			 << "    " << cell_num << endl;
		cout << "Number of Relay Stations"
			 << "    " << relays << endl;
		cout << "Minutes Used"
			 << "    " << call_length << endl;
		cout << "Net Cost"
			 << "    " << net_cost << endl;
		cout << "Tax Rate"
			 << "    " << tax_rate << endl;
		cout << "Call Tax"
			 << "    " << call_tax << endl;
		cout << "Total Cost of Call"
			 << "    " << total_cost << endl;
		cout << "Would you like to do another calculation (Y or N): " << endl;
		cin >> user_response;
	}

	return 0;
}
