#include "TinySamRegressionResults.h"
#include "catch.hpp"
//    std::vector <std::string> header = {"Marker", "Env_1", "Loglikelihood", "Gscore", "WaldScore", "NumError",
// "Efron", "McFadden", "McFaddenAdj", "CoxSnell", "Nagelkerke", "AIC", "BIC",
// "Beta_0", "Beta_1"};
// 0 : h=5, e=1, v=4
// 1: h=15, e=2, v=13
//2: h=17, e=3, v=14

void TinySamRegressionResults::verifieTailles(bool hasHeader, int dimension, int nombreModeles) const {
    if (hasHeader)
    {
        verifieTailleHeader(dimension);
    }

    REQUIRE(etiquettes.size() == nombreModeles);
    REQUIRE(valeurs.size() == nombreModeles);

    int tailleEtiquettes = dimension + 1;
    int tailleValeurs = 4;

    if (dimension > 0)
    {
        tailleValeurs = dimension + 12;
    }

    for (int i(0); i < nombreModeles; ++i)
    {
        CHECK(etiquettes[i].size() == tailleEtiquettes);
        CHECK(valeurs[i].size() == tailleValeurs);
    }
}

void TinySamRegressionResults::verifieTailleHeader(int dimension) const {
    if (dimension == 0)
    {
        CHECK(header.size() == 5);
    }
    else
    {
        CHECK(header.size() == (2 * dimension + 13));
    }
}

void TinySamRegressionResults::compare(const TinySamRegressionResults &autre) const {

}
