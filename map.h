//
// Created by Macarena Oyague on 2019-10-24.
//

#ifndef PROJECT_MAP_H
#define PROJECT_MAP_H

#include <string>
using namespace std;


class Map {
private:
    string country_or_area;
    int year;
    unsigned long int comm_code;
    string commodity;
    string flow;
    unsigned long int trade_usd;
    unsigned long int weight_kg;
    string quantity_name;
    unsigned long int quantity;
    string category;
public:
    Map(){};
    Map(string country_or_area, int year, unsigned long int comm_code,
        string commodity, string flow, unsigned long int trade_usd,
        unsigned long int weight_kg, string quantity_name,
        unsigned long int quantity, string category)
    {
        this->country_or_area = country_or_area;
        this->year = year;
        this->comm_code = comm_code;
        this->commodity = commodity;
        this->flow = flow;
        this->trade_usd = trade_usd;
        this->weight_kg = weight_kg;
        this->quantity_name = quantity_name;
        this->quantity = quantity;
        this->category = category;
    }

    const string &getCountry_or_area() const {
        return country_or_area;
    }

    int getYear() const {
        return year;
    }

    unsigned long getComm_code() const {
        return comm_code;
    }

    const string &getCommodity() const {
        return commodity;
    }

    const string &getFlow() const {
        return flow;
    }

    unsigned long getTrade_usd() const {
        return trade_usd;
    }

    unsigned long getWeight_kg() const {
        return weight_kg;
    }

    const string &getQuantity_name() const {
        return quantity_name;
    }

    unsigned long getQuantity() const {
        return quantity;
    }

    const string &getCategory() const {
        return category;
    }
};


#endif //PROJECT_MAP_H
