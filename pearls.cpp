//
// Created by kim on 11/26/17.
//

#include <iostream>
#include <vector>
#include <chrono>
#include "Rand_int.h"

using std::vector;
using std::cout;
using namespace std::chrono;

void rotate_left(vector<int> &, int);

int main() {
//    decltype(auto) a = std::experimental::make_array(1,3,4,1);
    const long long fill_size = 1e8;
    const int lo{1};
    const int hi{50};
    Randint rnd(lo, hi);
//    vector<int> testv{0,1,0,5,6,8,3};
//    for (auto e : testv ) {
//        std::cout << e << ", ";
//    }
//    std::cout << "\n";
    vector<int> testv;
    for (int i = 0; i < fill_size; ++i) {
        auto ir = rnd();
        testv.push_back(ir);
    }
    for (int i = 0; i < testv.size() && i < 300; ++i) {
        cout << testv[i] << ", ";
        if ((i % 30) == 29)
            std::cout << "\n";
    }
    int rot{30};
    cout << "Starting\n" << std::endl;
    auto t = steady_clock::now();
    //
    //
    rotate_left(testv, rot);
    auto d = steady_clock::now() - t;
    cout << "rotate_left took " << duration_cast<milliseconds>(d).count() <<
         " ms for size " << fill_size << "\n";

    for (int i = 0; i < testv.size() && i < 300; ++i) {
        cout << testv[i] << ", ";
        if ((i % 30) == 29)
            std::cout << "\n";
    }
//    for (auto e : testv ) {
//       std::cout << e << ", ";
//   }
    std::cout << "\n";
    // release with debug info
    // 1337, 1448, 1307 ms for size=1e8 and move on laptop
    // 1380, 1380 ms for size=1e8 and copy on laptop
    // 777, 775, 773 ms   for size=1e8 and copy on desktop
    // release
    // 772, 771, 768 ms     "
    return 0;
}

void rotate_left(vector<int> &vin, const int irot) {
    auto sz = vin.size();
    vector<int> tmp(sz);
//    std::cout << "size of tmp = "<<tmp.size()<<"\n";
    if (irot >= sz) {
        exit(1);
    }
    for (int i = 0; i < sz; ++i) {
//        std::cout<<"tmp["<<i<<"] = vin["<<(i+irot)%sz<<"]\n";
        tmp[i] = vin[(i + irot) % sz];
//        std::cout<<"i = "<<i<<" i%10 = "<<(i%10)<<"\n";
    }
//    vin = std::move(tmp);
    vin = tmp;
}
