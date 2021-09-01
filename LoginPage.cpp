// *************
//                                   |   LOG-IN PAGE   |
// *************

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
// Header files for Timer
#include<cstdlib>
#include<iomanip>
#include<unistd.h>
#include<windows.h>
#include<ctime>
using namespace std;

int hours = 0;
int minutes = 0;
int seconds = 0;
// TIMER 
void displayClock()
{
    system("cls");
    cout << "                     TIMER       " << endl;
    cout << "------------------------------------------------" << endl;

    cout <<setw(30) <<setfill('0') << setw(2) << seconds << "\t  sec " << endl;
    cout << "------------------------------------------------" << endl;

}

void timer()
{
    while (true)
    {
        displayClock();
        sleep(1);
        seconds++;

        if (seconds == 6)
        {
            minutes++;
            if (minutes == 6)
            {
                hours++;
                minutes = 0;
            }
            seconds = 0;
            break;

        }
    }
}

void welcome()
{
    system("cls");

    cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout <<setw(50)<<" You have successfully logged-in!" << endl;
    cout <<setw(50)<<"Welcome to our page!!!" << endl;

}

int main()
{
    char password[] = "SP0211";
    char pass[32];                //to store password.
    int i = 0;
    int	static counter = 0;
    string username;
    char a;
    char exit;              //a Temp char

    while (counter < 3)
    {
    START:
        cout << "\n Enter Username -  ";
        cin >> username;

        cout << "\n Enter 6-digit Password - ";

        for (i = 0; i < 6; i++)
        {
            a = getch();
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
                //check if a is numeric or alphabet
            {
                pass[i] = a;//stores a in pass
                cout << "*";
            }
            if (a == '\b' && i >= 1)//if user typed backspace
                //i should be greater than 1.
            {
                cout << "\b \b";//rub the character behind the cursor.
                --i;
            }
             if (a == '\r')//if enter is pressed
             {
                 pass[i] = '\0';//null means end of string.
                 break;//break the loop
             }
        }

        /*
		here we can even check for minimum digits needed
        if (i <= 4)
        {
            cout << "\n Minimum 5 digits needed.\n Enter Again \t";
            getch();//It was not pausing :p
            goto START;
        }*/
        counter++;
       if (username == "Coders")
        {
            int b = (strcmp(pass, password));
            
                if (b == 0)
                {
                	welcome();
                    break;
                }
                else
                {  system("cls");
                 cout << "Invalid  Passward,Retry!!!! \n \n" << endl;
                	cout<<"enter correct password"<<endl;
				goto START;
				}
            
        }
        else
        {
            system("cls");
            cout << "Invalid Username or Passward,Retry!!!! \n \n" << endl;
            //  counter++;
        }
        if (counter == 3)
        {
            cout << "\n Too many login attempts!\n" << endl;
            cout << "If you want to retry press any key and wait for 5 secoends" << endl<< "If not then press 0" << endl; 
            cin >> exit;
            if (exit == '0')
            {
                goto END;
            }

            else
            {
                timer();

                counter = 1;
                goto START;

                return 0;
            }
        }
    }
END:
    return 0;
}
