/*
*  List.h
*  Header file for CS 223, Lab 4
*  Created by: Barb Wahl, 2-15-16
*  Revised 2-18-18
*  List is a circular, doubly-linked list with sentinel node.
*/

#ifndef List_H_DLL
#define List_H_DLL

#include "DLL_node.h"  // which already includes Person.h

namespace cs223_dll
{

class List
{
 public:
    // ***** Basic Member Functions *****

    // default constructor
    // Postcondition: the list has no items (just a sentinel node)
    List();

    // destructor - test it indirectly by checking for memory leaks
    ~List();

    // is_empty - checks if the list is empty
    // Postcondition: Returns true iff there are no items in the list.
    bool is_empty() const;

    // clear - deletes all items from the list
    // Postcondition: List is empty.
    void clear();

    // front - get the value at the front of the list
    // Precondition: This list is not empty.
    // Postcondition: Return value is a copy of the value stored at
    //    the front of the list.
    DLL_node::value_type front() const;

    // back - get the value at the end of the list
    // Precondition: This list is not empty.
    // Postcondition: Return value is a copy of the value stored at
    //    the back of the list.
    DLL_node::value_type back() const;

    // head_insert - add an item to the front of the list
    // Postcondition: The list has one more node than before, and the
    //    value `val` is stored at the front of the list.
    // EXAMPLE: If the list had items:  <r, o, n, t>, and then the call was
    //    to head_insert('f'), the list now has items: <f, r, o, n, t>
    void head_insert(DLL_node::value_type val);

    // tail_insert - add an item to the end of the list
    // Postcondition: The list has one more node than before, and the
    //    value `val` is stored at the end of the list.
    // EXAMPLE: If the list had items:  <p, i, g>, and then the call was
    //    to tail_insert('g'), the list now has items: <p, i, g, g>
    void tail_insert(DLL_node::value_type val);

    // ***** Other Member Functions *****

    // head_remove - remove an item from the front of the list
    // Postcondition:  Return value is `true` iff an item was removed.
    //    If the list was empty before head_remove(), return value is
    //    `false`.
    // EXAMPLE:  If the list had items <f, r, o, g> before the call to
    //    head_remove(), after the call the list has: <r, o, g>
    bool head_remove();

    // tail_remove - remove an item from the end of the list
    // Postcondition:  Return value is `true` iff an item was removed.
    //    If the list was empty before tail_remove(), return value is
    //    `false`.
    // EXAMPLE:  If the list had items <c, a, t, s> before the call to
    //    tail_remove(), after the call the list has: <c, a, t>
    bool tail_remove();

    // contains - checks for an item in the list
    // Postcondition: Returns true iff there is an item equivalent to
    //    `val` in this list.
    bool contains(DLL_node::value_type val) const;

    // remove_first_of - tries to remove the first instance of an item 
    //    from the list
    // Postcondition: Removes the front-most item in the list that is
    //    equivalent (==) to the given value `val`.  Return value is
    //    true iff an item was removed from the list.
    // NOTE: If no item in the list is equivalent to `val`, the list
    //    is unchanged and `false` is returned.
    // EXAMPLE: The list has items: <2, 9, 2>.  A call to
    //    remove_first_of('2') will return true, and the list items
    //    are now: <9, 2>
    bool remove_first_of(DLL_node::value_type val);

    // ***** Copy Constructor and Assignment Operator *****

    // copy constructor
    // Postcondition: The new list is an independent copy of `other`.
    //    Subsequent changes to one of the lists will *not* affect the
    //    other list.
    List(const List &other);

    // assignment operator
    // Postcondition: This list becomes an identical -- but indepedent --
    //    copy of `other` list.
    // NOTE: Returns the updated list to enable chaining of assignment.
    List& operator=(const List &other);

    // bracket-indexing operator, operator[]
    // Precondition:  i >= 0
    // Precondition:  the list has more than i items
    // Postcondition: returns the ith item in the list, where indexing begins
    //    with 0
    // EXAMPLE: If myList is <D, O, G>, then myList[0] returns 'D',
    //    myList[1] returns 'O', and myList[2] returns 'G'.
    DLL_node::value_type operator[](int i);

    // FRIEND FUNCTIONS
    friend std::ostream& operator <<(std::ostream& out, const List& list);

 private:
    DLL_node * head_ptr;  // pointer to sentinel node
};

// stream output operator - implementation provided
// Postcondition: For lists with length > 0, contents of the list are placed 
//    into the given //    output stream using the following format:
//         "List:\nfirst_item\n...\nlast_item\n"
//    For lists of length = 0, the following will be placed into the
//    given output stream:
//         "Empty List\n"
//    EXAMPLE: If myList is <rain, grass, flowers>, then cout << myList will
//       produce the following in standard out:
//    List:
//     rain
//     grass
//     flowers
std::ostream& operator <<(std::ostream& out, const List& list);

}  // namespace cs223_dll

#endif
