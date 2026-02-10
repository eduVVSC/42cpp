/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:46:41 by edvieira          #+#    #+#             */
/*   Updated: 2026/02/10 13:03:57 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <algorithm>
#include "MutantStack.hpp"

void printHeader(const std::string &title)
{
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void subjectMain()
{
    printHeader("SUBJECT TEST");
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    
    std::cout << "Stack contents: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::stack<int> s(mstack);
}


void subjectMainWithList()
{
    printHeader("SUBJECT TEST");
    
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << "Top: " << mstack.front() << std::endl;
    mstack.pop_back();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    
    std::cout << "Stack contents: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::list<int> s(mstack);
}

void testBasicOperations()
{
    printHeader("TEST: Basic Stack Operations");
    
    MutantStack<int> mstack;
    
    std::cout << "Empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    
    std::cout << "After pushing 10, 20, 30:" << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "After pop - Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
}

void testIterators()
{
    printHeader("TEST: Iterator Functionality");
    
    MutantStack<int> mstack;
    
    for (int i = 1; i <= 5; i++)
        mstack.push(i * 10);
    
    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Reverse iteration: ";
    MutantStack<int>::iterator it = mstack.end();
    --it;
    while (true)
    {
        std::cout << *it << " ";
        if (it == mstack.begin())
            break;
        --it;
    }
    std::cout << std::endl;
}

void testConstIterators()
{
    printHeader("TEST: Const Iterators");
    
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; i++)
        mstack.push(i);
    
    const MutantStack<int> &const_ref = mstack;
    
    std::cout << "Const iteration: ";
    for (MutantStack<int>::const_iterator it = const_ref.begin(); 
         it != const_ref.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void testCopyConstructor()
{
    printHeader("TEST: Copy Constructor");
    
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);
    
    MutantStack<int> copy(original);
    
    std::cout << "Original: ";
    for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Copy: ";
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    copy.push(999);
    std::cout << "After pushing 999 to copy:" << std::endl;
    std::cout << "Original top: " << original.top() << std::endl;
    std::cout << "Copy top: " << copy.top() << std::endl;
}

void testAssignmentOperator()
{
    printHeader("TEST: Assignment Operator");
    
    MutantStack<int> stack1;
    stack1.push(10);
    stack1.push(20);
    
    MutantStack<int> stack2;
    stack2.push(100);
    stack2.push(200);
    stack2.push(300);
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "Stack1 size: " << stack1.size() << std::endl;
    std::cout << "Stack2 size: " << stack2.size() << std::endl;
    
    stack1 = stack2;
    
    std::cout << "After stack1 = stack2:" << std::endl;
    std::cout << "Stack1 size: " << stack1.size() << std::endl;
    std::cout << "Stack1 top: " << stack1.top() << std::endl;
    
    std::cout << "Stack1 contents: ";
    for (MutantStack<int>::iterator it = stack1.begin(); it != stack1.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void testWithStrings()
{
    printHeader("TEST: MutantStack with Strings");
    
    MutantStack<std::string> mstack;
    
    mstack.push("Hello");
    mstack.push("World");
    mstack.push("42");
    mstack.push("School");
    
    std::cout << "String stack contents: ";
    for (MutantStack<std::string>::iterator it = mstack.begin(); 
         it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Top: " << mstack.top() << std::endl;
}

void testComparisonWithList()
{
    printHeader("TEST: Comparison with std::list");
    
    MutantStack<int> mstack;
    std::list<int> mlist;
    
    for (int i = 1; i <= 5; i++)
    {
        mstack.push(i * 10);
        mlist.push_back(i * 10);
    }
    
    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "std::list:   ";
    for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void testEmptyStack()
{
    printHeader("TEST: Empty Stack");
    
    MutantStack<int> mstack;
    
    std::cout << "Empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << "begin() == end(): " << (it == ite ? "yes" : "no") << std::endl;
}

void testLargeStack()
{
    printHeader("TEST: Large Stack");
    
    MutantStack<int> mstack;
    
    for (int i = 0; i < 100; i++)
        mstack.push(i);
    
    std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    
    int count = 0;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        count++;
    
    std::cout << "Elements counted via iterator: " << count << std::endl;
}

void testIteratorModification()
{
    printHeader("TEST: Modifying via Iterator");
    
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    
    std::cout << "Before modification: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Modify through iterator
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        *it *= 10;
    
    std::cout << "After multiplying by 10: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
    subjectMain();
    subjectMainWithList();
    //testBasicOperations();
    //testIterators();
    //testConstIterators();
    //testCopyConstructor();
    //testAssignmentOperator();
    //testWithStrings();
    //testComparisonWithList();
    //testEmptyStack();
    //testLargeStack();
    //testIteratorModification();
    
    printHeader("ALL TESTS COMPLETED");
    
    return 0;
}