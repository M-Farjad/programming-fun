#pragma once
#ifndef AUXIL_H
#define AUXIL_H

class Budget; // Forward declaration of Budget class

// Aux class declaration
class AuxiliaryOffice
{
private:
    double auxBudget;

public:
    AuxiliaryOffice()
    {
        auxBudget = 0;
    }

    double getDivisionBudget() const
    {
        return auxBudget;
    }

    void addBudget(double, Budget&);
};

void AuxiliaryOffice::addBudget(double b, Budget& div)
{
    auxBudget += b;
    div.corpBudget += b;
}

#endif