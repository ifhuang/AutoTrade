#ifndef LEX_GLOBAL_H_
#define LEX_GLOBAL_H_

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);        \
    void operator=(const TypeName&);

#endif  // LEX_GLOBAL_H_
