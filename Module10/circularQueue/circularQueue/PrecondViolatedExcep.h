/*
student: Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
date : April 02, 2022
file name : PrecondViolatedExcep.h
description: precondition violated exception header
*/

#pragma once
#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error
{
    public:
       PrecondViolatedExcep(const std::string& message = "");
};

