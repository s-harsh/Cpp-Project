#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <windows.h>
#include <time.h>


using namespace std;
class person
{
private:
    string name, adhar_no, vaccine, city, email_id, contact_no, year, gender;

public:
    void login();
    void menu();
    void insert();
    void display();
    void download();
    void deleted();
    void search();
};

//==============================================================================================================
//Code for the sign up and login pcity
//============================================================================================================

void person::login()
{
    cout << "_______________________________________________________________________________________________" << endl;
    cout << "###############################################################################################" << endl;
    cout << "_______________________________________________________________________________________________" << endl;

    cout << "\n\n\t\t\t\tVaccine Management System " << endl;
    cout << "_______________________________________________________________________________________________" << endl;
    cout << "###############################################################################################" << endl;
    cout << "_______________________________________________________________________________________________" << endl;

    cout << "\n\n\t\t\t\t\t Sign up !!" << endl;

    string username, adhar;
    cout << "\n\t\t*  Enter the name of person to be registred for vaccination: ";
    cin >> username;
    cout << "\t\t * Enter last 4 digits of your Adhar number: ";
    cin >> adhar;
    cout << "\n\n\t\t Your ID is been creating please wait";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(1000);  // pauses the screen for 1 millisecond
    }
    cout << "\n\t\t Your ID has been successfully created !!" << endl;
    system("CLS");  //clears the screen.

    cout << "_______________________________________________________________________________________________" << endl;
    cout << "###############################################################################################" << endl;
    cout << "_______________________________________________________________________________________________" << endl;

    cout << "\n\n\t\t\t\tVaccine Management System " << endl;
    cout << "_______________________________________________________________________________________________" << endl;
    cout << "###############################################################################################" << endl;
    cout << "_______________________________________________________________________________________________" << endl;
start:
    time_t timetoday;                 //displays current time of the system 
    time(&timetoday);
    cout << asctime(localtime(&timetoday));

    cout << "\n\n\t\t\t\t\t Login!!" << endl;
    string username1, adhar1;
    cout << "Name of the person: ";
    cin >> username1;
    cout << "last 4 digits of Aadhar number: ";
    cin >> adhar1;
    if (username1 == username && adhar == adhar1)
    {
        srand(time(0));  //this function generates a new captcha everytime. Only rand() will be generating the same sequence of numbers.
        int lower = 1000;
        int upper = 9999;
        int captcha = (rand() % (upper - lower + 1)) + lower;
        cout << "\n\n\t\t******************" << endl;
        cout << "\t\t" << captcha << endl;
        cout << "\t\t******************" << endl;
        cout << "\n\n\t\tEnter the Captcha sequence:-  ";
        int input;
        cin >> input;
        if (captcha == input)
        {
            cout << "Access Granted" << endl;
            menu();
        }
        else
        {
            cout << "Access Denied" << endl;
            Sleep(3000);
            goto start;
        }
    }
    else if (username1 != username)
    {
        cout << "Incorrect user name...Please recheck" << endl;
        Sleep(3000);
        goto start;
    }
    else
    {
        cout << "Incorrect aadhar number for this user" << endl;
        Sleep(3000);
        goto start;
    }
}

//==========================================================================================
//code for the main menu
//==========================================================================================

void person::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "_______________________________________________________________________________________________" << endl;
    cout << "###############################################################################################" << endl;
    cout << "_______________________________________________________________________________________________" << endl;

    cout << "\n\n\t\t\t\tVaccine Management System " << endl;
    cout << "_______________________________________________________________________________________________" << endl;
    cout << "###############################################################################################" << endl;
    cout << "_______________________________________________________________________________________________" << endl;

    cout << "\t\t\t 1. Enter your Data" << endl;                              //insert data
    cout << "\t\t\t 2. Display Record of all the persons vaccinated" << endl; //display
    cout << "\t\t\t 3. Search your data" << endl;                             //search data 
    cout << "\t\t\t 4. Download your vaccine certificate" << endl;            //download records
    cout << "\t\t\t 5. Delete Record" << endl;                                //delete
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another person Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        search();
        break;
    case 4:
        download();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}

//==========================================================================================
//code to enter details of person
//==========================================================================================

void person::insert() // add person's details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add person Details ---------------------------------------------" << endl;

    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Last 4 digits of your Adhar Number.: ";
    cin >> adhar_no;
    cout << "\t\t\tVaccine Injected: ";
    cin >> vaccine;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_no;
    cout << "\t\t\tEnter city: ";
    cin >> city;
    cout << "\t\t\tEnter Birth year(yyyy): ";
    cin >> year;
    cout << "\t\t\tGender : ";
    cin >> gender;
    file.open("personRecord.txt", ios::app | ios::out);
    file << " " << name << " " << adhar_no << " " << vaccine << " " << email_id << " " << contact_no << " " << city << " " << year << " " << gender << "\n";
    file.close();
}

//******************************************************************************************
//code to display data of all (just the name and the vaccine injected)
//==========================================================================================

void person::display() // display persons details
{
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Record Table --------------------------------------------" << endl;
    file.open("personRecord.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> name >> adhar_no >> vaccine >> email_id >> contact_no >> city >> year >> gender;

        while (!file.eof())
        {
            cout << "\n\n\t\t\t person No.: " << ++total << endl;
            cout << "\t\t\t Name: " << name << endl;
            //cout << "\t\t\t Adhar number: " << adhar_no << endl;
            cout << "\t\t\t Vaccine Injected: " << vaccine << endl;
            // cout << "\t\t\t registered Email Id.: " << email_id << endl;
            // cout << "\t\t\t Contact No.: " << contact_no << endl;
            // cout << "\t\t\t city: " << city << endl;
            // cout << "\t\t\t Birth year : " << year << endl;
            // cout << "\t\t\t gender : " << gender << endl;

            file >> name >> adhar_no >> vaccine >> email_id >> contact_no >> city >> year >> gender;
        }

        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}

//==========================================================================================
//code to download the certificates
//==========================================================================================

void person::download() // download certificate of person
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("personRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Download your certificate ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string adharno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "-------------------------------------Download your certificate ------------------------------------------" << endl;
        cout << "\n Enter your Adhar Number : ";
        cin >> adharno;
        file >> name >> adhar_no >> vaccine >> email_id >> contact_no >> city >> year >> gender;
        while (!file.eof())
        {
            if (adharno == adhar_no)
            {
                cout << "\n\tThe vaccine certificate of " << name << " has been successfully sent to the mail ID " << email_id << ". Kindly check your mail. " << endl;

                found++;
            }
            file >> name >> adhar_no >> vaccine >> email_id >> contact_no >> city >> year >> gender;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t No person registered by this adhar number! Please register yourself first";
        }
        file.close();
    }
}

//==========================================================================================
//code to delete data
//==========================================================================================

void person::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string ID;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Details ------------------------------------------" << endl;
    file.open("personRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Aadhar number of the person which you want Delete Data: ";
        cin >> ID;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> adhar_no >> vaccine >> email_id >> contact_no >> city >> year >> gender;
        while (!file.eof())
        {
            if (ID != adhar_no)
            {
                file1 << " " << name << " " << adhar_no << " " << vaccine << " " << email_id << " " << contact_no << " " << city << " " << year << " " << gender << "\n";
            }
            else
            {
                found++;
                cout << "\n\t Data for this Aadhar number has been deleted successfully !";
            }
            file >> name >> adhar_no >> vaccine >> email_id >> contact_no >> city >> year >> gender;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t person ID NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("personRecord.txt");
        rename("record.txt", "personRecord.txt");
    }
}

//==========================================================================================
//code to search the data
//==========================================================================================
void person::search()
{
    system("cls");
    fstream file;
    int found = 0;
    int count = 0;
    file.open("personRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present for this Aadhar Number...";
    }
    else
    {
        string adharno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Search Data ------------------------------------------" << endl;
        cout << "\n Enter your Aadhar Number to Search for your data: ";
        cin >> adharno;
        file >> name >> adhar_no >> vaccine >> email_id >> contact_no >> city >> year >> gender;
        while (!file.eof())
        {
            if (adharno == adhar_no)
            {
                cout << "\n\t\t\t Name: " << name << endl;
                cout << "\t\t\t ID No.: " << adhar_no << endl;
                cout << "\t\t\t Vaccine Injected: " << vaccine << endl;
                cout << "\t\t\t Email Id.: " << email_id << endl;
                cout << "\t\t\t city: " << city << endl;
                cout << "\t\t\t Birth Year : " << year << endl;
                cout << "\t\t\t Gender : " << gender << endl;
                found++;
            }
            file >> name >> adhar_no >> vaccine >> email_id >> contact_no >> city >> year >> gender;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t No Data present for this Aadhar number...";
        }
        file.close();
    }
}

//==========================================================================================
// MAIN
//==========================================================================================
main()
{
    person project;
    project.login();
    return 0;
}