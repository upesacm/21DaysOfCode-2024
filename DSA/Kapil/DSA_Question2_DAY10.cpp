class SimplePriorityQueue {
 public:
  SimplePriorityQueue() = default;
  void insert(int item, int priority) {
    data_.push_back({priority, item});
  }
  int extract_min() {
    if (empty()) {
      return -1; 
    }
    int min_index = 0;
    for (int i = 1; i < data_.size(); ++i) {
      if (data_[i].first < data_[min_index].first) {
        min_index = i;
      }
    }
    int min_item = data_[min_index].second;
    data_.erase(data_.begin() + min_index);
    return min_item;
  }
  bool empty() const {
    return data_.empty();
  }
 private:
  vector<pair<int, int>> data_;
};
