//
// Created by Артем Чумаченко on 05.05.2018.
//

#ifndef VOYAGEUR_FLATSPACE_H
#define VOYAGEUR_FLATSPACE_H

#include <cmath>
#include <vector>
#include <random>
#include <ostream>

class City {
public:
    City() = default;
    City(float x, float y, int n);
    City(const City &city) = default;
    City& operator=(const City & city) = default;
    ~City() = default;

    // distance between cities
    float operator-(City &otherCity) const;
    friend std::ostream& operator<<(std::ostream& os, const City& city);
private:
    float x;
    float y;
    int n;
};

class FlatSpace {
public:
    FlatSpace() = default;
    FlatSpace(const FlatSpace &FS) = default;
    FlatSpace& operator=(const FlatSpace & FS) = default;
    ~FlatSpace() = default;

    City& operator[](int n);
    size_t size() const;
    void clear();
    void add_city(City city);

    friend std::ostream& operator<<(std::ostream& os, const FlatSpace& FS);
private:
    std::vector<City> cities;
};



#endif //VOYAGEUR_FLATSPACE_H
