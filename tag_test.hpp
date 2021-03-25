#ifndef _TAG_TEST_H
#define _TAG_TEST_H

#include <cppunit/Test.h>

class TagTest : public CppUnit::TestFixture
{
private:
    // CPPUNIT_TEST_SUITE(TagTest);
    // CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);    

protected:
         
private:
    int m_argc;
    char* m_argv[10];
    
};

#endif