#include <iostream>
#include <iomanip>//this is needed for fomating output
using namespace std;

/*Plan for code:
* prompt
A cheese container can hold 2.76 kg of cheese. Each evening, a fromager ships containers of
cheese to a local grocery store. The cost of producing one container of cheese is $4.12,
and the profit of each container of cheese is $1.45.

 Write a program that does the following:
Prompts the user to enter the total amount of cheese produced each evening.
Outputs the number of containers needed to hold the cheese. (Round your answer to the nearest integer.)
Outputs the cost of producing the cheese.
Outputs the profit for producing cheese.
*plan

intro to program
user input into a float number
so then have total kg of cheese
then need to figure out how to round to int// will use ceil but this isnt in book, I dont think, so will force round up
all of the couts with x or containers was me testing the force round up

then will multiply that number by 4.12 for production cost
then  will multipy that numebr by 1.45 for profit per
output the info

these will be the function inside main ^
*/

//*after writing:
//will need to figure out the formating mentioned, it has to do with spaces and the *'s
//will also have to figure out how to format the output of profit/cost to show all 2 decimal places
//found from book that will need #include <iomanip> to format the output below
//so for the 2 decimal output need setprecision(2)
//need before it showpoint and fixed, shows 000 iunstead of e notation, showpoint will show trailing zeros, setprevision(2) makes it output only to
//tenth
//realised it needed to be rounded up and down, when returning as an int it does the same thing as rounding down
//so all I did was check for the decimal information being greater than .5 and if that is the case it will add 1
//and lose the decimal info essentialy rounding up

//IntroAndUserInputAndConversion
void Intro()
{ //this plays the intro
	string intro = " Containers Per Cheese Amount kg  ";
	cout << setfill('*');
	cout << setw(74) << "*" << endl;
	cout << setw(20) << "* " << intro << setw(19) << "*" << endl;
	cout << setw(74) << "*" << endl;
	cout << setfill(' ');

}

int ForceRound(float x)//this will round up the number
{
	//*BEFORE ISSUE WAS THOUGHT OF AND FIXED
	//x++;//this adds one
	//cout << x << endl;
	//return x;//this returns the number as an int
	//with the plus one and force to int, this will essentialy round up the number like ceil would

	//*AFTER ISSUE WAS THOUGHT OF AND FIXED
	//Issue I thought about for this force round up, if number is whole then it will round for no reason so will have to figure out solution
	//thought of checking some how with if statment
	//x = 9.9;//these were used to test my fix
	//x = 9.1;
	//x = 9;
	int y = x;//this removes decimal info and rounds down or gets same number
	float z = x - y;//this will only leave the decimal info if there is any
	if (z > .5)//this will round up if 
		//realised it wanted it to round up and down so made the cut off at .5 and if more than .5 then will round up
		// if lover than .5 in the decimal are will round down by cutting off the decimal infor when it returns it as an int
	{
		x++;//this adds one
	}
	return x;//this returns the number as an int
}

int IntroAndUserInputAndConversion()
{
	//Vars
	float cheese;//this will be the number of cheese input by the user
	float containers;//This will be the number of containers for 2.76kg of chees after rounding
	const float CONTAINER_CAN_HOLD = 2.76;
	Intro();//intro to the program
	//promt and user input
	cout << "please enter the total number of kilograms of cheese produced: ";
	cin >> cheese;
	containers = cheese / CONTAINER_CAN_HOLD;//this fives the amount of containers per cheese, and is a float
	//cout << containers << endl;
	containers = ForceRound(containers);//this rounds up by adding one and returning it as an int 
	//thus making it one higher and removing decimal info, practicaly making it a rounded up int
	//cout << containers << endl;
	return containers;
}

//CalculationsAndOutput
void CalculationsAndOutput(int x)//x is the number of containers
{//this one will display the output message and will do some calculations for production cost and profit numbers
	const float COST_PER_CONTAINER = 4.12;//this is the cost of production of one container
	const float PROFIT_PER_CONTAINER = 1.45;//this is the profit of one container
	float cost = x * COST_PER_CONTAINER;//this will give the total cost of producing all the containers
	float profit = x * PROFIT_PER_CONTAINER;//this will give the total profit off of containers
	cout << fixed << showpoint << setprecision(2);
	cout << "The number of containers to hold the chees is:" << setw(28) << x << endl;
	cout << "The cost of producing " << x << " container(s) of chees it: $" << setw(21) << cost << endl;
	cout << "The profit from producting " << x << " container(s) of cheese is: $" << setw(15) << profit << endl;
}
//MAIN
int main()
{
	//vars
	int x;//this will pass the containers var to calculations and output function
	x = IntroAndUserInputAndConversion();//input
	CalculationsAndOutput(x);//output
	return 0;
}