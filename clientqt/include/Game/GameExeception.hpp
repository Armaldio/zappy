//
//-----------------------------------------------------------------------------
//Filename:    GameExeception.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/22/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_GAMEEXECEPTION_HPP
#define CLIENTQT_GAMEEXECEPTION_HPP

#include <exception>
#include <string>

class GameException : public std::exception {
public:
    /** Constructor (C strings).
     *  @param message C-style string error message.
     *                 The string contents are copied upon construction.
     *                 Hence, responsibility for deleting the char* lies
     *                 with the caller.
     */
    explicit GameException(const char* message):
            msg_(message)
    {
    }

    /** Constructor (C++ STL strings).
     *  @param message The error message.
     */
    explicit GameException(const std::string& message):
            msg_(message)
    {}

    /** Destructor.
     * Virtual to allow for subclassing.
     */
    virtual ~GameException()  throw(){}

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

class MapGameException : public GameException {
public:
    MapGameException(const std::string &message) : GameException(message) {}

    explicit MapGameException(const char *message) : GameException(message) {}
};

#endif //CLIENTQT_GAMEEXECEPTION_HPP
