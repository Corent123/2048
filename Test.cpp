#include <iostream>
#include <vector>
#include "Modele.h"
using namespace std;

// #define CHECK(test)                \
//     if (!(test))                   \
//     cout << "Test failed in file " \
//          << __FILE__ << " line " << __LINE__ << ": " #test << endl

void CHECK(bool b)
{
    if (b)
    {
        cout << "Test failed in file" << FILE << "line" << __LINE__ << endl;
    }
}

void plateauVide_test()
{
    CHECK(plateauVide().plateau == {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}});
    CHECK(plateauVide().score == 0);
}

void deplacementGauche_test()
{
    Plateau p;
    p.plateau = {{2, 0, 2, 2},
                 {4, 4, 8, 0},
                 {4, 4, 0, 8},
                 {8, 0, 4, 4}};
    CHECK(deplacementGauche(p).plateau == {{4, 2, 0, 0}, {8, 8, 0, 0}, {8, 8, 0, 0}, {8, 8, 0, 0}});
    Plateau t;
    t.plateau = {{128, 256, 256, 2},
                 {0, 0, 0, 2},
                 {0, 0, 4, 4},
                 {0, 2, 2, 4}};
    CHECK(deplacementGauche(t).plateau == {{128, 512, 2, 0}, {2, 0, 0, 0}, {8, 0, 0, 0}, {4, 4, 0, 0}});
}

void deplacementDroite_test()
{
    Plateau p;
    p.plateau = {{2, 2, 0, 2}, {0, 8, 4, 4}, {8, 0, 4, 4}, {4, 4, 0, 8}};
    CHECK(deplacementDroite(p).plateau == {{0, 0, 2, 4}, {0, 0, 8, 8}, {0, 0, 8, 8}, {0, 0, 8, 8}});
    Plateau t;
    t.plateau = {{2, 256, 256, 128}, {2, 0, 0, 0}, {4, 4, 0, 0}, {4, 2, 2, 0}};
    CHECK(deplacementDroite(t).plateau == {{0, 2, 512, 128}, {0, 0, 0, 2}, {0, 0, 0, 8}, {0, 0, 0, 4}});
}

void deplacementHaut_test()
{
    Plateau p;
    p.plateau = {{8, 4, 4, 2}, {0, 4, 4, 0}, {4, 0, 8, 2}, {4, 8, 0, 2}};
    CHECK(deplacementHaut(p).plateau == {{8, 8, 8, 4}, {8, 8, 8, 2}, {0, 0, 0, 0}, {0, 0, 0, 0}});
    Plateau t;
    t.plateau = {{0, 0, 0, 128}, {2, 0, 0, 256}, {2, 4, 0, 256}, {4, 4, 2, 2}};
    CHECK(deplacementHaut(t).plateau == {{4, 8, 2, 128}, {4, 0, 0, 512}, {0, 0, 0, 2}, {0, 0, 0, 0}});
}
void deplacementBas_test()
{
    Plateau p;
    p.plateau = {{4, 8, 0, 2}, {4, 0, 8, 2}, {0, 4, 4, 0}, {8, 4, 4, 2}};
    CHECK(deplacementBas(p).plateau == {{0, 0, 0, 0}, {0, 0, 0, 0}, {8, 8, 8, 2}, {8, 8, 8, 4}});
    Plateau t;
    t.plateau = {{2, 2, 4, 4}, {256, 0, 4, 2}, {256, 0, 0, 2}, {128, 0, 0, 0}};
    CHECK(deplacementBas(t).plateau == {{0, 0, 0, 0}, {2, 0, 0, 0}, {512, 0, 0, 4}, {128, 2, 8, 4}});
}

void deplacement_test()
{
    Plateau p;
    p.plateau = {{2, 4, 8, 0}, {2, 4, 8, 0}, {2, 4, 8, 0}, {2, 4, 8, 0}};
    CHECK(deplacement(p, "q").plateau == {{2, 4, 8, 0}, {2, 4, 8, 0}, {2, 4, 8, 0}, {2, 4, 8, 0}});
}

void dessine_test()
{
    Plateau p;
    p.plateau = {{128, 256, 256, 2}, {0, 0, 0, 2}, {0, 0, 4, 4}, {0, 2, 2, 4}};
    CHECK(dessine(p) == "*************************\n\e[37m*\e[34m 128 \e[37m*\e[32m 256 \e[37m*\e[32m 256 \e[37m*\e[31m  2  \e[37m*\n*************************\e[33m  2  *\ne[35m  4  *\e[35m  4  *\n*     *\e[33m  2  *\e[33m  2  *\e[35m  4  \e[37m*\n**************************\n");
    Plateau t;
    t.plateau = {{128, 512, 2, 0}, {2, 0, 0, 0}, {8, 0, 0, 0}, {4, 4, 0, 0}};
    CHECK(dessine(t) == "*************************\n\e[37m*\e[34m 128 *\e[33m 512 *\e[33m  2  *     *\n*\e[33m  2  *     *     *     *\n*\e[34m  8  *     *     *     *\n*\e[35m  4  *\e[35m  4  *     *     \e[37m*\n**************************\n");
}
void estTermine_test()
{
    Plateau p;
    p.plateau = {{2, 4, 2, 4}, {8, 2, 8, 2}, {2, 4, 2, 4}, {8, 2, 8, 2}};
    CHECK(estTermine(p) == true);
    Plateau t;
    t.plateau = {{2, 0, 0, 0},
                 {2, 0, 0, 0},
                 {2, 0, 0, 0},
                 {2, 0, 0, 0}};
    CHECK(estTermine(t) == false);
}

void estGagnant_test()
{
    Plateau p;
    p.plateau = {{2048, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    CHECK(estGagnant(p) == true);
    Plateau t;
    t.plateau = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2048}};
    CHECK(estGagnant(t) == true);
    Plateau g;
    g.plateau = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    CHECK(estGagnant(g) == false);
}

int main()
{
    plateauVide_test();
    deplacementGauche_test();
    deplacementDroite_test();
    deplacementHaut_test();
    deplacementBas_test();
    deplacement_test();
    dessine_test();
    estTermine_test();
    estGagnant_test();
    return 0;
}