// MedicineBatch.cpp
#include "MedicineBatch.h"

// Implement the constructor
MedicineBatch::MedicineBatch(std::string n, std::string id, int q, int m, int y) {
    name = n;
    batchID = id;
    quantity = q;
    expMonth = m;
    expYear = y;
}