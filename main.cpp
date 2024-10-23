#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int, int, int);

int main()
{
    cout << endl
         << "\t\tTravel planner for pune Metro" << endl;
    cout << "---------------------------------------------------------------------------" << endl
         << endl;

    string stations[] = {
        "Hill View Park Car Depot", "Vanaz", "Anand Nagar", "Ideal Colony", "Nal Stop", "Garware College",
        "Deccan Gymkhana", "Chhatrapati Sambhaji Udyan", "PMC", "District Court", "Mangalwar Peth",
        "Pune Rly. Station", "Ruby Hall Clinic", "Bund Garden", "Yerawada", "Kalyani Nagar", "Ramwadi",
        "PCMC", "Sant Tukaram Nagar", "Bhosari [Nashik Phata]", "Kasarwadi", "Phugewadi", "Dapodi",
        "Bopodi", "Range Hill Depot", "Shivaji Nagar", "Budhwar Peth", "Mandai",
        "Swargate"};

    int totalLocations = sizeof(stations) / sizeof(stations[0]);

    cout << "Stations:-" << endl;
    for (int i = 0; i < totalLocations; i++)
    {
        cout << i + 1 << ". " << stations[i] << endl;
    }

    int source, destination;
    char dot;

    while (1)
    {

        cout << endl
             << "Give -1 in \"start\" to end the program." << endl;

        cout
            << "Give the stations with serial no. : " << endl;
        cout << "Start: ";
        cin >> source;

        if (source == -1)
            break;

        cin >> dot;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Destination: ";
        cin >> destination >> dot;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (source < 1 || destination > totalLocations)
        {
            cout << "You have given some wrong input" << endl;
            continue;
        }
        else if (source == destination)
        {
            cout << "You are at your destination." << endl;
            continue;
        }
        vector<int> path = solution(source, destination, totalLocations);

        if (path[0] == -1)
        {
            cout << endl
                 << "Not possible to travel through metro" << endl;
            continue;
        }

        cout << endl
             << path[0] << "km by metro" << endl;
        cout << "Path: " << endl;

        if (source == 10)
        {
            if (destination < 18)
                cout << "\t\t---AQUA LINE---" << endl;
            else
                cout << "\t\t---PURPLE LINE---" << endl;
        }
        else if (source < 18)
            cout << "\t\t---AQUA LINE---" << endl;
        else
            cout << "\t\t---PURPLE LINE---" << endl;

        cout << "\t" << stations[source - 1] << endl;

        for (int i = 2; i < path.size() - 1; i++)
        {
            cout << stations[path[i] - 1] << endl;
            if (path[i] == 10)
            {
                if (source < 18 && destination >= 18)
                {
                    cout << "\t\t---PURPLE LINE---" << endl;
                    cout << stations[path[i] - 1] << endl;
                }
                else if (source >= 18 && destination < 18)
                {
                    cout << "\t\t---AQUA LINE---" << endl;
                    cout << stations[path[i] - 1] << endl;
                }
            }
        }

        cout << "\t" << stations[destination - 1] << endl
             << endl;
    }

    cout << endl
         << "Thank you for using our program." << endl
         << endl;
    return 0;
}

vector<int> solution(int source, int destination, int total)
{
    vector<vector<vector<int>>> graph(total + 1);
    graph[1] = {{2, 1}};
    graph[2] = {{1, 1}, {3, 2}};
    graph[3] = {{2, 2}, {4, 1}};
    graph[4] = {{3, 1}, {5, 1}};
    graph[5] = {{4, 1}, {6, 2}};
    graph[6] = {{5, 2}, {7, 1}};
    graph[7] = {{6, 1}, {8, 1}};
    graph[8] = {{7, 1}, {9, 1}};
    graph[9] = {{8, 1}, {10, 1}};
    graph[10] = {{9, 1}, {11, 1}, {26, 1}, {27, 1}};
    graph[11] = {{10, 1}, {12, 1}};
    graph[12] = {{11, 1}, {13, 1}};
    graph[13] = {{12, 1}, {14, 1}};
    graph[14] = {{13, 1}, {15, 2}};
    graph[15] = {{14, 2}, {16, 2}};
    graph[16] = {{15, 2}, {17, 1}};
    graph[17] = {{16, 1}};
    graph[18] = {{19, 2}};
    graph[19] = {{18, 2}, {20, 2}};
    graph[20] = {{19, 2}, {21, 2}};
    graph[21] = {{20, 2}, {22, 1}};
    graph[22] = {{21, 1}, {23, 1}};
    graph[23] = {{22, 1}, {24, 1}};
    graph[24] = {{23, 1}, {25, 1}};
    graph[25] = {{24, 1}, {26, 2}};
    graph[26] = {{10, 2}, {25, 1}};
    graph[27] = {{10, 1}, {28, 1}};
    graph[28] = {{27, 1}, {29, 1}};
    graph[29] = {{28, 1}};

    vector<int> distances(total + 1, INT_MAX);
    queue<pair<int, vector<int>>> q;
    vector<int> ans;

    distances[source] = 0;
    q.push({source, {0, source}});

    while (!q.empty())
    {
        for (vector<int> temp : graph[q.front().first])
        {
            if (q.front().second[0] + temp[1] < distances[temp[0]])
            {
                vector<int> temp_vec;
                temp_vec = q.front().second;
                distances[temp[0]] = temp_vec[0] += temp[1];
                temp_vec.push_back(temp[0]);
                q.push({temp[0], temp_vec});

                if (temp[0] == destination)
                    ans = temp_vec;
            }
        }
        q.pop();
    }

    if (distances[destination] == INT_MAX)
        return {-1};

    return ans;
}