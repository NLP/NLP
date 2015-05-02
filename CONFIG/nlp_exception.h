/**
 * nlp_exception.h
 * Copyright (C) 2015 Tony Lim <atomictheorist@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef NLP_EXCEPTION_H
#define NLP_EXCEPTION_H
#include <exception>

using namespace std;

namespace NLP
{
    class unimplemented_exc: public exception
    {
        virtual const char* what() const throw()
        {
            return "Unimplemented error.";
        }
    };
} /* NLP */


#endif /* !NLP_EXCEPTION_H */
