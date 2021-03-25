#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include "tag_test.hpp"

using namespace CppUnit;
using namespace std;

void TagTest::setUp(void)
{
}

void TagTest::tearDown(void)
{
}

CPPUNIT_TEST_SUITE_REGISTRATION( TagTest );

int main(int argc, char* argv[])
{
    // return 0 if tests were successful
    return 0;
}