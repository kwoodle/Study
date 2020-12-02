//
// Created by kwoodle on 11/16/17.
//

#ifndef STUDY_RAND_INT_H
#define STUDY_RAND_INT_H

#include <random>
#include <functional>

// From Stroustrup C++11 4th edition Section 40.7
// error: non-static data member declared with placeholder ‘auto’
class Rand_int {
public:
    Rand_int(int lo, int hi) : d{lo, hi} {}

    int operator()() { return d(e); }

private:
    std::uniform_int_distribution<> d;
    std::default_random_engine e;
};

class Randint {
public:
    Randint(int lo, int hi) : p{lo, hi} {}

    int operator()() { return r(); }

private:
    std::uniform_int_distribution<>::param_type p;
//    auto r = std::bind(std::uniform_int_distribution<>{p}, std::default_random_engine{});
    std::function<int()> r = std::bind(std::uniform_int_distribution<>{p}, std::default_random_engine{});
};

class Rand_double {
public:
    Rand_double(double low, double high)
            : r(std::bind(std::uniform_real_distribution<>(low, high), std::default_random_engine())) {}

    double operator()() { return r(); }

private:
    std::function<double()> r;
};

#endif //STUDY_RAND_INT_H
