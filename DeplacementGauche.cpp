Plateau deplacementGauche(Plateau plateau)
{
    for (int i = 0; i < plateau.size(); i++)
    {
        bool blocage = false;
        for (int j = 1; j < plateau[i].size(); j++)
        {
            int n = 0;
            while ((n < j) and (plateau[i][j - n - 1] == 0))
            {
                n++;
            }
            plateau[i][j - n] = plateau[i][j];
            plateau[i][j] = 0;
            if ((j - n > 0) and (blocage == false) and (plateau[i][j - n] == plateau[i][j - n - 1]))
            {
                plateau[i][j - 1 - n] = 2 * plateau[i][j - n - 1];
                plateau[i][j - n] = 0;
                blocage = true;
            }
            else if (plateau[i][j - n] != 0)
            {
                blocage = false;
            }
        }
    }
    return plateau;
}