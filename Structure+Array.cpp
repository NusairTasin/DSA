/*This code shows how to implement an array 
of stuctures & array as a data member of structure*/
#include <iostream>
#include <string>
using namespace std;
struct student{
    string name;
    string id;
    double cgpa[3]; // Array of CGPA
};

int main(){
    int n;
    cout <<"Enter the number of students: ";
    cin >> n;
    student cse[n];  // Array of Structures i.e. number of students

    //Travarse through every student for input
    for(int i=0; i<n; ++i)
    {
        cin.ignore();
        cout << endl << "Enter the details of student " << i+1 << ":"<<endl;
        cout << "Name: "; getline(cin, cse[i].name);
        cout << "ID: "; cin >> cse[i].id;

        for(int j=0; j<3; ++j) //Travarse through Array of CGPA
        {
            cout << "Enter CGPA of Semester " << j+1 <<": "; 
            cin >> cse[i].cgpa[j];
        }
    }

    // Printing all the data
    for(int i=0; i<n; ++i)
    {
        cout << endl << "Details of student " << i+1 << ":"<<endl;
        cout << "Name: " << cse[i].name << endl;
        cout << "ID: " << cse[i].id << endl;

        for(int j=0; j<3; ++j)
        {
            cout << "CGPA of Semester " << j+1 <<": " << cse[i].cgpa[j] << endl;
        }
    }
}