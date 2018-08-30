#ifndef HASHABLE_TYPE_H
#define HASHABLE_TYPE_H

class HashableType {
public:

    bool operator==(const HashableType &other) {
        return type_ == other.type_;
    }

    bool operator!=(const HashableType &other) {
        return type_ != other.type_;
    }

    static HashableType String() {return HashableType(kString);}
    static HashableType Long() {return HashableType(kLong);}
    static HashableType Double() {return HashableType(kDouble);}

private:
    enum DataType {
        kString,
        kLong,
        kDouble
    };

    HashableType(DataType type):
        type_(type) {}

    DataType type_;
};

#endif // HASHABLE_TYPE_H
