cmake_minimum_required(VERSION 4.1)
project(NewLoan)

set(CMAKE_CXX_STANDARD 20)

add_executable(NewLoan main.cpp
        Loan.cpp
        Loan.h
        Book.cpp
        Book.h
        Magazine.cpp
        Magazine.h
        Members.cpp
        Members.h)
