#pragma once

template <typename T>
class shared_ptr {
public:
    shared_ptr() : shared_ptr(nullptr) {}

    explicit shared_ptr(T *ptr) : ptr_(ptr), use_count_(ptr == nullptr ? nullptr : new size_t(1)) {}

    shared_ptr(const shared_ptr<T> &other) : ptr_(other.ptr_), use_count_(other.use_count_) {
        if (ptr_ != nullptr) {
            (*use_count_)++;
        }
    }

    shared_ptr(shared_ptr<T> &&other) : ptr_(other.ptr_), use_count_(other.use_count_) {
        other.ptr_ = nullptr;
        other.use_count_ = nullptr;
    }

    ~shared_ptr() {
        if (ptr_ == nullptr) {
            return;
        }
        (*use_count_)--;
        if (*use_count_ == 0) {
            delete ptr_;
        }
    }

    shared_ptr<T>& operator=(const shared_ptr<T> &other) {
        if (this == &other) {
            return *this;
        }
        if (ptr_ != other.ptr_) {
            if (ptr_ != nullptr) {
                (*use_count_)--;
                if (*use_count_ == 0) {
                    delete ptr_;
                }
            }
            ptr_ = other.ptr_;
            use_count_ = other.use_count_;
            if (ptr_ != nullptr) {
                (*use_count_)++;
            }
        }
        return *this;
    }

    shared_ptr<T>& operator=(shared_ptr<T> &&other) {
        if (this == &other) {
            return *this;
        }
        if (ptr_ != nullptr) {
            (*use_count_)--;
            if (*use_count_ == 0) {
                delete ptr_;
            }
        }
        ptr_ = other.ptr_;
        use_count_ = other.use_count_;
        other.ptr_ = nullptr;
        other.use_count_ = nullptr;
        return *this;
    }

    T* get() const {
        return ptr_;
    }

    size_t use_count() const {
        if (use_count_ == nullptr) {
            return 0;
        }
        return *use_count_;
    }

    explicit operator bool() const {
        return use_count() > 0;
    }
private:
    T *ptr_;
    size_t *use_count_;
};
