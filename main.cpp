// DNA Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dna.h"
#include <fstream>
#include <vector>

using namespace std;
int main()
{
    while(true)
    {
    cout << "Welcome to the DNA Profiling App!"<<endl;
    string dnafilename = "";
    cout << "Enter database textfile name:";
    cin >> dnafilename;
    
    
    string peoplefilename = "";
    cout << "Enter dna file:";
    cin >> peoplefilename;
    
    
    fstream inFile(dnafilename);
    string dnastr;
    inFile >> dnastr;
    dna *d = new dna(dnastr);
    
    
    bool outerflag = false;
    fstream peopleinFile(peoplefilename);
    string peoplednastr;
    peopleinFile >> peoplednastr;

    std::string s = peoplednastr;
    std::string delimiter = ",";
    vector<string> headerString;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        headerString.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    headerString.push_back(s);

    cout << "Searching Data base...." << endl;
    while (true)
    {
        peopleinFile >> peoplednastr;
        if (peopleinFile.eof()) break;
        std::string s = peoplednastr;
        vector<string> userString;
        pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            userString.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        userString.push_back(s);
        dna* sampledna = new dna(*d);
        bool flag = false;
        for (int i = 1; i < userString.size(); i++)
        {
            int num;
            num = std::stoi(userString[i]);
            string splicetarget = "";
            while (num > 0)
            {
                splicetarget = splicetarget + headerString[i];
                num--;

            }
            dna target(splicetarget);
            //cout << userString[0] << target.toString()<<endl<< sampledna->toString() << endl;
            bool spliceflag = sampledna->splice(target);
            if (!spliceflag)
            {
                flag = false;
                break;
            }
            else
            {
                sampledna = new dna(*d);
                flag = true;
            }
        }

        if (flag)
        {
            outerflag = true;
            cout << "Dna match: " << userString[0] << endl;
            break;
        }
        
     }
    if (outerflag == false)
    {
        cout << "no match" << endl;
    }
    cout << endl;
    cout << "add another:" << endl;
    }
   

    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
