#include <queuer/queuer.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>


TEST_CASE("QueueR::isEmpty()") {
    QueueR q;
    REQUIRE(q.isEmpty());
}

TEST_CASE("QueueR::push(int value)") {
    QueueR q;
    int value = 10;
    q.push(value);
    REQUIRE_FALSE(q.isEmpty());
}

TEST_CASE("QueueR::top()") {
    QueueR q;
    int value = 10;
    q.push(value);
    REQUIRE(q.top() == value);
}

TEST_CASE("QueueR::pop()") {
    QueueR q;
    int value = 10;
    q.push(value);
    q.pop();
    REQUIRE(q.isEmpty());
}

TEST_CASE("Test of priority") {
    QueueR q;
    int value1 = 10;
    int value2 = 20;
    int value3 = 30;
    REQUIRE(q.isEmpty());
    q.push(value2);
    REQUIRE_FALSE(q.isEmpty());
    REQUIRE(q.top() == value2);
    q.push(value3);
    REQUIRE_FALSE(q.isEmpty());
    REQUIRE(q.top() == value2);
    q.push(value1);
    REQUIRE_FALSE(q.isEmpty());
    REQUIRE(q.top() == value1);
    q.pop();
    REQUIRE_FALSE(q.isEmpty());
    REQUIRE(q.top() == value2);
    q.pop();
    REQUIRE_FALSE(q.isEmpty());
    REQUIRE(q.top() == value3);
    q.pop();
    REQUIRE(q.isEmpty());
}
