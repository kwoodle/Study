//
// Created by kwoodle on 11/21/17.
//

#ifndef STUDY_UTILS_H
#define STUDY_UTILS_H

#include <iostream>

#include <bitset>
#include <forward_list>
#include "Node.h"


using std::bitset;
static const long bpb{8};


extern void count_bits(std::bitset<bpb> bs);

extern int count_bits(int in);

extern void remdupes_std(std::forward_list<int> &fwdlst);

extern void test_lists();

extern void rem_dupes(List &l);

extern void test_count_ones();


#endif //STUDY_UTILS_H
