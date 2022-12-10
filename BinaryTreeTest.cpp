#include "pch.h"
#include "CppUnitTest.h"
#include "..\Vin\BinaryTree.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTest
{
	TEST_CLASS(BinaryTreeTest)
	{
	public:
		
		TEST_METHOD(First_node_insert)
		{
			// Arrange
			std::string expected = "111 ";

			// Act
			BinaryTree tree;
			std::ostringstream temp_act;
			tree.insert(111);
			temp_act << tree << endl;
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(One_more_node_insert)
		{
			// Arrange
			std::string expected = "111 222";

			// Act
			BinaryTree tree;
			std::ostringstream temp_act;
			tree.insert(111);
			tree.insert(222);
			temp_act << tree << endl;
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Node_delete)
		{
			// Arrange
			std::string expected = "222 ";

			// Act
			BinaryTree tree;
			std::ostringstream temp_act;
			tree.insert(111);
			tree.insert(222);
			tree.remove(111);
			temp_act << tree << endl;
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Node_find)
		{
			// Arrange
			std::string expected = "0";

			// Act
			BinaryTree tree;
			std::ostringstream temp_act;
			tree.insert(111);
			tree.insert(222);
			tree.remove(111);
			temp_act << tree.findElement(111) << endl;
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Copy_construcrot)
		{
			// Arrange
			std::string expected = "111 \n111 222 ";

			// Act
			BinaryTree tree1;
			BinaryTree tree2;

			tree1.insert(111);
			tree1.insert(222);

			tree2 = tree1;

			tree1.remove(222);

			ostringstream temp1;
			temp1 << tree1 << endl << tree2;
			string actual = temp1.str();

			// Assert
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(Move_Constructor)
		{
			// Arrange
			string expected = "0000000000000000";

			// Act
			BinaryTree tree1;
			BinaryTree tree2;

			tree2 = move(tree1);

			ostringstream temp1;
			temp1 << tree1.get_root() << endl;
			string actual = temp1.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
