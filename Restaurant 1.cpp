#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
struct menu
{
	string name;
	int price;
}arr[30];

int limit, sum = 0, orders, o, extra, orderno, check[15];
int j = 0;

void welcome(void)
{
	cout << "\n \t \t  |______Welcome to our Restaurant______| \n \n";
}
void printmenu(menu arr[30])
{
	cout << "\n  \n --------------------------------------------------MENU--------------------------------------------------" << endl;
	cout << "\n  !FAST FOOD!                               " << endl << endl;
	for (int i = 0; i <= 7; i++)
	{
		cout << i + 1 << ":" << arr[i].name << setw(10) <<"Rs."<< arr[i].price;
		cout << "\n";
	}
	cout << " \n !DESSERTS!                               " << endl << endl;
	for (int i = 8; i <= 10; i++)
	{
		cout << i + 1 << ":" << arr[i].name << setw(10) <<"Rs."<< arr[i].price;
		cout << "\n";
	}
	cout << "\n !DRINKS!                             " << endl << endl;
	for (int i = 11; i <= 20; i++)
	{
		cout << i + 1 << ":" << arr[i].name << setw(10) <<"Rs."<< arr[i].price;
		cout << "\n";
	}
	cout << "\n \n";
}

void printMenu(menu arr[30])
{
	cout << "So, In our restaurant you can order following thing,Please choose  :" << endl;
	for (int i = 0; i <= 20; i++)
	{

		if (arr[i].price <= limit)
		{
			cout << i + 1 << "\t" << arr[i].name<< endl;
		}

	}
}

int main()
{
	arr[0].name = "pizza         \t";
	arr[0].price = 300;

	arr[1].name = "burger        \t";
	arr[1].price = 60;

	arr[2].name = "momos         \t";
	arr[2].price = 50;

	arr[3].name = "manchuriyaan   \t";
	arr[3].price = 80;

	arr[4].name = "sandwich       \t";
	arr[4].price = 40;

	arr[5].name = "chowmein       \t";
	arr[5].price = 100;

	arr[6].name = "spring roll    \t";
	arr[6].price = 150;

	arr[7].name = "pasta          \t";
	arr[7].price = 120;

	arr[8].name = "patry           \t";
	arr[8].price = 70;

	arr[9].name = "donuts          \t";
	arr[9].price = 60;

	arr[10].name = "cupcake        \t";
	arr[10].price = 80;

	arr[11].name = "banana shake   \t";
	arr[11].price = 50;

	arr[12].name = "mango shake    \t";
	arr[12].price = 60;

	arr[13].name = "papaya shake   \t";
	arr[13].price = 40;

	arr[14].name = "chocolate shake \t";
	arr[14].price = 65;

	arr[15].name = "apple shake     \t";
	arr[15].price = 45;

	arr[16].name = "pineapple shake \t";
	arr[16].price = 75;

	arr[17].name = "strawberry shake \t";
	arr[17].price = 85;

	arr[18].name = "oreo shake       \t";
	arr[18].price = 70;

	arr[19].name = "vaneela shake    \t";
	arr[19].price = 55;

	arr[20].name = "keshar pista shake \t";
	arr[20].price = 95;

	welcome();

	printmenu(arr);

	cout << "Enter amount : \t" ;
	cin >> limit;

	system("cls");
	welcome();

	if (limit < 40)
	{
		goto end;
	}

	printMenu(arr);

	cout << "Enter how many thing you want to order: " << "\t";

	cin >> orders;

	cout << "Enter you desire orders from above order list:" << "\t";
	for (int i = 0; i < orders; i++)
	{ 
	start:

		cin >> orderno;
		//cout << "\t";
		if (i == 0)
		{
			if (limit >= arr[orderno - 1].price)
			{
				goto order;
			}
			else
			{
				system("cls");
				printMenu(arr);
				cout << "You have to order from above list:" << endl;
				goto start;
			}
		}
		if (i >= 1)
		{

			if (extra >= arr[orderno - 1].price)                       
			{
				goto order;
			}               

			else
			{
				cout << "You have to order from above list :" <<"\t";
				goto start;
			}
		}
	order:
        cout<<"your order number"<<":"<<i+1<<"."<<arr[orderno-1].name<<"is Rs."<<arr[orderno-1].price<<"\t";
         sum = sum + arr[orderno - 1].price;
		//cout << " \n Sum of order is : " << sum << endl;
		if (sum <= limit)
		{
			extra = limit - sum;
			cout << " \n Your extra amount is = Rs." << extra << endl<<endl;
			if (extra < 40)
			{
				cout << "\nYour extra amount is = Rs. " << extra << "\n Sorry You can't order another item from that amount" << endl;
				break;
				goto end;
			}
			for (int i = 0; i <= 20; i++)
			{
				if (extra >= arr[i].price)
				{
					j++;
					cout << "You can order more items from  " << i + 1 << " " << arr[i].name <<" \n";
					continue;
				}
			}
			i++;
			goto start;


		}
		else if (sum > limit)
		{
			cout << "  You have used your full money. ";
			break;
		}
	}   
	
end:
	 cout << endl;
	cout << "\n \n \t _______Thanks For Visting_______";
	
	return 0;
}
