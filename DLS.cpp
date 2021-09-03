#include <iostream>
#include<stdlib.h>
using namespace std;

// project globle variables

int score1 = 0, score2 = 0, overs = 0, wickets = 0, team2run, rungape;
double resource;

//dls resources table, called by fucntion
//It is only for 50 over match.

double table(int i, int j)
{
    double arr[51][10] = { {100,99.4,85.1,74.9,62.7,49,34.9,22,11.9,4.7},
        {99.1,92.6,84.5,74.4,62.5,48.9,34.9,22.0,11.9,4.7},
        {98.1,91.7,83.8,74,62.2,48.8,34.9,22,11.9,4.7},
        {97.1,90.9,83.2,73.5,61.9,48.6,34.9,12,11.9,4.7},
        {96.1,90.0,82.5,73.0,61.6,48.5,34.8,22,11.9,4.7},
        {95,89.1,81.8,72.5,61,48.4,34.8,22,11.9,4.7},
        {93.9,88.2,81.0,72.0,61.0,48.3,34.8,22,11.9,4.7},
        {92.8,87.3,80.3,71.4,60.7,48.1,34.7,22,11.9,4.7},
        {91.7,86.3,79.5,70.9,60.3,47.9,34.7,22,11.9,4.7},
        {90.5,85.3,78.7,70.3,59.9,47.8,34.6,22,11.9,4.7},
        {89.3,84.2,77.8,69.6,59.5,47.6,34.6,22,11.9,4.7},
        {86.7,82,76,68.3,58.7,47.1,34.5,21.9,11.9,4.7},
        {85.4,80.9,75.0,67.6,58.2,46.9,34.4,22.9,11.9,4.7},
        {84.1,79.7,74.1,66.8,57.7,46.4,34.2,21.9,11.9,4.7},
        {82.7,78.5,73,66,57.2,46.4,34.2,21.9,11.9,4.7},
        {81.3,77.2,72,65.2,56.6,46.1,34.1,22.9,11.9,4.7},
        {79.3,75.9,70.9,64.4,56,45.8,34,21.9,11.9,4.7},
        {78.3,74.6,69.7,63.5,55.4,45.4,33.9,21.9,11.9,4.7},
        {76.7,73.2,68.6,62.5,54.8,45.1,33.7,21.9,11.9,4.7},
        {75.1,71.8,67.3,61.6,54.1,44.7,33.6,21.8,11.9,4.7},
        {73.5,70.3,66.1,60.5,53.4,44.2,33.4,21.8,11.9,4.7},
        {71.8,68.8,64.8,59.5,52.6,43.8,33.2,21.8,11.9,4.7},
        {70.1,67.2,63.4,58.4,51.8,43.3,33,21.7,11.9,4.7},
        {68.3,65.6,62,57.2,50.9,42.8,32.8,21.7,11.9,4.7},
        {66.5,6.9,60.5,56.0,50.0,42.4,32.6,21.6,11.9,4.7},
        {62.7,60.4,57.4,53.4,48.0,40.9,32.0,21.5,11.9,4.7},
        {60.7,58.6,55.8,52.0,47.0,40.2,31.6,21.4,11.9,4.7} ,
        {58.7,56.7,54.1,50.6,45.8,39.4,31.2,21.3,11.9,4.7} ,
        {56.6,54.8,52.4,49.1,44.6,38.6,30.8,21.2,11.9,4.7} ,
        {54.4,52.8,50.5,47.5,43.4,37.7,30.3,21.1,11.9,4.7} ,
        {52.2,50.7,48.6,45.9,42.0,36.8,29.8,20.9,11.9,4.7} ,
        {49.9,48.5,46.7,44.1,40.6,35.8,29.2,20.7,11.9,4.7} ,
        {47.6,46.3,44.7,42.3,39.1,34.7,28.5,20.5,11.8,4.7} ,
        {45.2,44.1,42.6,40.5,37.6,33.5,27.8,20.2,11.8,4.7} ,
        {42.7,41.7,40.4,38.5,35.9,32.2,27.0,19.9,11.8,4.7} ,
        {40.2,39.3,38.1,36.5,34.2,30.8,26.1,19.5,11.7,4.7} ,
        {37.6,36.8,35.8,34.3,32.3,29.4,25.1,19.0,11.6,4.7} ,
        {34.9,34.2,33.4,32.1,30.4,27.8,24.0,18.5,11.5,4.7} ,
        {32.1,31.6,30.8,29.8,28.3,26.1,22.8,17.9,11.4,4.7} ,
        {29.3,28.9,28.2,27.4,26.1,24.2,21.4,17.1,11.2,4.7} ,
        {26.4,26.0,25.5,24.8,29.8,22.3,19.9,16.2,10.9,4.7} ,
        {23.4,23.1,22.7,22.2,21.4,20.1,18.2,15.2,10.5,4.7} ,
        {20.3,20.1,19.8,19.4,18.8,17.8,16.4,13.9,10.1,4.6} ,
        {17.2,17.0,16.8,16.5,16.1,15.4,14.3,12.5,9.4,4.6} ,
        {19.9,19.8,19.7,19.5,19.2,12.7,12.0,10.7,8.4,4.5} ,
        {10.6,10.5,10.4,10.3,10.2,9.9,9.5,8.7,7.2,4.2} ,
        {7.2,7.1,7.1,7.0,7.0,6.8,6.6,6.2,5.5,3.7} ,
        {3.6,3.6,3.6,3.6,3.6,3.5,3.5,3.4,3.2,2.5} ,
        {0,0,0,0,0,0,0,0,0}
         };
    return arr[i][j];
}
// Project Welcome code, called by function
void welcome()
{
    cout << "\t \t \t\t \t |______________________________ Welcome to DLS Calculator ______________________________| \n \n" ;
}

int main()
{
	start:
	system("cls");
	int inning,stopTime,reduceOver=0;
    float overRate=15;

    welcome();

    cout<<"select one option, either the match is stopped in first inning or in second inning: "<<endl;
	cout<<"1.>  If, match stopped in the First inning"<<endl;
	cout<<"2.>  If, match stopped in the Second inning"<<endl;
	cin>>inning;
    
    if(inning==1)
    {
        cout<<"So, Match stopped in first inning : \n \n";

        cout<<"Enter that the time the match has been stopped (in minutes)."<<endl;
        cin>>stopTime;

        reduceOver=50-((overRate/60)*stopTime);
        cout<<"Then reduced overs are : "<<reduceOver<<endl;

        cout<<"So, Both team will play only "<<reduceOver<<" overs"<<endl;
	}
	else if(inning==2)
	{
	cout<<"So, Match stopped in second inning : \n \n";

	cout << "Team1 Score: \t";
    cin >> score1;
    cout << "\n ";

    cout << "Team2 Score that it made before stoping the match: \t";
    cin >> team2run;
    cout << "\n ";

    cout << "Enter Remaining overs of team2 : \t ";
    cin >> overs;

    if (overs < 50)
    {
        cout << "Entered remaining overs are : " << overs << endl;
    }
    else
    {
        cout << "Please enter vaid wickets!!! Re-enter lost wickets" << endl;
        cin >> overs;
    }
    cout << "\n ";

    cout << "Enter Lost wickets of team2 : \t";
    cin >> wickets;

    if (wickets < 9)
    {
        cout << "Entered lost wickets are : " << wickets << endl;
    }
    else
    {
        cout << "Please enter vaid wickets!!! Re-enter lost wickets" << endl;
        cin >> wickets;
    }

    cout << "\n \n";

    int i, j;

    j = wickets;

    i = (50 - overs);

    resource = 100 - table(i, j);

    score2 = (score1 * resource) / 100;
    rungape = team2run - score2;

    cout << "So, Team2 has" << resource << "% resources available." << "\n \n";

    if (team2run > score2)
    {
        cout << "Team2 is the winner & win the match from " << rungape << " runs." << "\n \n \n";
    }
    else
    {
        cout << "Team1 is the winner & win the match from "<<rungape<<"runs." << endl;
    }
		
	}
	
	else
	{
		cout<<"Please select from given options"<<endl;
		goto start;
	}
    cout << "\n  \t \t Thanks !!!!" << endl;
    return 0;
}
