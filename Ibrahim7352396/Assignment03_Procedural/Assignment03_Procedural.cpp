#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void print(std::vector<std::vector<char>>& passenger)
{

    for (int row = 0; row < passenger.size(); row++)
    {
        for (int col = 0; col < passenger[row].size(); col++)
        {
            std::cout << passenger[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void stopA(std::vector<std::vector<char>>& passenger, std::vector<std::vector<char>>& Stops, std::fstream& stops)
{
    std::string line = "";
    int mCount = 0;
    int lCount = 0;
    int cCount = 0;

    std::getline(stops, line);

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == 'L')
        {
            lCount++;
        }
        else if (line[i] == 'C')
        {
            cCount++;
        }
        else if (line[i] == 'M')
        {
            mCount++;
        }
    }

    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < passenger[row].size(); col++)
        {
            if (lCount > 0 && passenger[row][col] == 'E')
            {
                passenger[row][col] = 'L';
                Stops[row][col] = 'A';
                lCount--;

            }
            else if (cCount > 0 && passenger[row][col] == 'E')
            {
                passenger[row][col] = 'C';
                Stops[row][col] = 'A';
                cCount--;
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::fstream stops;
    stops.open("StopsOn.txt", std::ios::in | std::ios::out);

    std::vector<std::vector<char>> passenger
    {
        {' ','A','B','C','D'},
        {' ',' ',' ','D','R'},
        {'1','E','E','E','E'},
        {'2','E','E','E','E'},
        {'3','E','E','E','E'},
        {'4','E','E','E','E'},
        {' ',' ',' ','D','R'},
        {'5','E','E','E','E'},
        {'6','E','E','E','E'},
        {'7','E','E','E','E'},
        {'8','E','E','E','E'},
        {' ',' ',' ','D','R'}
    };

    std::vector<std::vector<char>> Stops
    {
        {' ','A','B','C','D'},
        {' ',' ',' ','D','R'},
        {'1','E','E','E','E'},
        {'2','E','E','E','E'},
        {'3','E','E','E','E'},
        {'4','E','E','E','E'},
        {' ',' ',' ','D','R'},
        {'5','E','E','E','E'},
        {'6','E','E','E','E'},
        {'7','E','E','E','E'},
        {'8','E','E','E','E'},
        {' ',' ',' ','D','R'}
    };

    stopA(passenger,Stops,stops);
    print(passenger);
    std::cout << std::endl;
    print(Stops);

    stops.close();
}


