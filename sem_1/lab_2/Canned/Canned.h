#ifndef CANNED_H
#define CANNED_H
#include "../Grocery/Grocery.h"

class Canned : public Grocery {
public:
    Canned(const std::string& name, float price, int quantity, const std::string& expiration_date,
       const std::string& preservation_type, bool is_recyclable);

    void setPreservationType(const std::string& type);
    std::string getPreservationType() const;

    void setRecyclable(bool recyclable);
    bool isRecyclable() const;

    void displayCannedInfo() const;

private:
    std::string preservation_type_;
    bool is_recyclable_;
};

#endif //CANNED_H
