#include "pch.h"
#include "CppUnitTest.h"
#include "..\Vin\Node.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NodeTest
{
	TEST_CLASS(NodeTest)
	{
	public:
		
		TEST_METHOD(Constructor_with_parameters)
		{
			// Arrange
			std::ostringstream temp_arrange;
			temp_arrange << "111";
			std::string expected = temp_arrange.str();

			// Act
			Node node(111);
			std::ostringstream temp_act;
			temp_act << node.get_data();
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}