#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include <stdio.h>
#include <ostream>
#include "sorted_array_exceptio.h"
typedef unsigned int UINT;

class sorted_array
{

    public:
        //default constructor
        sorted_array(int sz = 5);
        //copy constructor
        sorted_array(sorted_array& other);
        //move constructor
        sorted_array(sorted_array&& other);
        ~sorted_array();
        // copy assignment operator
        sorted_array& operator=(const sorted_array& other);
        // move assignment operator
        sorted_array& operator=(sorted_array&& other);
        // index operator
        UINT& operator[](int index);
       // const UINT& operator[] (int index) const;
        // ostream operator as friend
        friend std::ostream& operator << (std::ostream& output, sorted_array& arr);
        // equality operator
        bool operator == (sorted_array& other);
        bool operator != (sorted_array& other);
        // setat
        void setat(int index, UINT value);
        // getat
        UINT getat(int index);
        // get size
        int getSize();
    private:
        int max_size;
        bool sorted_state;
        UINT* ptr_data;
        void sort();
        void swap(UINT* x, UINT* y);
};

#endif