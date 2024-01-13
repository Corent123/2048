#include <vector>
#include <iostream>
#include <random>
using namespace std;

typedef vector<vector<int>> Plateau;

Plateau plateauVide()
{
    Plateau plateau(4);
    // plateau = Plateau(4);
    for (int i = 0; i < plateau.size(); i++)
    {
        // vector<int>
        vector<int> ligne(4);
        ligne = {0, 0, 0, 0};
        plateau[i] = ligne;
    }
    return plateau;
}

int main()
{
    Plateau plateau;
    plateau = plateauVide();
    for (int i = 0; i < plateau.size(); i++)
    {
        cout << "i=" << i << endl;
        cout << plateau[i].size() << endl;
        // for (int j = 0; j < plateau[i].size(); j++)
        // {
        // cout << "j=" << j << endl
        //  << plateau[i][j];
        // }
    }
}