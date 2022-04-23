#include <gtest/gtest.h>

#include "unique_ptr.hpp"

namespace {

class PointeeMock {
public:
    PointeeMock(int *delete_count) : delete_count_(delete_count) {}
    ~PointeeMock() {
        (*delete_count_)++;
    }

private:
    int *delete_count_;
};

}

TEST(UniquePtrBoolTest, DefaultConstructedIsFalse) {
  unique_ptr<int> ptr;
  EXPECT_FALSE(ptr);
}

TEST(UniquePtrBoolTest, ConstructedFromNullptrIsFalse) {
  unique_ptr<int> ptr(nullptr);
  EXPECT_FALSE(ptr);
}

TEST(UniquePtrBoolTest, ConstructedFromNonNullPtrIsTrue) {
  auto *raw_ptr = new int(42);
  unique_ptr<int> ptr(raw_ptr);
  EXPECT_TRUE(ptr);
}

TEST(UniquePtrDestructorTest, PointeeIsDeleted) {
    int delete_count = 0;
    auto *mock = new PointeeMock(&delete_count);
    {
        unique_ptr<PointeeMock> ptr(mock);
    }
    EXPECT_EQ(delete_count, 1);
}

TEST(UniquePtrGetTest, WhenEmpty) {
    unique_ptr<PointeeMock> ptr;
    EXPECT_EQ(ptr.Get(), nullptr);
}

TEST(UniquePtrGetTest, WhenNotEmpty) {
    int delete_count = 0;
    auto *mock = new PointeeMock(&delete_count);
    unique_ptr<PointeeMock> ptr(mock);
    EXPECT_EQ(ptr.Get(), mock);
}

TEST(UniquePtrMoveCtorTest, RawPtrIsExchanged) {
    int delete_count = 0;
    auto *mock = new PointeeMock(&delete_count);
    unique_ptr<PointeeMock> ptr_moved_from(mock);
    unique_ptr<PointeeMock> ptr_moved_to(std::move(ptr_moved_from));
    EXPECT_FALSE(ptr_moved_from);
    EXPECT_TRUE(ptr_moved_to);
    EXPECT_EQ(ptr_moved_to.Get(), mock);
    EXPECT_EQ(delete_count, 0);
}

TEST(UniquePtrMoveAssignmentTest, WhenPointeesAreDifferent) {
    int delete_count_old = 0, delete_count_new;
    auto *mock_old = new PointeeMock(&delete_count_old);
    auto *mock_new = new PointeeMock(&delete_count_new);
    unique_ptr<PointeeMock> ptr_old(mock_old);
    unique_ptr<PointeeMock> ptr_new(mock_new);
    ptr_new = std::move(ptr_old);
    EXPECT_FALSE(ptr_old);
    EXPECT_TRUE(ptr_new);
    EXPECT_EQ(ptr_new.Get(), mock_old);
    EXPECT_EQ(delete_count_old, 0);
    EXPECT_EQ(delete_count_new, 1);
}

// error: call to deleted constructor of 'unique_ptr<(anonymous namespace)::PointeeMock>'
// TEST(UniquePtrIsNotCopyable, ViaCtor) {
//     int delete_count = 0;
//     auto *mock = new PointeeMock(&delete_count);
//     unique_ptr<PointeeMock> ptr(mock);
//     unique_ptr<PointeeMock> new_ptr(ptr);
//     EXPECT_TRUE(new_ptr);
// }

// error: overload resolution selected deleted operator '='
// TEST(UniquePtrIsNotCopyable, ViaAssignment) {
//     int delete_count = 0;
//     auto *mock = new PointeeMock(&delete_count);
//     unique_ptr<PointeeMock> ptr(mock);
//     unique_ptr<PointeeMock> new_ptr;
//     new_ptr = ptr;
//     EXPECT_TRUE(new_ptr);
// }
