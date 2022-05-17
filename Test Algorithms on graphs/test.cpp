#include "pch.h"
#include "gtest/gtest.h"
#include "..\Algorithms on graphs\AdjacencyMatrix.h"


TEST(Test_FloydWarshall) {
    AdjacencyMatrix matrix;

    ASSERT_THROW(matrix.FloydWarshall(), invalid_argument);

    matrix.insert("One");
    matrix.insert("Two");
    matrix.insert("Three");
    matrix.insert("Four");

    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(3)->data.path = "One --> Four";
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(3)->data.weightPath = 1;
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(1)->data.path = "One --> Two";
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(1)->data.weightPath = 8;
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(2)->data.path = "Four --> Three";
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(2)->data.weightPath = 9;
    matrix.listRows.getIndex(1)->data.listDestinations.getIndex(2)->data.path = "Two --> Three";
    matrix.listRows.getIndex(1)->data.listDestinations.getIndex(2)->data.weightPath = 1;
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(1)->data.path = "Four --> Two";
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(1)->data.weightPath = 2;
    matrix.listRows.getIndex(2)->data.listDestinations.getIndex(0)->data.path = "Three --> One";
    matrix.listRows.getIndex(2)->data.listDestinations.getIndex(0)->data.weightPath = 4;

    matrix.FloydWarshall();

    ASSERT_EQ(matrix.listRows.getIndex(0)->data.listDestinations.getIndex(0)->data.weightPath, 0);
    ASSERT_EQ(matrix.listRows.getIndex(0)->data.listDestinations.getIndex(1)->data.weightPath, 3);
    ASSERT_EQ(matrix.listRows.getIndex(0)->data.listDestinations.getIndex(2)->data.weightPath, 4);
    ASSERT_EQ(matrix.listRows.getIndex(0)->data.listDestinations.getIndex(3)->data.weightPath, 1);
    ASSERT_EQ(matrix.listRows.getIndex(1)->data.listDestinations.getIndex(0)->data.weightPath, 5);
    ASSERT_EQ(matrix.listRows.getIndex(1)->data.listDestinations.getIndex(1)->data.weightPath, 0);
    ASSERT_EQ(matrix.listRows.getIndex(1)->data.listDestinations.getIndex(2)->data.weightPath, 1);
    ASSERT_EQ(matrix.listRows.getIndex(1)->data.listDestinations.getIndex(3)->data.weightPath, 6);
    ASSERT_EQ(matrix.listRows.getIndex(2)->data.listDestinations.getIndex(0)->data.weightPath, 4);
    ASSERT_EQ(matrix.listRows.getIndex(2)->data.listDestinations.getIndex(1)->data.weightPath, 7);
    ASSERT_EQ(matrix.listRows.getIndex(2)->data.listDestinations.getIndex(2)->data.weightPath, 0);
    ASSERT_EQ(matrix.listRows.getIndex(2)->data.listDestinations.getIndex(3)->data.weightPath, 5);
    ASSERT_EQ(matrix.listRows.getIndex(3)->data.listDestinations.getIndex(0)->data.weightPath, 7);
    ASSERT_EQ(matrix.listRows.getIndex(3)->data.listDestinations.getIndex(1)->data.weightPath, 2);
    ASSERT_EQ(matrix.listRows.getIndex(3)->data.listDestinations.getIndex(2)->data.weightPath, 3);
    ASSERT_EQ(matrix.listRows.getIndex(3)->data.listDestinations.getIndex(3)->data.weightPath, 0);

}

TEST(Test_ShortedPath) {
    AdjacencyMatrix matrix;

    ASSERT_THROW(matrix.shortedPath("One", "Two"), logic_error);

    matrix.insert("One");
    matrix.insert("Two");
    matrix.insert("Three");
    matrix.insert("Four");

    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(3)->data.path = "One --> Four";
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(3)->data.weightPath = 1;
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(1)->data.path = "One --> Two";
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(1)->data.weightPath = 8;
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(2)->data.path = "Four --> Three";
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(2)->data.weightPath = 9;
    matrix.listRows.getIndex(1)->data.listDestinations.getIndex(2)->data.path = "Two --> Three";
    matrix.listRows.getIndex(1)->data.listDestinations.getIndex(2)->data.weightPath = 1;
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(1)->data.path = "Four --> Two";
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(1)->data.weightPath = 2;
    matrix.listRows.getIndex(2)->data.listDestinations.getIndex(0)->data.path = "Three --> One";
    matrix.listRows.getIndex(2)->data.listDestinations.getIndex(0)->data.weightPath = 4;

    matrix.FloydWarshall();

    ASSERT_EQ(matrix.shortedPath("Three", "Two"), "Three --> One\nOne --> Four\nFour --> Two");
    ASSERT_EQ(matrix.shortedPath("One", "Three"), "One --> Four\nFour --> Two\nTwo --> Three");
    ASSERT_EQ(matrix.shortedPath("One", "Two"), "One --> Four\nFour --> Two");
}

TEST(Test_WeighthSortedPath) {
    AdjacencyMatrix matrix;

    ASSERT_THROW(matrix.weighthSortedPath("One", "Two"), logic_error);

    matrix.insert("One");
    matrix.insert("Two");
    matrix.insert("Three");
    matrix.insert("Four");

    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(3)->data.path = "One --> Four";
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(3)->data.weightPath = 1;
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(1)->data.path = "One --> Two";
    matrix.listRows.getIndex(0)->data.listDestinations.getIndex(1)->data.weightPath = 8;
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(2)->data.path = "Four --> Three";
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(2)->data.weightPath = 9;
    matrix.listRows.getIndex(1)->data.listDestinations.getIndex(2)->data.path = "Two --> Three";
    matrix.listRows.getIndex(1)->data.listDestinations.getIndex(2)->data.weightPath = 1;
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(1)->data.path = "Four --> Two";
    matrix.listRows.getIndex(3)->data.listDestinations.getIndex(1)->data.weightPath = 2;
    matrix.listRows.getIndex(2)->data.listDestinations.getIndex(0)->data.path = "Three --> One";
    matrix.listRows.getIndex(2)->data.listDestinations.getIndex(0)->data.weightPath = 4;

    matrix.FloydWarshall();

    ASSERT_EQ(matrix.weighthSortedPath("Three", "Two"), 7);
    ASSERT_EQ(matrix.weighthSortedPath("One", "Three"), 4);
    ASSERT_EQ(matrix.weighthSortedPath("One", "Two"), 3);

}