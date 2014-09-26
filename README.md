FeaturesTogglePlusPlus
======================

A small library that implements feature toggles (feature switches).

Development Staus
-----------------
This project is still in heavy development. It can't be used yet.

Project Mission
---------------
The aim of this library is to provide a simple but extensible mechanism for feature toggles in C++.

Design Goals
------------
- Low runtime overhead
- Elminate most (or all) virtual funtions (runtime overhead)
- Use of templates and macros (x-macros)
- Extensible
- User friendly
- ...


To Do's
-------
This following notes are mainly for myself.
- User Config
    + General configs (defines...)
    + Features definitions
    + Feature classes
- Doxygen
    + User doc
    + Developer doc
    + cmake cli param for user/developer doc
- Unit Tests
    + UnitTest++
    + cmake cli param for enabling/disabling
- Logging
    + logging4cxx?
- userconfig.h
    + Names (char[]) for listing all features
    + status text (std::string)
    + status infos (std::stream?)
- Folder Structure
    + src
        + userconfig
            + userconfig.h
            + userfeatures.def
            + userfeaturesclasses.h
        + lib
            + features.def (includes userfeatures.def)
            + featuredefmacros.def (includes features.def)
            + FeaturesTogglePlusPlus.cpp
            + lib.h (lib.cpp?)
            + config.h
        + include
            + FeaturesTogglePlusPlus.h
            + featureclasses.h (userfeaturesclasses.h)
- Run tools
    + gnu size
    + Static analysis (cppcheck, clang static analyzer, ChkSem, oclint)
    + Dynamic analysis (valgrind, xcode instruments)
    + Code metrics (CCCC...)