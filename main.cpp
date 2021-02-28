#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    int count = 0;
    int input=0, TotData=0, endCount=0;
    double score[100], average;
    double TotScore = 0;
    string line_;
    string name[100];
    ifstream in_stream;
    ifstream file("gpacinta.txt");

    while(getline(file,line_))
        {
            getline(file,line_);
            TotData++;
        }
    file.close();

    ifstream file_("gpacinta.txt");
    cout << "How many students ? ";
    cin  >> input;

    while (input <= 0 || input >= TotData){
        cout << "Your input more than the limit " << TotData << endl;
        cout << "Input correctly Please!";
        cin >> input;
    }

    if (file_.is_open())
    {
        for(int i=0; i<input; i++)
        {
            getline(file_,line_);
            name[count] = line_;
            cout << line_ << '\t';
            getline(file_,line_);
            istringstream(line_) >> score[count];
            cout << line_ << endl;
            TotScore += score[count];
            count++;
            average = TotScore/count;
        }
        file_.close();
    }
    else
    cout << "file is not open" << '\n';

    cout << '\n' << count << " Students found!" << endl;
    cout << "The average GPA is : " << average << endl;
    cout << '\n' << "Student with GPA above Average : " << endl;

    for(int i=0; i<count; i++){
        if(score[i] >= average){
        cout << name[i] << '\t' << showpoint << setprecision(2) << score[i] << endl;
        endCount++;}
    }
    cout << '\n' << "Total students with GPA above the average :" << endCount << endl;
    return 0;
}
