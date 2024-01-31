#include <iostream>
#include <fstream>
#include "nlohmann\json.hpp"

using namespace std;

using json = nlohmann::json;

int deadBoarder()
{
    ifstream inputFile("database.json");
    json data = json::parse(inputFile);
    
    //output "Dead Boarder Started"
    cout << "Dead Boarder Started" << endl;

    // find a way to parse json information

    // keep this here or it breaks.
    return 0;
}