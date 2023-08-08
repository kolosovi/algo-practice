int read4(char *buf) { return 0; }

class Solution {
 public:
  Solution() : length_(0), offset_(0) {}
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    int read_count = 0;
    while (read_count < n) {
      if (length_ - offset_ == 0) {
        offset_ = 0;
        length_ = read4(buf_);
        if (length_ == 0) {
          break;
        }
      }
      buf[read_count] = buf_[offset_];
      read_count++;
      offset_++;
    }
    return read_count;
  }

 private:
  char buf_[4];
  int length_;
  int offset_;
};
