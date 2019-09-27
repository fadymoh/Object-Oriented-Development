#ifndef SORTED_ARRAY_EXCEPTION_H
#define SORTED_ARRAY_EXCEPTION_H
#include <string>
class sorted_array_exception: public std::exception
{
public:
    /** Constructor (C strings).
     *  @param message C-style string error message.
     *                 The string contents are copied upon construction.
     *                 Hence, responsibility for deleting the char* lies
     *                 with the caller. 
     */
    explicit sorted_array_exception(const char* message):
      msg_(message)
      {
      }

    /** Destructor.
     * Virtual to allow for subclassing.
     */
    virtual ~sorted_array_exception() throw (){}

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *          is in posession of the Exception object. Callers must
     *          not attempt to free the memory.
     */
    virtual const char* what() const throw (){
       return msg_.c_str();
    }

protected:
    /** Error message.
     */
    std::string msg_;
};
#endif