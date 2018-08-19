#ifndef TINY_SAM_TINYSAMREGRESSIONRESULTS_H
#define TINY_SAM_TINYSAMREGRESSIONRESULTS_H

#include <vector>
#include <string>

class TinySamRegressionResults
{
public:

    std::vector <std::string> header;
    std::vector <std::vector<std::string>> etiquettes;
    std::vector <std::vector<long double>> valeurs;

    void verifieTailles(bool hasHeader, int dimension, int nombreModeles) const;
    void compare(const TinySamRegressionResults &autre) const;

private:
    void verifieTailleHeader(int dimension) const;
};


#endif //TINY_SAM_TINYSAMREGRESSIONRESULTS_H
