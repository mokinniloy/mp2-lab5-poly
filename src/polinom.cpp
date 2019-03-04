#include <polinom.hpp>
#include <stdexcept>
#include <string>
#include <cmath>
#include <regex>

#define PWR_ERR throw new std::logic_error("Unexpected power.");

#define TEMP_MONOM PTMonom tempMonom = new TMonom(0, -1);

TPolinom::TPolinom(int monoms[][2], int monomCount) : THeadRing()
{
    TEMP_MONOM
    pHead->SetDatValue(tempMonom);

    for (int i = 0; i < monomCount; i++)
    {
        if (monoms[i][1] > 999 || monoms[i][1] < 0) PWR_ERR
        tempMonom = new TMonom(monoms[i][0], monoms[i][1]);
        InsLast(tempMonom);
    }
}

TPolinom::TPolinom(TPolinom &source)
{
    TEMP_MONOM
    pHead->SetDatValue(tempMonom);

    for (source.Reset(); !source.IsListEnded(); source.GoNext())
    {
        PTMonom monom = source.GetMonom();
        InsLast(monom->GetCopy());
    }
}

TPolinom &TPolinom::operator=(TPolinom &source)
{
    DelList();

    for (source.Reset(); !source.IsListEnded(); source.GoNext())
    {
        PTMonom pMonom = source.GetMonom();
        InsLast(pMonom->GetCopy());
    }

    return *this;
}

TPolinom &TPolinom::operator+(TPolinom &source)
{
    PTMonom destMonom, srcMonom, tempMonom;
    Reset();
    source.Reset();

    while (true)
    {
        destMonom = GetMonom();
        srcMonom = source.GetMonom();
        if (destMonom->Index < srcMonom->Index)
        {
            tempMonom = new TMonom(srcMonom->Coeff, srcMonom->Index);
            InsCurrent(tempMonom);
            source.GoNext();
        }
        else if (destMonom->Index > srcMonom->Index)
            GoNext();
        else
        {
            if (destMonom->Index == -1)
                break;
            
            destMonom->Coeff += srcMonom->Coeff;
            if (destMonom->Coeff != 0)
            {
                GoNext();
                source.GoNext();
            }
            else
            {
                DelCurrent();
                source.GoNext();
            }
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, TPolinom &source)
{
    os << "Polinom: ";
    for (source.Reset(); !source.IsListEnded(); source.GoNext())
        os << *source.GetMonom();
    os << std::endl;

    return os;
}

std::istream &operator>>(std::istream &is, TPolinom &source)
{
    int coeff = 0;
    int monomCount = 0;
    int power = 0;

    std::string polinom;
    std::string monom;
    std::string powerStr;

    std::smatch monomMatches;
    std::smatch coefMatches;

    const std::regex yEx("[y]", std::regex_constants::extended);
    const std::regex xEx("[x]", std::regex_constants::extended);
    const std::regex powerEx("[^2-9]", std::regex_constants::extended);
    const std::regex coefEx("[1-9]{1,3}|[2-9]{1}", std::regex_constants::extended);
    const std::regex monomEx("([a-z].[1-9]){1,3}", std::regex_constants::extended); //34x^5y^4z^8+321x^3y^9z^4

    if (source.GetListLength() != 0) source.DelList();
    
    std::cout << "Input polinom: ";
    is >> polinom;

    while(std::regex_search(polinom, monomMatches, monomEx))
    {
        std::regex_search(polinom, coefMatches, coefEx);
        coeff = atoi(coefMatches.str().c_str());

        monom = monomMatches.str().c_str();
        powerStr = std::regex_replace(monom, powerEx, "").c_str();

        if (powerStr.length() == 2 
            && std::regex_search(monom,*(new std::smatch), yEx))
            power = atoi(powerStr.c_str()) * 10;
        else if (powerStr.length() == 2)
            power = atoi(powerStr.c_str()) / 10 * 100 + atoi(powerStr.c_str()) % 10;
        else if (powerStr.length() == 1
                 && std::regex_search(monom,*(new std::smatch), yEx))
            power = atoi(powerStr.c_str()) * 10;
        else if (powerStr.length() == 1
                 && std::regex_search(monom,*(new std::smatch), xEx))
            power = atoi(powerStr.c_str()) * 100;
        else power = atoi(powerStr.c_str());

        PTMonom tempMonom = new TMonom(coeff, power);
        source.InsLast(tempMonom);

        polinom = monomMatches.suffix().str();
        monomCount++;
    }

    if (monomCount == 0)
    {
        std::cout << "Unexpected polinom." << std::endl;
        return is;
    }

    return is;
}