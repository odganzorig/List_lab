// FILE: List_tests.cpp
// CS 223 Winter 2018, Lab 4
//
// <Name and Date>
//
// List class testing for a circular DLL with sentinel node.
//

#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "Person.h"
#include "DLL_node.h"
#include "List.h"
#include "gtest/gtest.h"  // declares the testing framework

using namespace std;
using namespace cs223_dll;

namespace {

// create some global Person objects to use in tests
Person p1;  // default Person
Person Mickey_Mouse("Mickey", "Mouse", 45);
Person Minnie_Mouse("Minnie", "Mouse", 45);
Person Peter_Pan("Peter", "Pan", 100);
Person Ziggy_Wilson("Ziggy", "Wilson", 5);
Person Skye_Wilson("Skye", "Wilson", 4);
Person Mister_Gray("Mister", "Gray", 10);
Person Dopey_Dwarf("Dopey", "Dwarf", 73);
Person Sleepy_Dwarf("Sleepy", "Dwarf", 73);
Person Happy_Dwarf("Happy", "Dwarf", 73);
Person Snow_White("Snow", "White", 21);

// an array of 10 persons
Person person[] =
    { Mickey_Mouse, Minnie_Mouse, Peter_Pan, Ziggy_Wilson, Skye_Wilson,
      Mister_Gray, Dopey_Dwarf, Sleepy_Dwarf, Happy_Dwarf, Snow_White};

// constructor, is_empty
TEST(TestConstructorANDisEmpty, ListWithJustSentinel_isEmpty)
{
   List L1;
   EXPECT_TRUE(L1.is_empty());
}

// head_insert, front, back
TEST(TestHeadInsert_with_Front_and_Back, Head_Insert_into_Empty_List)
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   ASSERT_FALSE(L1.is_empty());
   EXPECT_EQ(L1.front(), Happy_Dwarf);
   EXPECT_EQ(L1.back(), Happy_Dwarf);
}

TEST(TestHeadInsert_with_Front_and_Back, Head_Insert_into_Length_1_List)
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Minnie_Mouse);
   EXPECT_EQ(L1.front(), Minnie_Mouse);
   EXPECT_EQ(L1.back(), Happy_Dwarf);
}

TEST(TestHeadInsert_with_Front_and_Back, Head_Insert_into_Length_2_List)
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Minnie_Mouse);
   L1.head_insert(Ziggy_Wilson);
   EXPECT_EQ(L1.front(), Ziggy_Wilson);
   EXPECT_EQ(L1.back(), Happy_Dwarf);
}

TEST(TestTailInsert_with_Front_and_Back, Tail_Insert_into_Empty_List)
{
   List L1;
   L1.tail_insert(Happy_Dwarf);
   ASSERT_FALSE(L1.is_empty());
   EXPECT_EQ(L1.front(), Happy_Dwarf);
   EXPECT_EQ(L1.back(), Happy_Dwarf);
}

TEST(TestTailInsert_with_Front_and_Back, Tail_Insert_into_Length_1_List)
{
   List L1;
   L1.tail_insert(Happy_Dwarf);
   L1.tail_insert(Minnie_Mouse);
   EXPECT_EQ(L1.back(), Minnie_Mouse);
   EXPECT_EQ(L1.front(), Happy_Dwarf);
}

TEST(TestTailInsert_with_Front_and_Back, Tail_Insert_into_Length_2_List)
{
   List L1;
   L1.tail_insert(Happy_Dwarf);
   L1.tail_insert(Minnie_Mouse);
   L1.tail_insert(Ziggy_Wilson);
   EXPECT_EQ(L1.back(), Ziggy_Wilson);
   EXPECT_EQ(L1.front(), Happy_Dwarf);
}

// contains
TEST(TestContains, Empty_List_so_Contains_is_False)
{
   List L1;
   EXPECT_FALSE(L1.contains(Happy_Dwarf));
}

TEST(TestContains, Length_1_List_and_Contains_is_True)
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   EXPECT_TRUE(L1.contains(Happy_Dwarf));
}

TEST(TestContains, Length_1_List_and_Contains_is_False)
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   EXPECT_FALSE(L1.contains(Ziggy_Wilson));
}

TEST(TestContains, Length_4_List_and_Contains_is_True_with_Item_at_Tail)
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Snow_White);
   L1.head_insert(Mickey_Mouse);
   L1.tail_insert(Ziggy_Wilson);
   EXPECT_TRUE(L1.contains(Ziggy_Wilson));
}

TEST(TestContains, Length_4_List_and_Contains_returns_False)
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Snow_White);
   L1.head_insert(Mickey_Mouse);
   L1.tail_insert(Ziggy_Wilson);
   EXPECT_FALSE(L1.contains(Skye_Wilson));
}

// head_remove
TEST(TestHeadRemove, Empty_List_so_Head_Remove_returns_False) 
{
   List L1;
   EXPECT_FALSE(L1.head_remove());
}

TEST(TestHeadRemove, Head_Remove_from_Length_1_List_returns_True) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   EXPECT_TRUE(L1.head_remove());
   EXPECT_TRUE(L1.is_empty());
}

TEST(TestHeadRemove, Head_Remove_from_Length_3_List_returns_True) 
{
   List L1;
   L1.head_insert(Mickey_Mouse);
   L1.head_insert(Snow_White);
   L1.head_insert(Happy_Dwarf);
   EXPECT_TRUE(L1.head_remove());
   EXPECT_EQ(L1.front(), Snow_White);
   EXPECT_TRUE(L1.head_remove());
   EXPECT_EQ(L1.front(), Mickey_Mouse);
   EXPECT_TRUE(L1.head_remove());
   EXPECT_TRUE(L1.is_empty());
}

// tail_remove
TEST(TestTailRemove, Empty_List_so_Tail_Remove_returns_False)
{
   List L1;
   EXPECT_FALSE(L1.tail_remove());
}

TEST(TestTailRemove, Tail_Remove_from_Length_1_List_returns_True)
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   EXPECT_TRUE(L1.tail_remove());
   EXPECT_TRUE(L1.is_empty());
}

TEST(TestTailRemove, Tail_Remove_from_Length_3_List_returns_True)
{
   List L1;
   L1.head_insert(Mickey_Mouse);
   L1.head_insert(Snow_White);
   L1.head_insert(Happy_Dwarf);
   EXPECT_TRUE(L1.tail_remove());
   EXPECT_EQ(L1.back(), Snow_White);
   EXPECT_TRUE(L1.tail_remove());
   EXPECT_EQ(L1.back(), Happy_Dwarf);
   EXPECT_TRUE(L1.tail_remove());
   EXPECT_TRUE(L1.is_empty());
}

//****************************************************
// Student To Do: Implement the tests described below.
//****************************************************

// remove_first_of
// TestRemoveFirstOf 
//   - Empty_List_so_RemoveFirstOf_returns_False
//   - Length_1_List_and_RemoveFirstOf_returns_True
//   - Length_1_List_and_RemoveFirstOf_returns_False
//   - Length_4_List_with_All_Items_Diff_and_RemoveFirstOf_returns_True_with_TailItem_Removed
//   - Length_4_List_with_All_Items_Diff_and_RemoveFirstOf_returns_False
//   - Length_4_List_with_Same_2ndAND4th_and_RemoveFirstOf_returns_True_with_2ndItem_Removed

TEST(RemoveFirstOf, Empty_List_so_RemoveFirstOf_returns_False) 
{
   List L1;
   EXPECT_FALSE(L1.remove_first_of(Happy_Dwarf));
}

TEST(RemoveFirstOf, Length_1_List_and_RemoveFirstOf_returns_True) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   EXPECT_TRUE(L1.remove_first_of(Happy_Dwarf));
   EXPECT_TRUE(L1.is_empty());
}

TEST(RemoveFirstOf, Length_1_List_and_RemoveFirstOf_returns_False) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   EXPECT_FALSE(L1.remove_first_of(Snow_White));
   EXPECT_FALSE(L1.is_empty());
}

TEST(RemoveFirstOf, Length_4_List_with_All_Items_Diff_and_RemoveFirstOf_returns_True_with_TailItem_Removed) 
{
   List L1;
   L1.head_insert(Mickey_Mouse);
   L1.head_insert(Snow_White);
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Ziggy_Wilson);
   EXPECT_TRUE(L1.remove_first_of(Mickey_Mouse));
   EXPECT_EQ(L1.back(), Snow_White);
   EXPECT_TRUE(L1.remove_first_of(Snow_White));
   EXPECT_EQ(L1.back(), Happy_Dwarf);
   EXPECT_TRUE(L1.remove_first_of(Happy_Dwarf));
   EXPECT_EQ(L1.back(), Ziggy_Wilson);
   EXPECT_TRUE(L1.remove_first_of(Ziggy_Wilson));
   EXPECT_TRUE(L1.is_empty());
}

TEST(RemoveFirstOf, Length_4_List_with_All_Items_Diff_and_RemoveFirstOf_returns_False) 
{
   List L1;
   L1.head_insert(Mickey_Mouse);
   L1.head_insert(Snow_White);
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Ziggy_Wilson);
   EXPECT_FALSE(L1.remove_first_of(Minnie_Mouse));
   EXPECT_EQ(L1.back(), Mickey_Mouse);
}

TEST(RemoveFirstOf, Length_4_List_with_Same_2ndAND4th_and_RemoveFirstOf_returns_True_with_2ndItem_Removed) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Snow_White);
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Ziggy_Wilson);
   EXPECT_TRUE(L1.remove_first_of(Happy_Dwarf));
   EXPECT_EQ(L1.back(), Happy_Dwarf);
}


// clear
// TestClear
//   - Clear_Empty_List
//   - Clear_Length_1_List
//   - Clear_Length_3_List

TEST(Clear, Clear_Empty_List) 
{
   List L1;
   L1.clear();
   EXPECT_TRUE(L1.is_empty());
}

TEST(Clear, Clear_Length_1_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.clear();
   EXPECT_TRUE(L1.is_empty());
}

TEST(Clear, Clear_Length_3_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Snow_White);
   L1.head_insert(Happy_Dwarf);
   L1.clear();
   EXPECT_TRUE(L1.is_empty());
}

// copy constructor
// TestCopyConstructor
//   - Copy_Empty_List
//   - Copy_Length_1_List
//   - Copy_Length_3_List
//   - Copy_is_Independent_of_Other_List

TEST(CopyConstructor, Copy_Empty_List) 
{
   List L1;
   List L2(L1);
}

TEST(CopyConstructor, Copy_Length_1_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   List L2(L1);
   EXPECT_EQ(L1.front(), L2.front());
}

TEST(CopyConstructor, Copy_Length_3_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Mickey_Mouse);
   L1.head_insert(Snow_White);
   List L2(L1);
   EXPECT_EQ(L1.front(), L2.front());
   EXPECT_EQ(L1.back(), L2.back());
}

TEST(CopyConstructor, Copy_is_Independent_of_Other_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Mickey_Mouse);
   List L3(L1);
   L1.head_remove();
   EXPECT_EQ(L3.front(),Mickey_Mouse);
}

// assignment operator
// TestAssignmentOperator
//   - SelfAssignment
//   - Assign_Length_3_List_to_Different_Length_3_List
//   - Assign_Longer_List_to_Shorter_List
//   - Assign_Shorter_List_to_Longer_List
//   - Assignment_Chaining
//   - This_List_is_Independent_of_Other_List

TEST(AssignmentOperator, SelfAssignment) 
{
   List L1;
   L1 = L1;
   EXPECT_EQ(L1.front(), L1.front());
}

TEST(AssignmentOperator, Assign_Length_3_List_to_Different_Length_3_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Mickey_Mouse);
   L1.head_insert(Snow_White);
   List L2;
   L2.head_insert(Ziggy_Wilson);
   L2.head_insert(Minnie_Mouse);
   L2.head_insert(Peter_Pan);
   L2 = L1;
   EXPECT_EQ(L2[0], L1[0]);
   EXPECT_EQ(L2[1], L1[1]);
   EXPECT_EQ(L2[2], L1[2]);
}

TEST(AssignmentOperator, Assign_Longer_List_to_Shorter_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Mickey_Mouse);
   L1.head_insert(Snow_White);
   List L2;
   L2.head_insert(Ziggy_Wilson);
   L2.head_insert(Minnie_Mouse);
   L2 = L1;
   EXPECT_EQ(L2[0], L1[0]);
   EXPECT_EQ(L2[1], L1[1]);
   EXPECT_EQ(L2[2], L1[2]);
}


TEST(AssignmentOperator, Assign_Shorter_List_to_Longer_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Mickey_Mouse);
   List L2;
   L2.head_insert(Ziggy_Wilson);
   L2.head_insert(Minnie_Mouse);
   L2.head_insert(Snow_White);
   L2 = L1;
   EXPECT_EQ(L2[0], L1[0]);
   EXPECT_EQ(L2[1], L1[1]);
   EXPECT_FALSE(L2[2] == Ziggy_Wilson);
}

TEST(AssignmentOperator, Assignment_Chaining) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Mickey_Mouse);
   List L2;
   L2.head_insert(Ziggy_Wilson);
   L2.head_insert(Minnie_Mouse);
   List L3;
   L3.head_insert(Snow_White);
   L3.head_insert(Peter_Pan);
   L3 = L2 = L1;
   EXPECT_EQ(L3[0], L2[0]);
   EXPECT_EQ(L2[0], L1[0]);
   EXPECT_EQ(L3[1], L2[1]);
   EXPECT_EQ(L2[1], L1[1]);
}

TEST(AssignmentOperator, This_List_is_Independent_of_Other_List) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Mickey_Mouse);
   List L2;
   L2 = L1;
   L1.head_remove();
   EXPECT_EQ(L2.front(),Mickey_Mouse);
}



// bracket-indexing operator []
// TestBracketIndexing
//   - Length_1_List_Index_0
//   - Length_3_List_Index_0
//   - Length_3_List_Index_1
//   - Length_3_List_Index_2

TEST(BracketIndexing, Length_1_List_Index_0) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   EXPECT_EQ(L1[0], Happy_Dwarf);
}

TEST(BracketIndexing, Length_3_List_Index_0) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Ziggy_Wilson);
   L1.head_insert(Minnie_Mouse);
   EXPECT_EQ(L1[0], Minnie_Mouse);
}

TEST(BracketIndexing, Length_3_List_Index_1) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Ziggy_Wilson);
   L1.head_insert(Minnie_Mouse);
   EXPECT_EQ(L1[1], Ziggy_Wilson);
}

TEST(BracketIndexing, Length_3_List_Index_2) 
{
   List L1;
   L1.head_insert(Happy_Dwarf);
   L1.head_insert(Ziggy_Wilson);
   L1.head_insert(Minnie_Mouse);
   EXPECT_EQ(L1[2], Happy_Dwarf);
}



// stream output operator
TEST(TestStreamOutput, Empty_List)
{
   stringstream out;
   List L1;
   out << L1;
   EXPECT_EQ(out.str(), "Empty List\n");
}

TEST(TestStreamOutput, Length_1_list)
{
   stringstream out;
   List L1;
   L1.head_insert(Skye_Wilson);
   out << L1;
   EXPECT_EQ(out.str(), "List:\nPerson: Skye Wilson, age 4\n");
}

TEST(TestStreamOutput, Length_3_list)
{
   stringstream out;
   List L1;
   L1.head_insert(Ziggy_Wilson);
   L1.head_insert(Skye_Wilson);
   L1.head_insert(Mister_Gray);
   string correct = "List:\n";
   correct += "Person: Mister Gray, age 10\n";
   correct += "Person: Skye Wilson, age 4\n";
   correct += "Person: Ziggy Wilson, age 5\n";
   out << L1;
   EXPECT_EQ(out.str(), correct);
}

} // namespace

// main() for testing -- boilerplate
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
