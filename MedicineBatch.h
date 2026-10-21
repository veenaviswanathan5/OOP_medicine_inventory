// MedicineBatch.h
#ifndef MEDICINEBATCH_H
#define MEDICINEBATCH_H

#include <string>

class MedicineBatch {
public:
    std::string name;
    std::string batchID;
    int quantity;
    int expMonth;
    int expYear;

    // Just declare the constructor here
    MedicineBatch(std::string n, std::string id, int q, int m, int y);
};

#endif