#ifndef DETAIL_H_INCLUDED
#define DETAIL_H_INCLUDED

#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
    Dummy data class used for example of the LinkedList
*/
class Detail
{
    private:
        char code;
        string name;
        string unit;
        double value;

    public:
        char getCode()
        {
            return this->code;
        }

        string getName()
        {
            return this->name;
        }

        string getUnit()
        {
            return this->unit;
        }

        double getValue()
        {
            return this->value;
        }

        Detail* setCode(char code)
        {
            this->code = code;
            return this;
        }

        Detail* setName(string name)
        {
            this->name = name;
            return this;
        }

        Detail* setUnit(string unit)
        {
            this->unit = unit;
            return this;
        }

        Detail* setValue(double value)
        {
            this->value = value;
            return this;
        }

        bool operator==(const Detail that)
        {
            return this->code == that.code &&
                   this->name == that.name &&
                   this->unit == that.unit &&
                   this->value == that.value;
        }

        bool operator!=(const Detail that)
        {
            return !(*this == that);
        }

        friend ostream& operator<< (ostream& output, const Detail& other)
        {
            output << "Code: " << other.code << "; Name: " << other.name << "; " << other.value << " " << other.unit ;
            return output;
        }
};

#endif // DETAIL_H_INCLUDED
