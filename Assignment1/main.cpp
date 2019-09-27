#include <iostream>
#include "sortedArray.h"
#include <assert.h>
int main()
{
    try 
    {
        //
        // ─── TRYING CONSTRUCTOR DEFAULT CONSTRUCTORS──────────────────────────────────────────
        //
        sorted_array one(5);
        sorted_array two; // should call the default constructor with size 10
        one.setat(0, 2);
        one.setat(3, 4);
        one.setat(4, 6);

        two.setat(1, 2);
        two.setat(4, 4);
        two.setat(2, 6);

        //
        // ─── TESTS THE SORTING AND EQUALITY/INDEX OVERLOADING ──────────────────
        //
        std::cout << one << '\n';
        std::cout << two << '\n';
        assert(one == two && "failed the assertion. they are not equal");
        two.setat(4, 6);
        assert(one != two && "failed the assertion. they are equal");
        assert(one[0] == two[0] && "failed the assertion. index operator not working");
        one[1] = one[2];
        std::cout << one << '\n';
        //
        // ─── TESTS THE MOVE AND COPY CONSTRUCTORS AND COPY AND MOVE ASSIGNMENT────────────────────────
        //
        sorted_array x = sorted_array(sorted_array(sorted_array(10)));
        sorted_array y = x =  one =  sorted_array(50);
        assert(y.getSize() == 50 && "failed the assertion. assignment not working");

    } catch (sorted_array_exception& ex)
    {
        std::cout << "sorted_array_exception! " << ex.what() << '\n';
    } catch(std::exception& ex)
    {
        std::cout << "exception thrown: " << ex.what() << '\n';
    } catch (...)
    {
        std::cout << "Unhandled exception caught\n";
    }
    return 0;
}