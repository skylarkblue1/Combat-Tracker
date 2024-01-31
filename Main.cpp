#include <iostream>
#include <fstream>
#include "nlohmann\json.hpp"
#include "DeadBoarder.cpp"

using namespace std;

using json = nlohmann::json;

int main()
{
    string keepData;
    bool ifKeepData;

    string scenarioName;
    string name;
    int dex;
    int startHP;
    int characterCount;

    json wipe = {};
     
    ifstream inputFile("database.json");
    json data = json::parse(inputFile);

    cout << "Would you like to keep data? (y/n) ";
    cin >> keepData;
    if (keepData == "y" || keepData == "Y")
        ifKeepData = true;
    else if (keepData == "n" || keepData == "N")
        ifKeepData = false;
    

    if(ifKeepData == false)
    {

        // I'm not actually fully sure if this does anything or not
        ofstream outputFile("database.json");
        data["characters"] = wipe;
        outputFile << wipe.dump();

        cout << "How many characters are playing? ";
        cin >> characterCount;

        for (int i = 0; i < characterCount; i++)
        {
            cout << "Enter character name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(std::cin, name, '\n');
            data["characters"][i]["name"] = name;

            cout << "Enter character Starting HP: ";
            cin >> startHP;
            data["characters"][i]["HP"] = startHP;

            cout << "Enter character DEX stat: ";
            cin >> dex;
            data["characters"][i]["DEX"] = dex;

            // output all those variables
            cout << "Name: " << name << " Starting HP: " << startHP << " DEX: " << dex << "\n" << endl;

            
            ofstream outputFile("database.json");
            // .dump() will dump the json data into the output file.
            outputFile << data.dump();

        }
    }

    
        cout << "Enter Scenario Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(std::cin, scenarioName, '\n');
        data["scenarioName"] = scenarioName;

        string temp = "";
        for(char c: scenarioName)
        if( tolower(c) <= 122 &&  tolower(c) >= 97)
            temp += tolower(c);
        scenarioName = temp;

        // Check to see what scenario is wanted to be ran out of the built-in scenarios
        // Currently the built-in scenarios are: Dead Boarder

        if (scenarioName == "dead boarder" || scenarioName == "db")
            // call the function to run the scenario.
            deadBoarder();
        else
            cout << "Scenario not found, please try again.\n";

    // keep this here or it breaks.
    return 0;
}