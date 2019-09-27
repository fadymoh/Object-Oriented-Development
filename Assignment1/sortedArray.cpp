#include "sortedArray.h"


//
// ────────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: D E F A U L T   C O N S T R U C T O R : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────────────
//
sorted_array::sorted_array(int sz) : max_size(sz), ptr_data(new UINT[sz]), sorted_state(false)
{
    puts("inside the default constructor");
    for (int i = 0; i < sz; ++i)
        ptr_data[i] = -1;
}
//
// ──────────────────────────────────────────────────────────────────────── II ──────────
//   :::::: C O P Y   C O N S T R U C T O R : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────
//
sorted_array::sorted_array(sorted_array& other) : max_size(other.max_size), ptr_data(new UINT[other.max_size]), sorted_state(other.sorted_state)
{
    puts("inside the copy constructor");
    for (int i = 0; i < max_size; ++i)
        ptr_data[i] = other.ptr_data[i];
}
//
// ──────────────────────────────────────────────────────────────────────── III ──────────
//   :::::: M O V E   C O N S T R U C T O R : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────
//
sorted_array::sorted_array(sorted_array&& other) : max_size(other.max_size), ptr_data(other.ptr_data), sorted_state(other.sorted_state)
{
    puts("inside the move constructor");
    other.ptr_data = nullptr;
    other.max_size = 0;
}
//
// ──────────────────────────────────────────────────────────── IV ──────────
//   :::::: D E S T R U C T O R : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────
//
sorted_array::~sorted_array()
{
    if (ptr_data != nullptr)
        delete[] ptr_data;
    else
        puts("resource already deleted");
}
//
// ──────────────────────────────────────────────────────────────────────────────────────── V ──────────
//   :::::: C O P Y   A S S I G N M E N T   O P E R A T O R : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────
//
sorted_array& sorted_array::operator=(const sorted_array& other)
{
    puts(" in copy assignment operator");

    if (this != &other)
    {
        delete[] ptr_data;

        max_size = other.max_size;
        sorted_state = other.sorted_state;
        ptr_data = new UINT[max_size];
        for (int i = 0; i < max_size; ++i)
            ptr_data[i] = other.ptr_data[i];
    }
    return *this;
}
//
// ──────────────────────────────────────────────────────────────────────────────────────── VI ──────────
//   :::::: M O V E   A S S I G N M E N T   O P E R A T O R : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────
//
sorted_array& sorted_array::operator=(sorted_array&& other)
{
    puts("in move assignment operator");
    if (this != &other)
    {
        delete[] ptr_data; // free the already allocated memory

        ptr_data = other.ptr_data;
        max_size = other.max_size;
        sorted_state = other.sorted_state;

        other.ptr_data = nullptr;
    }
    return *this;
}
//
// ──────────────────────────────────────────────────────────────────────────────────────────── VII ──────────
//   :::::: F R I E N D   F U N C T I O N   F O R   O U T P U T : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────────
//
std::ostream& operator<<(std::ostream & output, sorted_array& arr)
{
    int sz = arr.max_size;
    if (!arr.sorted_state)
        arr.sort();
    output << "This array has a size of " << sz << '\n' << "( ";
    for (int i = 0; i < sz; ++i)
		output << arr[i] << ","[i == sz - 1] << ' ' << ")"[i != sz - 1];
    return output;
}
//
// ──────────────────────────────────────────────────────────────────────────────────────────────────── VIII ──────────
//   :::::: O V E R L O A D   T H E   E Q U A L I T Y   O P E R A T O R : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────────────────
//
bool sorted_array::operator == (sorted_array& other)
{
    if (!sorted_state) 
        sort();
    if (!other.sorted_state) 
        other.sort();
    if (max_size != other.max_size) 
        return false;
    for (int i = 0; i < max_size; ++i)
        if (ptr_data[i] != other.ptr_data[i]) 
            return false;
    return true;
}
//
// ────────────────────────────────────────────────────────────────────────────────── IX ──────────
//   :::::: O V E R L O A D   T H E   O P E R A T O R : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────────────────
//
bool sorted_array::operator != (sorted_array& other)
{
    return !(*this == other);
}
void sorted_array::swap(UINT* x, UINT* y)
{
    UINT temp = *x;
    *x = *y;
    *y = temp;
}
//
// ────────────────────────────────────────────────────────────────────────────────────── X ──────────
//   :::::: S O R T   T H E   U N S I G N E D   A R R A Y : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────────────────────
//
void sorted_array::sort()
{
    for (int i = 0; i < max_size-1; i++)      
        for (int j = 0; j < max_size -i-1; j++)  
            if (ptr_data[j] > ptr_data[j+1])  
                swap(&ptr_data[j], &ptr_data[j+1]);

    sorted_state = true;
}
//
// ──────────────────────────────────────────────────────────────────────────────────────────────────── XI ──────────
//   :::::: S E T   V A L U E   A T   A   S P E C I F I E D   I N D E X : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────────────────
//
void sorted_array::setat(int index, UINT value)
{
    if (index >= max_size || index < 0)
		throw sorted_array_exception("Index out of int of bound!\n");
    
    ptr_data[index] = value;
    sorted_state = false;
}
//
// ──────────────────────────────────────────────────────────────────────────────────────── XII ──────────
//   :::::: O V E R L O A D   I N D E X   O P E R A T O R S : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────
//
UINT& sorted_array::operator[](int index)
{
    if (index >= max_size || index < 0)
		throw sorted_array_exception("Index out of int of bound!\n");
    return ptr_data[index];
}
//const UINT& sorted_array::operator[](int index) const
//{
//    if (index >= max_size || index < 0)
//        throw "index out of bound";
//    return ptr_data[index];
//}
//
// ──────────────────────────────────────────────────────────────────────────────────────────────── XIII ──────────
//   :::::: G E T   V A L U E   A T   S P E C I F I E D   I N D E X : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────────────
//
UINT sorted_array::getat(int index)
{
    if (index >= max_size || index < 0)
		throw sorted_array_exception("Index out of int of bound!\n");
    return ptr_data[index];
}
//
// ──────────────────────────────────────────────────────────────────────────────────────────────── XIV ──────────
//   :::::: R E T U R N   T H E   S I Z E   O F   T H E   A R R A Y : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────────────────────────
//
int sorted_array::getSize(){
    return max_size;
}
