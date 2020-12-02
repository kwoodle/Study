//
// Created by kwoodle on 11/21/17.
//

#include "Utils.h"
#include "Node.h"

#include <cmath>

constexpr int pow2(int i) {
    return std::pow(2, i);
}

void count_bits(bitset<bpb> bs) {
    auto bint0 = bs.to_ulong();
    auto bint = bint0;
    int cnt{0};
    for (auto i = bpb - 1; i >= 0; --i) {
        if (bint >= pow2(i)) {
            ++cnt;
            bint -= pow2(i);
        }
    }
    std::cout << cnt << " bits in bitset " << bs << " which is long " << bint0 << "\n";
}

int count_bits(int in) {
    static const int byt1{7};
    int cnt = 0;
    for (auto i = byt1; i >= 0; --i) {
        if (in >= pow2(i)) {
            ++cnt;
            in -= pow2(i);
        }
    }
    return cnt;
}

void remdupes_std(std::forward_list<int> &fwdlst) {
    using std::next;
    using std::advance;
    auto end_it = fwdlst.end();
    for (auto hd = fwdlst.begin(); hd != end_it; ++hd) {
        int fnd = *hd;
        auto prev = hd;
        auto q = next(prev);
        while (q != end_it) {
            if (*q == fnd) {
                q = next(q);
                fwdlst.erase_after(prev);
            } else {
                prev = next(prev);
                q = next(q);
            }
        }
    }
}

void test_lists() {

    using std::cout;
    List ll{1, 5, 4, 3, 5, 2, 6, 2, 1, 1};
    std::forward_list<int> fl{1, 5, 4, 3, 5, 2, 6, 2, 1, 1};
    cout << "List = " << ll << "\n";
    rem_dupes(ll);
    remdupes_std(fl);
    cout << "After\n";
    cout << "List = " << ll << "\n";
    cout << "Fwd = ";
    for (auto v : fl) {
        cout << v << ", ";
    }
    cout << "\n";
}


void rem_dupes(List &l) {
    for (Node *hd = l.head; hd != nullptr; hd = hd->next) {
        int fnd = hd->val;
        Node *prev = hd;
        Node *q = prev->next;
        while (q) {
            if (q->val == fnd) {
                prev->next = q->next;
                Node *tmp = q;
                q = q->next;
                delete (tmp);
            } else {
                prev = prev->next;
                q = q->next;
            }
        }
    }
}

void test_count_ones() {
    bitset<bpb> bs{"00011001"};
    count_bits(bs);
    auto in = bs.to_ulong();
    auto bts = count_bits(in);
    std::cout << "bts = " << bts << "\n";
}


// count ones in intin
// start with ones at 8
// Case >= 10000000 >= 2^7 first bit set
// else decrement count
/*
template <int N, int in>
int cnt() {
    if(in < pow2(N)) {
        return (cnt<N-1, in>() - 1);
    } else {
        return cnt<N-1, in-pow2(N)>();
    }
}
*/
