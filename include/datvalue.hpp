#pragma once

class TDatValue;
typedef 

class TDatValue {
    public:
        virtual TDatValue * GetCopy() =0;                           // создание копии
        ~TDatValue() {}
};