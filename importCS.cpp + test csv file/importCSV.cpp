#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;


// Convert to List of Lists.
int main()
{

    // File pointer
    ifstream myFile;

    // Need to input # of rows when declaring vector
    vector<vector<double>> v(39);
    
    myFile.open("AAPL.csv");

    string line, word;
    int k = 0;
    while (myFile.good()) {
        getline(myFile,line);
        stringstream s(line);
        while(getline(s, word,',')){ 
            v[k].push_back(stod(word)); 
        }   
        k++;
    }
    for (int k = 0; k < v.size(); k++) {
        cout << k << ": ";
        for(int i = 0; i < v.at(k).size(); i++) {
            cout << v[k][i] << " ";
        }
        cout <<endl;
    }
    return 0;
}