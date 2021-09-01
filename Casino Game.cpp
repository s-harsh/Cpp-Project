// ===================================================================================================
//                               ||   LUCK GAME  ||
// ===================================================================================================


// **
//                       ~ HEADER FILES USED IN PROJECT ~
// **

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ***
//                               ~ MAIN FUNCTION ~
// ***

int main()
{
    
    string playerName;
    int amount;              //  Holds player's amount 
    int bettingAmount;
    char b;                  // Number to start game
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
    cout<< "\t\t                |          ##### WELCOME TO LUCKY WHEEl #####          | " << endl;
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
    cout << "\n-----------LET'S TRY YOUR LUCK!!------------\n" << endl;
    cout << "  :) Test Your Luck with our Luck Game :)    " << endl;
    cout<<"   "<<endl;
    cout<<"GOOD LUCK!! ^_^"<<endl;
    cout<<" \n@(^_^)@\n"<<endl;
    
    // Input user's name
    cout<<"Enter your Name: "<<endl;
    // cin>>playerName; 
    getline(cin,playerName);
    // Input user's deposit amount
    cout<<"Enter Deposit amount to play game:$ "<<endl;
    cin>>amount;

    // RULES of game
cout<<"=========================================================================================================================\n"<<endl;
cout<<"***"<<endl;
cout<<"              |            RULES OF THE GAME            |         "<<endl;
cout<<"***\n"<<endl;
cout<<"1."<<"If all the three randomly generated numbers are equal to 6, then you will win money 10 times of the money you bet."<<endl;
cout<<"2."<<"\nIf all the three numbers are same, then you will get money 8 times of money you bet."<<endl;
cout<<"3."<<"\nIf first two numbers are same, then you will get money 5 times of money you bet."<<endl;
cout<<"4."<<"\nIf last two numers are same, then you will get money 4 times of money you bet."<<endl;
cout<<"5."<<"\nIf first and last numbers are same, then you will get money 2 times the money you bet."<<endl;
cout<<"6."<<"\nIf all the numbers are different, then you will loose all the money you bet."<<endl;
cout<<"========================================================================================================================="<<endl;

    cout<<"Your current amount is $ "<<amount<<"\n";
    if(amount==0)
    {
    cout<<"You don't have money to play!"<<endl;
    return 0;
    }
    // Input Money to bet
    
     do
        {
            cout <<playerName<<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
        Re:
        //char b;
    cout << "Enter any number & then click Enter button to start the game: " << endl;
    cin>>b;

    if(b>='0' && b<='9')
    {
    	b;
    	goto Start;
	}
	else
	{
		cout<<"Re-enter number"<<endl;
		goto Re;
	}
 Start:   
    cout << "You got following outcomes: " << endl;
    

	
    replay:
    srand(time(0));

    int dice1 = (int)(1 + rand() % 6);    // dice1, dice2, dice3 holds the randomly generated number between 1 to 6.
    cout << dice1 << endl;                           
    int dice2 = (int)(1 + rand() % 6);
    cout << dice2 << endl;
    int dice3 = (int)(1 + rand() % 6);
    cout << dice3 << endl;

// ------------------------------------------------------------------------------------------------------------------------------
// Various cases to win the game
     if (dice1 == dice2== dice3==6 )
     {
        cout << "Hurray!!! You Won $"<<bettingAmount*10<<" \t You can become a Millionare"<<endl;
        amount= amount+ bettingAmount*10;
     }
    else if(dice1 == dice2 == dice3) 
    { 
        cout<<"Brilliant!!! You Won $"<<bettingAmount*8<<" \t You Hate Maths........But You love counting Money!!"<<endl; 
        amount= amount+ bettingAmount*8; 
    }
    else if ( dice1 == dice2 && dice2 != dice3 )
    {
      cout << "Bravo!! You Won $"<<bettingAmount*5<<" \t Work until your bank account looks like a phone number :D "<<endl; 
      amount = amount + bettingAmount*5;
    }
    else if (dice2 == dice3 && dice1 != dice3)
    {
        cout << "Congratulations!! You won $"<<bettingAmount*4<<" \t Winning is FUN! "<<endl;
        amount = amount + bettingAmount*4;
    }
    else if (dice1 == dice3 && dice2 != dice3)   
    { 
        cout << "Fantastic! You won $"<<bettingAmount*2<<" \tYou are a genius! You can make money in bed :D"<<endl;
        amount = amount + bettingAmount*2;
    }
    else
    {
    cout << "Sorry! You loose!! You Lost $"<<bettingAmount<<" \tBetter Luck Next Time!"<<"";
    amount = amount - bettingAmount;
    }
// ---------------------------------------------------------------------------------------------------------------------
    cout<<" \n Hope You Enjoyed our game!!"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<" | "<<"Thanks for Playing!  Your balance amount is $ "<<amount<<" | "<<endl;
    cout<<"-------------------------------------------------------------"<<endl;

//~ For REPLAY ~~~ 
   
    int e=1;
     
    cout << " Press 1 for Replay or Press any key to Exit"<<endl;
    cin>>e;
    if ( e == 1){

        if(amount==0)
        {
        cout<<"Sorry!! You don't have money to play!"<<endl;    
        }
        else{
        cout<<"Your current amount is $ "<<amount<<"\n";
        do
        {
            cout <<playerName<<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);    
      Reenter:
        cout << "Enter any number & then click Enter button to start the game: " << endl;
        cin >> b;
         if(b>='0' && b<='9')
    {
    	b;
    	goto number;
	}
	else
	{
		cout<<"Re-enter number"<<endl;
		goto Reenter;
	}
	number:
        cout << "You got following outcomes: " << endl;   
        goto replay ;              
    
        return 0;
        }
    }
    else
    exit(0);
    return 0;
//~~~ 
}
// ***
//                          ~   END of the program!   ~
// *
