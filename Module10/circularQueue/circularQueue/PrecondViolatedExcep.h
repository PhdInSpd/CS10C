#ifndef PRECOND_VIOLATED_EXCEP_H
#define PRECOND_VIOLATED_EXCEP_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error
{
    public:
       PrecondViolatedExcep(const std::string& message = "");
};
#endif
