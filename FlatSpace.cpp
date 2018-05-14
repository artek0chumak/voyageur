//
// Created by Артем Чумаченко on 05.05.2018.
//

#include "FlatSpace.h"

City::City(float x, float y, int n): x(x), y(y), n(n) {
}

float City::operator-(City &otherCity) const {
    return static_cast<float>(std::sqrt(std::pow(x - otherCity.x, 2) + std::pow(y - otherCity.y, 2)));
}

std::ostream& operator<<(std::ostream& os, const City &city) {
    os<<city.n<<":\tx:"<<city.x<<"\ty:"<<city.y;
    return os;
}


City &FlatSpace::operator[](int n) {
    return cities[n];
}

std::ostream &operator<<(std::ostream &os, const FlatSpace &FS) {
    for(auto city: FS.cities) {
        os<<city<<std::endl;
    }
    return os;
}

size_t FlatSpace::size() const {
    return cities.size();
}

void FlatSpace::add_city(City city) {
    cities.emplace_back(city);
}

void FlatSpace::clear() {
    cities.clear();
}

