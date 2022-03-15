// BASE CLASS
#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>

#ifndef CVECTOR
#define CVECTOR

class FabricCVector;

class CVector
{
protected:
    
    static size_t count;
    double * ar;
    size_t size;
    
    void copy(const CVector&);
    void clear();
    double * sum(const CVector&);
    double * dif(const CVector&);
    
public:
    CVector();
    CVector(const CVector&);
    CVector(CVector&&);
    
    virtual ~CVector();
    
    CVector& operator=(const CVector&);
    CVector& operator=(CVector&&);
    
    double& operator[](const size_t);
    double operator*(const CVector&);
    
    virtual int output() = 0;
    static CVector** create(const char * FileName, FabricCVector ** f);
    static size_t getCount();
    size_t Size() const;
};

//BASE FABRIC
class FabricCVector
{
public:
    virtual CVector* create(const char *) = 0;
//    virtual ~FabricCVector();
};

#endif


