cmake_minimum_required(VERSION 3.26)
project(VigenereEncryption)

set(CMAKE_CXX_STANDARD 23)

add_executable(VigenereEncryption main.cpp
        src/encrypt.cpp
        inc/encrypt.h
        src/decrypt.cpp
        inc/decrypt.h
        src/breakEncryption.cpp
        inc/breakEncryption.h
        src/utilities.cpp
        inc/utilities.h
        inc/flags.h
        inc/filePathStruct.h
        inc/englishLetterFrequency.h
        inc/constants.h
)
