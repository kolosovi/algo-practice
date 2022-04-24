#include <gtest/gtest.h>

#include "shared_ptr.hpp"

#include <memory>

class Pointee {
public:
    Pointee(int *delete_count) : delete_count_(delete_count) {}
    ~Pointee() {
        (*delete_count_)++;
    }

private:
    int *delete_count_;
};

class PointeeMock {
public:
    PointeeMock() : delete_count_(0), ptr_(new Pointee(&delete_count_)) {}

    int DeleteCount() const {
        return delete_count_;
    }

    Pointee* Ptr() const {
        return ptr_;
    }

private:
    int delete_count_;
    Pointee *ptr_;
};

TEST(SharedPtrDefaultCtorTest, IsFalse) {
    shared_ptr<Pointee> ptr;
    EXPECT_FALSE(ptr);
}

TEST(SharedPtrDefaultCtorTest, GetReturnsNull) {
    shared_ptr<Pointee> ptr;
    EXPECT_EQ(ptr.get(), nullptr);
}

TEST(SharedPtrDefaultCtorTest, ZeroUseCount) {
    shared_ptr<Pointee> ptr;
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(SharedPtrPointeeCtorTest, IsFalseWhenFromNull) {
    shared_ptr<Pointee> ptr(nullptr);
    EXPECT_FALSE(ptr);
}

TEST(SharedPtrPointeeCtorTest, IsTrueWhenFromNotNull) {
    PointeeMock p;
    shared_ptr<Pointee> ptr(p.Ptr());
    EXPECT_TRUE(ptr);
}

TEST(SharedPtrPointeeCtorTest, GetReturnsNullWhenFromNull) {
    shared_ptr<Pointee> ptr(nullptr);
    EXPECT_EQ(ptr.get(), nullptr);
}

TEST(SharedPtrPointeeCtorTest, GetReturnsPointeeWhenFromNotNull) {
    PointeeMock p;
    shared_ptr<Pointee> ptr(p.Ptr());
    EXPECT_EQ(ptr.get(), p.Ptr());
}

TEST(SharedPtrPointeeCtorTest, ZeroUseCountWhenFromNull) {
    shared_ptr<Pointee> ptr(nullptr);
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(SharedPtrPointeeCtorTest, NonZeroUseCountWhenFromNotNull) {
    PointeeMock p;
    shared_ptr<Pointee> ptr(p.Ptr());
    EXPECT_EQ(ptr.use_count(), 1);
}

TEST(SharedPtrPointeeDtorTest, WhenNullPointee) {
    shared_ptr<Pointee> ptr(nullptr);
}

TEST(SharedPtrPointeeDtorTest, WhenLastPointer) {
    PointeeMock p;
    EXPECT_EQ(p.DeleteCount(), 0);
    {
        shared_ptr<Pointee> ptr(p.Ptr());
    }
    EXPECT_EQ(p.DeleteCount(), 1);
}

TEST(SharedPtrPointeeDtorTest, WhenNotLastPointer) {
    PointeeMock p;
    EXPECT_EQ(p.DeleteCount(), 0);
    {
        shared_ptr<Pointee> ptr_1(p.Ptr());
        {
            shared_ptr<Pointee> ptr(ptr_1);
        }
        EXPECT_EQ(p.DeleteCount(), 0);
    }
    EXPECT_EQ(p.DeleteCount(), 1);
}

TEST(SharedPtrCopyCtorTest, WhenNullPointee) {
    shared_ptr<Pointee> orig(nullptr);
    shared_ptr<Pointee> ptr(orig);

    EXPECT_FALSE(orig);
    EXPECT_FALSE(ptr);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(SharedPtrCopyCtorTest, WhenNonNullPointee) {
    PointeeMock p;
    shared_ptr<Pointee> orig(p.Ptr());
    shared_ptr<Pointee> ptr(orig);

    EXPECT_TRUE(orig);
    EXPECT_TRUE(ptr);
    EXPECT_EQ(orig.get(), p.Ptr());
    EXPECT_EQ(ptr.get(), p.Ptr());
    EXPECT_EQ(orig.use_count(), 2);
    EXPECT_EQ(ptr.use_count(), 2);
}

TEST(SharedPtrMoveCtorTest, WhenNullPointee) {
    shared_ptr<Pointee> orig(nullptr);
    shared_ptr<Pointee> ptr(std::move(orig));

    EXPECT_FALSE(orig);
    EXPECT_FALSE(ptr);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(SharedPtrMoveCtorTest, WhenNonNullPointee) {
    PointeeMock p;
    shared_ptr<Pointee> orig(p.Ptr());
    EXPECT_EQ(orig.use_count(), 1);
    shared_ptr<Pointee> ptr(std::move(orig));

    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);

    EXPECT_TRUE(ptr);
    EXPECT_EQ(ptr.get(), p.Ptr());
    EXPECT_EQ(ptr.use_count(), 1);
}

TEST(SharedPtrCopyAssignmentTest, WhenCopyToSelfAndNullPointee) {
    shared_ptr<Pointee> orig;
    orig = orig;
    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
}

TEST(SharedPtrCopyAssignmentTest, WhenCopyToSelfAndNonNullPointee) {
    PointeeMock p;
    shared_ptr<Pointee> orig(p.Ptr());
    orig = orig;
    EXPECT_TRUE(orig);
    EXPECT_EQ(orig.get(), p.Ptr());
    EXPECT_EQ(orig.use_count(), 1);
    EXPECT_EQ(p.DeleteCount(), 0);
}

TEST(SharedPtrCopyAssignmentTest, WhenOnlyMyIsNull) {
    PointeeMock p;
    shared_ptr<Pointee> orig(p.Ptr());
    shared_ptr<Pointee> ptr;
    ptr = orig;

    EXPECT_TRUE(orig);
    EXPECT_EQ(orig.get(), p.Ptr());
    EXPECT_EQ(orig.use_count(), 2);
    EXPECT_TRUE(ptr);
    EXPECT_EQ(ptr.get(), p.Ptr());
    EXPECT_EQ(ptr.use_count(), 2);
    EXPECT_EQ(p.DeleteCount(), 0);
}

TEST(SharedPtrCopyAssignmentTest, WhenOnlyTheirsIsNullAndImLast) {
    shared_ptr<Pointee> orig;
    PointeeMock p;
    shared_ptr<Pointee> ptr(p.Ptr());
    ptr = orig;

    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_FALSE(ptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0);
    EXPECT_EQ(p.DeleteCount(), 1);
}

TEST(SharedPtrCopyAssignmentTest, WhenOnlyTheirsIsNullAndImNotLast) {
    shared_ptr<Pointee> orig;
    PointeeMock p;
    shared_ptr<Pointee> other_ptr(p.Ptr());
    shared_ptr<Pointee> ptr(other_ptr);
    ptr = orig;

    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_FALSE(ptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0);
    EXPECT_TRUE(other_ptr);
    EXPECT_EQ(other_ptr.get(), p.Ptr());
    EXPECT_EQ(other_ptr.use_count(), 1);
    EXPECT_EQ(p.DeleteCount(), 0);
}

TEST(SharedPtrCopyAssignmentTest, WhenBothPointeesAreNull) {
    shared_ptr<Pointee> orig;
    shared_ptr<Pointee> ptr;
    ptr = orig;

    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_FALSE(ptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(SharedPtrCopyAssignmentTest, WhenPointeesEqual) {
    PointeeMock p;
    {
        shared_ptr<Pointee> orig(p.Ptr());
        shared_ptr<Pointee> ptr(orig);
        ptr = orig;

        EXPECT_TRUE(orig);
        EXPECT_TRUE(ptr);
        EXPECT_EQ(orig.get(), p.Ptr());
        EXPECT_EQ(ptr.get(), p.Ptr());
        EXPECT_EQ(orig.use_count(), 2);
        EXPECT_EQ(ptr.use_count(), 2);
        EXPECT_EQ(p.DeleteCount(), 0);
    }
    EXPECT_EQ(p.DeleteCount(), 1);
}

TEST(SharedPtrCopyAssignmentTest, WhenPointeesNotEqualAndImNotLast) {
    PointeeMock p1;
    PointeeMock p2;
    shared_ptr<Pointee> last(p1.Ptr());
    {
        shared_ptr<Pointee> orig(p2.Ptr());
        shared_ptr<Pointee> ptr(last);
        ptr = orig;

        EXPECT_TRUE(orig);
        EXPECT_TRUE(ptr);
        EXPECT_EQ(orig.get(), p2.Ptr());
        EXPECT_EQ(ptr.get(), p2.Ptr());
        EXPECT_EQ(orig.use_count(), 2);
        EXPECT_EQ(ptr.use_count(), 2);
        EXPECT_EQ(p1.DeleteCount(), 0);
        EXPECT_EQ(p2.DeleteCount(), 0);
    }
    EXPECT_EQ(p1.DeleteCount(), 0);
    EXPECT_EQ(p2.DeleteCount(), 1);
}

TEST(SharedPtrCopyAssignmentTest, WhenPointeesNotEqualAndImLast) {
    PointeeMock p1;
    PointeeMock p2;
    {
        shared_ptr<Pointee> orig(p2.Ptr());
        shared_ptr<Pointee> ptr(p1.Ptr());
        ptr = orig;

        EXPECT_TRUE(orig);
        EXPECT_TRUE(ptr);
        EXPECT_EQ(orig.get(), p2.Ptr());
        EXPECT_EQ(ptr.get(), p2.Ptr());
        EXPECT_EQ(orig.use_count(), 2);
        EXPECT_EQ(ptr.use_count(), 2);
        EXPECT_EQ(p1.DeleteCount(), 1);
        EXPECT_EQ(p2.DeleteCount(), 0);
    }
    EXPECT_EQ(p2.DeleteCount(), 1);
}

TEST(SharedPtrMoveAssignmentTest, WhenMoveToSelfAndNullPointee) {
    shared_ptr<Pointee> orig;
    orig = std::move(orig);
    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
}

TEST(SharedPtrMoveAssignmentTest, WhenMoveToSelfAndNonNullPointee) {
    PointeeMock p1;
    shared_ptr<Pointee> orig(p1.Ptr());
    orig = std::move(orig);
    EXPECT_TRUE(orig);
    EXPECT_EQ(orig.get(), p1.Ptr());
    EXPECT_EQ(orig.use_count(), 1);
    EXPECT_EQ(p1.DeleteCount(), 0);
}

TEST(SharedPtrMoveAssignmentTest, WhenOnlyMyIsNull) {
    PointeeMock p;
    shared_ptr<Pointee> orig(p.Ptr());
    shared_ptr<Pointee> ptr;
    ptr = std::move(orig);

    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_TRUE(ptr);
    EXPECT_EQ(ptr.get(), p.Ptr());
    EXPECT_EQ(ptr.use_count(), 1);
    EXPECT_EQ(p.DeleteCount(), 0);
}

TEST(SharedPtrMoveAssignmentTest, WhenPointeesNotEqualAndImLast) {
    PointeeMock p1;
    PointeeMock p2;
    {
        shared_ptr<Pointee> orig(p2.Ptr());
        shared_ptr<Pointee> ptr(p1.Ptr());
        ptr = std::move(orig);

        EXPECT_FALSE(orig);
        EXPECT_TRUE(ptr);
        EXPECT_EQ(orig.get(), nullptr);
        EXPECT_EQ(ptr.get(), p2.Ptr());
        EXPECT_EQ(orig.use_count(), 0);
        EXPECT_EQ(ptr.use_count(), 1);
        EXPECT_EQ(p1.DeleteCount(), 1);
        EXPECT_EQ(p2.DeleteCount(), 0);
    }
    EXPECT_EQ(p2.DeleteCount(), 1);
}

TEST(SharedPtrMoveAssignmentTest, WhenPointeesNotEqualAndImNotLast) {
    PointeeMock p1;
    PointeeMock p2;
    shared_ptr<Pointee> last(p1.Ptr());
    {
        shared_ptr<Pointee> orig(p2.Ptr());
        shared_ptr<Pointee> ptr(last);
        ptr = std::move(orig);

        EXPECT_FALSE(orig);
        EXPECT_TRUE(ptr);
        EXPECT_EQ(orig.get(), nullptr);
        EXPECT_EQ(ptr.get(), p2.Ptr());
        EXPECT_EQ(orig.use_count(), 0);
        EXPECT_EQ(ptr.use_count(), 1);
        EXPECT_EQ(p1.DeleteCount(), 0);
        EXPECT_EQ(p2.DeleteCount(), 0);
    }
    EXPECT_EQ(p1.DeleteCount(), 0);
    EXPECT_EQ(p2.DeleteCount(), 1);
}

TEST(SharedPtrMoveAssignmentTest, WhenBothPointeesAreNull) {
    shared_ptr<Pointee> orig;
    shared_ptr<Pointee> ptr;
    ptr = std::move(orig);

    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_FALSE(ptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0);
}

TEST(SharedPtrMoveAssignmentTest, WhenPointeesEqual) {
    PointeeMock p;
    {
        shared_ptr<Pointee> orig(p.Ptr());
        shared_ptr<Pointee> ptr(orig);
        ptr = std::move(orig);

        EXPECT_FALSE(orig);
        EXPECT_TRUE(ptr);
        EXPECT_EQ(orig.get(), nullptr);
        EXPECT_EQ(ptr.get(), p.Ptr());
        EXPECT_EQ(orig.use_count(), 0);
        EXPECT_EQ(ptr.use_count(), 1);
        EXPECT_EQ(p.DeleteCount(), 0);
    }
    EXPECT_EQ(p.DeleteCount(), 1);
}

TEST(SharedPtrMoveAssignmentTest, WhenOnlyTheirsIsNullAndImLast) {
    shared_ptr<Pointee> orig;
    PointeeMock p;
    shared_ptr<Pointee> ptr(p.Ptr());
    ptr = std::move(orig);

    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_FALSE(ptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0);
    EXPECT_EQ(p.DeleteCount(), 1);
}

TEST(SharedPtrMoveAssignmentTest, WhenOnlyTheirsIsNullAndImNotLast) {
    shared_ptr<Pointee> orig;
    PointeeMock p;
    shared_ptr<Pointee> other_ptr(p.Ptr());
    shared_ptr<Pointee> ptr(other_ptr);
    ptr = std::move(orig);

    EXPECT_FALSE(orig);
    EXPECT_EQ(orig.get(), nullptr);
    EXPECT_EQ(orig.use_count(), 0);
    EXPECT_FALSE(ptr);
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0);
    EXPECT_TRUE(other_ptr);
    EXPECT_EQ(other_ptr.get(), p.Ptr());
    EXPECT_EQ(other_ptr.use_count(), 1);
    EXPECT_EQ(p.DeleteCount(), 0);
}
