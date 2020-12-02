//
// Created by kwoodle on 11/12/17.
//

#include <chrono>
#include <list>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "Node.h"
#include "Utils.h"
#include "Rand_int.h"

using std::cout;
using namespace std::chrono;

int fac(int i) {
    return (i < 2) ? 1 : i * fac(i - 1);
}

int main() {
/*
    const int i{4};
    cout<<"fac("<<i<<")="<<fac(i)<<"\n";
*/
    test_count_ones();
    test_lists();
    const long long fill_size = 1e6;
    const int lo{1};
    const int hi{500};
    Randint rnd(lo, hi);
    List l;
    std::forward_list<int> stdlst;
    for (int i = 0; i < fill_size; ++i) {
        int rani{rnd()};
        l.add(rani);
        stdlst.push_front(rani);
    }
    std::forward_list<int> stdlst2 = stdlst;

    cout << "Starting\n" << std::endl;
    auto t = steady_clock::now();
    //
    //
    rem_dupes(l);
    auto d = steady_clock::now() - t;
    cout << "rem_dupes took " << duration_cast<milliseconds>(d).count() << " ms " <<
         "for fill_size " << std::scientific << std::setprecision(0) << double(fill_size) << "\n";

    t = steady_clock::now();
    //
    //
    stdlst.sort();
    stdlst.unique();
    d = steady_clock::now() - t;
    cout << "rem dupes sort/unique took " << duration_cast<milliseconds>(d).count() << " ms " <<
         "for fill_size " << double(fill_size) << "\n";

    t = steady_clock::now();
    //
    //
    remdupes_std(stdlst2);

    d = steady_clock::now() - t;
    cout << "remdupes_std took " << duration_cast<milliseconds>(d).count() << " ms " <<
         "for fill_size " << double(fill_size) << "\n";

/*    Node* h = l.head;
    int n{0};
    for (auto i : stdlst) {
        cout << "my List = "<<h->val<<" stdlist = " << i <<"\n";
        h = h->next;
        if (h == nullptr || n == hi+1)
            break;
        ++n;
    }
*/
    Node *nd = l.head;
    auto sti = stdlst.begin();
    auto st2 = stdlst2.begin();
    while (nd && sti != stdlst2.end()) {
//        cout<<"List = "<< nd->val << ", std = " << *st2 << ".\n";
        if (nd->val != *st2)
            std::cout << nd->val << " != " << *st2 << ".\n";
        nd = nd->next;
        ++sti;
        ++st2;
    }
    return 0;
}




