// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;

TEST(test_list_default_ctor) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
    ASSERT_FALSE(empty_list.size() == 1);
}

TEST(test_empty) {
    List<int> my_list;
    ASSERT_TRUE(my_list.empty());

    my_list.push_front(42);
    my_list.push_back(42);
    my_list.pop_front();

    ASSERT_FALSE(my_list.empty());

    my_list.pop_back();

    ASSERT_TRUE(my_list.empty());
}

TEST(test_size) {
    List<int> my_list;
    ASSERT_TRUE(my_list.size() == 0);

    my_list.push_front(42);
    my_list.push_back(42);

    ASSERT_TRUE(my_list.size() == 2);

    my_list.push_front(12);
    my_list.push_front(13);

    ASSERT_TRUE(my_list.size() == 4);

    my_list.pop_back();
    my_list.pop_back();
    my_list.pop_back();


    ASSERT_TRUE(my_list.size() == 1);
}

TEST(test_front) {
    List<int> my_list;
    my_list.push_front(42);
    my_list.push_back(43);

    ASSERT_TRUE(my_list.front() == 42);

    my_list.front() = 32;
    my_list.back() = 33;

    ASSERT_TRUE(my_list.front() == 32);

    //one element
    List<int> my_list2;
    my_list2.push_back(86);

    ASSERT_TRUE(my_list2.front() == 86);

    my_list2.front() = 68;

    ASSERT_TRUE(my_list2.front() == 68);

    my_list2.back() = 90;

    ASSERT_TRUE(my_list2.front() == 90);
}

TEST(test_back) {
    List<int> my_list;
    my_list.push_front(42);
    my_list.push_back(43);

    ASSERT_TRUE(my_list.back() == 43);

    my_list.front() = 32;
    my_list.back() = 33;

    ASSERT_TRUE(my_list.back() == 33);

    //one element
    List<int> my_list2;
    my_list2.push_back(86);

    ASSERT_TRUE(my_list2.back() == 86);

    my_list2.back() = 68;

    ASSERT_TRUE(my_list2.back() == 68);

    my_list2.front() = 90;

    ASSERT_TRUE(my_list2.back() == 90);
}

TEST(test_push_front) {
    List<int> my_list;
    my_list.push_front(42);
    my_list.push_front(43);
    my_list.push_front(44);

    List<int>::Iterator iter = my_list.begin();
    List<int>::Iterator iter2 = my_list.begin();
    ++iter2;
    ++iter2;

    ASSERT_TRUE(*iter == 44);
    ++iter;
    ASSERT_TRUE(*iter == 43);
    ++iter;
    ASSERT_TRUE(*iter == 42);

    ASSERT_TRUE(*iter2 == 42);
    --iter2;
    ASSERT_TRUE(*iter2 == 43);
    --iter2;
    ASSERT_TRUE(*iter2 == 44);
}

TEST(test_push_back) {
    List<int> my_list;
    my_list.push_back(42);
    my_list.push_back(43);
    my_list.push_back(44);

    List<int>::Iterator iter = my_list.begin();
    List<int>::Iterator iter2 = my_list.begin();
    ++iter2;
    ++iter2;

    ASSERT_TRUE(*iter == 42);
    ++iter;
    ASSERT_TRUE(*iter == 43);
    ++iter;
    ASSERT_TRUE(*iter == 44);

    ASSERT_TRUE(*iter2 == 44);
    --iter2;
    ASSERT_TRUE(*iter2 == 43);
    --iter2;
    ASSERT_TRUE(*iter2 == 42);
}

TEST(test_pop_front) {
    List<int>::Iterator default_iter;    
    
    List<int> my_list;
    my_list.push_front(42);
    my_list.push_front(43);
    my_list.push_front(44);
    ASSERT_TRUE(my_list.size() == 3);

    my_list.pop_front();
    ASSERT_TRUE(my_list.size() == 2);
    List<int>::Iterator iter = my_list.begin();
    List<int>::Iterator iter2 = my_list.end();

    ASSERT_TRUE(*iter == 43);
    ASSERT_TRUE(iter2 == default_iter)

    my_list.pop_front();

    iter = my_list.begin();
    iter2 = my_list.end();

    ASSERT_TRUE(*iter == 42);
    ASSERT_TRUE(iter2 == default_iter);

    List<int> my_list2;
    my_list2.push_front(9);
    my_list2.push_front(6);
    my_list2.push_front(3);
    my_list2.push_front(1);
    my_list2.push_front(4);
    ASSERT_TRUE(my_list2.size() == 5);

    my_list2.pop_front();
    ASSERT_TRUE(my_list2.size() == 4);
    List<int>::Iterator iter3 = my_list2.begin();
    List<int>::Iterator iter4 = my_list2.begin();
    ++iter4;
    ++iter4;
    ++iter4;

    ASSERT_TRUE(*iter3 == 1);
    ASSERT_TRUE(*iter4 == 9);
    ++iter3;
    --iter4;
    ASSERT_TRUE(*iter3 == 3);
    ASSERT_TRUE(*iter4 == 6);
    ++iter3;
    --iter4;
    ASSERT_TRUE(*iter3 == 6);
    ASSERT_TRUE(*iter4 == 3);
    ++iter3;
    --iter4;
    ASSERT_TRUE(*iter3 == 9);
    ASSERT_TRUE(*iter4 == 1);
}

TEST(test_pop_back) {
    List<int>::Iterator default_iter;

    List<int> my_list;
    my_list.push_back(42);
    my_list.push_back(43);
    my_list.push_back(44);

    my_list.pop_back();
    List<int>::Iterator iter = my_list.begin();
    List<int>::Iterator iter2 = my_list.end();

    ASSERT_TRUE(*iter == 42);
    ASSERT_TRUE(iter2 == default_iter);
    my_list.pop_back();

    iter = my_list.begin();
    iter2 = my_list.end();

    ASSERT_TRUE(*iter == 42);
    ASSERT_TRUE(iter2 == default_iter);

    List<int> my_list2;
    my_list2.push_back(9);
    my_list2.push_back(6);
    my_list2.push_back(3);
    my_list2.push_back(1);
    my_list2.push_back(4);
    ASSERT_TRUE(my_list2.size() == 5);

    my_list2.pop_back();
    ASSERT_TRUE(my_list2.size() == 4);
    List<int>::Iterator iter3 = my_list2.begin();
    List<int>::Iterator iter4 = my_list2.begin();
    ++iter4;
    ++iter4;
    ++iter4;

    ASSERT_TRUE(*iter3 == 9);
    ASSERT_TRUE(*iter4 == 1);
    ++iter3;
    --iter4;
    ASSERT_TRUE(*iter3 == 6);
    ASSERT_TRUE(*iter4 == 3);
    ++iter3;
    --iter4;
    ASSERT_TRUE(*iter3 == 3);
    ASSERT_TRUE(*iter4 == 6);
    ++iter3;
    --iter4;
    ASSERT_TRUE(*iter3 == 1);
    ASSERT_TRUE(*iter4 == 9);
}

TEST(test_clear) {
    List<int> my_list;

    //zero elements
    my_list.clear();
    ASSERT_TRUE(my_list.empty());
    ASSERT_TRUE(my_list.size() == 0);

    //1 element
    my_list.push_back(42);
    my_list.clear();
    ASSERT_TRUE(my_list.empty());
    ASSERT_TRUE(my_list.size() == 0);

    //2 elements
    my_list.push_back(42);
    my_list.push_back(43);
    my_list.clear();
    ASSERT_TRUE(my_list.empty());
    ASSERT_TRUE(my_list.size() == 0);

    //3 elements
    my_list.push_back(42);
    my_list.push_back(43);
    my_list.push_back(44);
    my_list.clear();
    ASSERT_TRUE(my_list.empty());
    ASSERT_TRUE(my_list.size() == 0);
}

TEST(test_list_other_ctor) {
    List<int> my_list;
    my_list.push_back(42);
    my_list.push_back(43);
    my_list.push_back(44);

    List<int> *my_list2 = new List<int>(my_list);
    List<int>::Iterator iter = my_list.begin();
    List<int>::Iterator iter2 = my_list2->begin();

    ASSERT_TRUE(*iter == *iter2);
    ++iter;
    ++iter2;
    ASSERT_TRUE(*iter == *iter2);
    ++iter;
    ++iter2;
    ASSERT_TRUE(*iter == *iter2);

    delete my_list2;

    List<int>::Iterator default_iter;
    List<int> my_list3;
    List<int> *my_list4 = new List<int>(my_list3);
    List<int>::Iterator iter3 = my_list3.begin();
    List<int>::Iterator iter4 = my_list4->begin();

    ASSERT_TRUE(iter3 == iter4);
    ASSERT_TRUE(iter3 == default_iter);

    delete my_list4;
}

TEST(test_list_assignment_operator) {
    //lhs already equals rhs, both are empty
    List<int> my_list;
    List<int> my_list2;

    my_list = my_list2;

    ASSERT_TRUE(my_list.empty());
    ASSERT_TRUE(my_list2.empty());

    //lhs already equals rhs, not empty
    my_list.push_back(39);
    my_list.push_front(66);
    my_list.push_front(65);
    my_list2.push_back(39);
    my_list2.push_front(66);
    my_list2.push_front(65);

    my_list = my_list2;

    List<int>::Iterator iter = my_list.begin();
    ASSERT_TRUE(*iter == 65);
    ++iter;
    ASSERT_TRUE(*iter == 66);
    ++iter;
    ASSERT_TRUE(*iter == 39);
    --iter;
    ASSERT_TRUE(*iter == 66);
    --iter;
    ASSERT_TRUE(*iter == 65);


    //lhs empty, rhs not
    List<int> my_list3;
    List<int> my_list4;
    my_list4.push_back(39);
    my_list4.push_front(66);
    my_list4.push_front(65);

    my_list3 = my_list4;
    List<int>::Iterator iter2 = my_list3.begin();
    ASSERT_TRUE(*iter2 == 65);
    ++iter2;
    ASSERT_TRUE(*iter2 == 66);
    ++iter2;
    ASSERT_TRUE(*iter2 == 39);
    --iter2;
    ASSERT_TRUE(*iter2 == 66);
    --iter2;
    ASSERT_TRUE(*iter2 == 65);

    //rhs empty, lhs not
    List<int> my_list5;
    List<int> my_list6;
    my_list5.push_back(39);
    my_list5.push_front(66);
    my_list5.push_front(65);

    my_list5 = my_list6;
    ASSERT_TRUE(my_list5.empty());

    //reg
    List<int> my_list7;
    my_list7.push_back(39);
    my_list7.push_front(66);
    my_list7.push_front(65);

    List<int> my_list8;
    my_list8.push_back(18);
    my_list8.push_front(23);

    my_list8 = my_list7;
    List<int>::Iterator iter3 = my_list8.begin();
    ASSERT_TRUE(*iter3 == 65);
    ++iter3;
    ASSERT_TRUE(*iter3 == 66);
    ++iter3;
    ASSERT_TRUE(*iter3 == 39);
    --iter3;
    ASSERT_TRUE(*iter3 == 66);
    --iter3;
    ASSERT_TRUE(*iter3 == 65);


}

TEST(test_copy_all) {
    List<int> my_list;
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);

    List<int> my_list2;
    my_list2 = my_list;

    List<int>::Iterator iter = my_list2.begin();

    ASSERT_TRUE(*iter == 1);
    ++iter;
    ASSERT_TRUE(*iter == 2);
    ++iter;
    ASSERT_TRUE(*iter == 3);

    iter = my_list2.begin();
    ++iter;
    ++iter;
    ASSERT_TRUE(*iter == 3);
    --iter;
    ASSERT_TRUE(*iter == 2);
    --iter;
    ASSERT_TRUE(*iter == 1);

    //one element
    List<int> my_list3;
    my_list3.push_back(1);

    List<int> my_list4;
    my_list4 = my_list3;

    List<int>::Iterator iter2 = my_list4.begin();
    List<int>::Iterator default_iter;

    ASSERT_TRUE(*iter2 == 1);
    ++iter2;
    ASSERT_TRUE(iter2 == default_iter);

    //no elements
    List<int> my_list5;

    List<int> my_list6;
    my_list6 = my_list5;

    List<int>::Iterator iter3 = my_list6.begin();
    ASSERT_TRUE(iter3 == default_iter);
}

TEST(test_iterator_default_ctor) {
    List<int>::Iterator iter;
    
    List<int> my_list;
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);

    List<int>::Iterator iter2 = my_list.begin();

    ASSERT_TRUE(iter != iter2);

    my_list.pop_back();
    my_list.pop_back();
    my_list.pop_back();

    iter2 = my_list.begin();

    ASSERT_TRUE(iter == iter2);
}

TEST(test_iterator_begin) {
    //one element
    List<int> my_list;
    my_list.push_back(10);
    List<int>::Iterator iter = my_list.begin();
    ASSERT_TRUE(*iter == 10);
    //two elements
    my_list.push_front(15);
    iter = my_list.begin();
    ASSERT_TRUE(*iter == 15);
    //more than 2 elements
    List<int> my_list2;
    my_list2.push_back(11);
    my_list2.push_back(16);
    my_list2.push_back(21);
    List<int>::Iterator iter2 = my_list2.begin();
    ASSERT_TRUE(*iter2 == 11);
}

TEST(test_iterator_end) {
    List<int>::Iterator default_iter;
    
    //one element
    List<int> my_list;
    my_list.push_back(10);
    List<int>::Iterator iter = my_list.end();
    //ASSERT_TRUE(*iter == 10);
    ASSERT_TRUE(iter == default_iter);

    //two elements
    my_list.push_back(15);
    iter = my_list.end();
    //ASSERT_TRUE(*iter == 15);
    ASSERT_TRUE(iter == default_iter);

    //more than 2 elements
    List<int> my_list2;
    my_list2.push_back(11);
    my_list2.push_back(16);
    my_list2.push_back(21);
    List<int>::Iterator iter2 = my_list2.end();
    //ASSERT_TRUE(*iter2 == 21);
    ASSERT_TRUE(iter2 == default_iter);

}

TEST(test_iterator_erase) {
    //1 element
    List<int> my_list;
    my_list.push_front(14);
    ASSERT_TRUE(my_list.size() == 1);
    List<int>::Iterator iter = my_list.begin();
    my_list.erase(iter);
    ASSERT_TRUE(my_list.empty());
    ASSERT_TRUE(my_list.size() == 0);

    //first element
    List<int> my_list2;
    my_list2.push_back(11);
    my_list2.push_back(16);
    my_list2.push_back(21);
    ASSERT_TRUE(my_list2.size() == 3);

    List<int>::Iterator iter2 = my_list2.begin();
    my_list2.erase(iter2);
    iter2 = my_list2.begin();
    ASSERT_TRUE(my_list2.size() == 2);
    ASSERT_TRUE(*iter2 == 16);
    ++iter2;
    ASSERT_TRUE(*iter2 == 21);

    //last element
    List<int> my_list3;
    my_list3.push_back(11);
    my_list3.push_back(16);
    my_list3.push_back(21);
    ASSERT_TRUE(my_list3.size() == 3);
    List<int>::Iterator iter3 = my_list3.begin();
    ++iter3;
    ++iter3;
    my_list3.erase(iter3);
    iter3 = my_list3.begin();
    ASSERT_TRUE(my_list3.size() == 2);
    ASSERT_TRUE(*iter3 == 11);
    ++iter3;
    ASSERT_TRUE(*iter3 == 16);

    //more than 3 elements
    List<int> my_list4;
    my_list4.push_back(11);
    my_list4.push_back(16);
    my_list4.push_back(21);
    my_list4.push_back(26);
    my_list4.push_back(31);
    ASSERT_TRUE(my_list4.size() == 5);
    List<int>::Iterator iter4 = my_list4.begin();
    ++iter4;
    ++iter4;
    my_list4.erase(iter4);
    iter4 = my_list4.begin();
    ASSERT_TRUE(my_list4.size() == 4);
    ASSERT_TRUE(*iter4 == 11);
    ++iter4;
    ASSERT_TRUE(*iter4 == 16);
    ++iter4;
    ASSERT_TRUE(*iter4 == 26);
    ++iter4;
    ASSERT_TRUE(*iter4 == 31);
    iter4 = my_list4.begin();
    ++iter4;
    ++iter4;
    ++iter4;
    ASSERT_TRUE(*iter4 == 31);
    --iter4;
    ASSERT_TRUE(*iter4 == 26);
    --iter4;
    ASSERT_TRUE(*iter4 == 16);
    --iter4;
    ASSERT_TRUE(*iter4 == 11);

    //iter is second element
    
    List<int> my_list5;
    my_list5.push_back(11);
    my_list5.push_back(16);
    my_list5.push_back(21);
    my_list5.push_back(26);
    my_list5.push_back(31);
    ASSERT_TRUE(my_list5.size() == 5);
    List<int>::Iterator iter5 = my_list5.begin();
    ++iter5;
    my_list5.erase(iter5);
    iter5 = my_list5.begin();
    ASSERT_TRUE(my_list5.size() == 4);
    ASSERT_TRUE(*iter5 == 11);
    ++iter5;
    ASSERT_TRUE(*iter5 == 21);
    ++iter5;
    ASSERT_TRUE(*iter5 == 26);
    ++iter5;
    ASSERT_TRUE(*iter5 == 31);
    iter5 = my_list5.begin();
    ++iter5;
    ++iter5;
    ++iter5;
    ASSERT_TRUE(*iter5 == 31);
    --iter5;
    ASSERT_TRUE(*iter5 == 26);
    --iter5;
    ASSERT_TRUE(*iter5 == 21);
    --iter5;
    ASSERT_TRUE(*iter5 == 11);
 
    //iter is second last element
    List<int> my_list6;
    my_list6.push_back(11);
    my_list6.push_back(16);
    my_list6.push_back(21);
    my_list6.push_back(26);
    my_list6.push_back(31);
    ASSERT_TRUE(my_list6.size() == 5);
    List<int>::Iterator iter6 = my_list6.begin();
    ++iter6;
    ++iter6;
    ++iter6;
    my_list6.erase(iter6);
    iter6 = my_list6.begin();
    ASSERT_TRUE(my_list6.size() == 4);
    ASSERT_TRUE(*iter6 == 11);
    ++iter6;
    ASSERT_TRUE(*iter6 == 16);
    ++iter6;
    ASSERT_TRUE(*iter6 == 21);
    ++iter6;
    ASSERT_TRUE(*iter6 == 31);
    iter6 = my_list6.begin();
    ++iter6;
    ++iter6;
    ++iter6;
    ASSERT_TRUE(*iter6 == 31);
    --iter6;
    ASSERT_TRUE(*iter6 == 21);
    --iter6;
    ASSERT_TRUE(*iter6 == 16);
    --iter6;
    ASSERT_TRUE(*iter6 == 11);
    
}

TEST(test_iterator_insert) {
    //0 elements
    List<int> my_list;
    ASSERT_TRUE(my_list.size() == 0);
    List<int>::Iterator iter = my_list.begin();
    my_list.insert(iter, 12);
    iter = my_list.begin();
    ASSERT_TRUE(*iter == 12);
    ASSERT_TRUE(my_list.size() == 1);

    //first element
    List<int> my_list2;
    my_list2.push_back(11);
    my_list2.push_back(16);
    my_list2.push_back(21);
    ASSERT_TRUE(my_list2.size() == 3);
    List<int>::Iterator iter2 = my_list2.begin();
    my_list2.insert(iter2, 5);
    iter2 = my_list2.begin();
    ASSERT_TRUE(*iter2 == 5);
    ++iter2;
    ASSERT_TRUE(*iter2 == 11);
    ++iter2;
    ASSERT_TRUE(*iter2 == 16);
    ++iter2;
    ASSERT_TRUE(*iter2 == 21);
    ASSERT_TRUE(my_list2.size() == 4);

    //last element
    List<int> my_list3;
    my_list3.push_back(11);
    my_list3.push_back(16);
    my_list3.push_back(21);
    ASSERT_TRUE(my_list3.size() == 3);
    List<int>::Iterator iter3 = my_list3.begin();
    ++iter3;
    ++iter3;
    my_list3.insert(iter3, 75);
    iter3 = my_list3.begin();
    ASSERT_TRUE(*iter3 == 11);
    ++iter3;
    ASSERT_TRUE(*iter3 == 16);
    ++iter3;
    ASSERT_TRUE(*iter3 == 75);
    ++iter3;
    ASSERT_TRUE(*iter3 == 21);
    ASSERT_TRUE(my_list3.size() == 4);

    //one element
    List<int> my_list4;
    my_list4.push_back(11);
    ASSERT_TRUE(my_list4.size() == 1);
    List<int>::Iterator iter4 = my_list4.begin();
    my_list4.insert(iter4, 17);
    iter4 = my_list4.begin();
    ASSERT_TRUE(*iter4 == 17);
    ++iter4;
    ASSERT_TRUE(*iter4 == 11);
    ASSERT_TRUE(my_list4.size() == 2);

    //more than 2 elements
    List<int> my_list5;
    my_list5.push_back(11);
    my_list5.push_back(16);
    my_list5.push_back(21);
    my_list5.push_back(26);
    my_list5.push_back(31);
    ASSERT_TRUE(my_list5.size() == 5);
    List<int>::Iterator iter5 = my_list5.begin();
    ++iter5;
    ++iter5;
    ++iter5;
    my_list5.insert(iter5, 108);
    iter5 = my_list5.begin();
    ASSERT_TRUE(*iter5 == 11);
    ++iter5;
    ASSERT_TRUE(*iter5 == 16);
    ++iter5;
    ASSERT_TRUE(*iter5 == 21);
    ++iter5;
    ASSERT_TRUE(*iter5 == 108);
    ++iter5;
    ASSERT_TRUE(*iter5 == 26);
    ++iter5;
    ASSERT_TRUE(*iter5 == 31);
    ASSERT_TRUE(my_list5.size() == 6);

    //iter is second node
    List<int> my_list6;
    my_list6.push_back(11);
    my_list6.push_back(16);
    my_list6.push_back(21);
    my_list6.push_back(26);
    my_list6.push_back(31);
    ASSERT_TRUE(my_list6.size() == 5);
    List<int>::Iterator iter6 = my_list6.begin();
    ++iter6;
    my_list6.insert(iter6, 111);
    iter6 = my_list6.begin();
    ASSERT_TRUE(*iter6 == 11);
    ++iter6;
    ASSERT_TRUE(*iter6 == 111);
    ++iter6;
    ASSERT_TRUE(*iter6 == 16);
    ++iter6;
    ASSERT_TRUE(*iter6 == 21);
    ++iter6;
    ASSERT_TRUE(*iter6 == 26);
    ++iter6;
    ASSERT_TRUE(*iter6 == 31);
    ASSERT_TRUE(my_list6.size() == 6);

    //iter is second last node
    List<int> my_list7;
    my_list7.push_back(11);
    my_list7.push_back(16);
    my_list7.push_back(21);
    my_list7.push_back(26);
    my_list7.push_back(31);
    ASSERT_TRUE(my_list7.size() == 5);
    List<int>::Iterator iter7 = my_list7.begin();
    ++iter7;
    ++iter7;
    ++iter7;
    my_list7.insert(iter7, 13);
    iter7 = my_list7.begin();
    ASSERT_TRUE(*iter7 == 11);
    ++iter7;
    ASSERT_TRUE(*iter7 == 16);
    ++iter7;
    ASSERT_TRUE(*iter7 == 21);
    ++iter7;
    ASSERT_TRUE(*iter7 == 13);
    ++iter7;
    ASSERT_TRUE(*iter7 == 26);
    ++iter7;
    ASSERT_TRUE(*iter7 == 31);
    ASSERT_TRUE(my_list7.size() == 6);

    //backwards traversal
    iter7 = my_list7.begin();
    ++iter7;
    ++iter7;
    ++iter7;
    ++iter7;
    ++iter7;

    ASSERT_TRUE(*iter7 == 31);
    --iter7;
    ASSERT_TRUE(*iter7 == 26);
    --iter7;
    ASSERT_TRUE(*iter7 == 13);
    --iter7;
    ASSERT_TRUE(*iter7 == 21);
    --iter7;
    ASSERT_TRUE(*iter7 == 16);
    --iter7;
    ASSERT_TRUE(*iter7 == 11);
}

TEST_MAIN()
