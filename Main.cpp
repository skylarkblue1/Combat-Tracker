#include <iostream>
#include <fstream>
#include "nlohmann\json.hpp"

using namespace std;

using json = nlohmann::json;

int main()
{
    string name;
    int dex;
    int startHP;
    int characterCount;

    std::ifstream inputFile("database.json");
    json data = json::parse(inputFile);

    cout << "How many characters are playing? ";
    cin >> characterCount;

    for (int i = 0; i < characterCount; i++)
    {
        cout << "Enter character name: ";
        cin >> name;
        data["characters"][i]["name"] = name;

        cout << "Enter character Starting HP: ";
        cin >> startHP;
        data["characters"][i]["HP"] = startHP;

        cout << "Enter character DEX stat: ";
        cin >> dex;
        data["characters"][i]["DEX"] = dex;

        // output all those variables
        cout << "Name: " << name << " Starting HP: " << startHP << " DEX: " << dex << "\n" << endl;

        std::ofstream outputFile("database.json");
        // .dump() will dump the json data into the output file.
        outputFile << data.dump();
        
    }

    // keep this here or it breaks.
    return 0;
}