int countSegments(const std::vector<int>& candy, int d, int m) {
    int count = 0;
    int n = candy.size();
    
  
    if (n < m) return 0;
    
   
    int current_sum = 0;
    for (int i = 0; i < m; ++i) {
        current_sum += candy[i];
    }
    

    if (current_sum == d) {
        ++count;
    }
    
   
    for (int i = m; i < n; ++i) {
        current_sum += candy[i] - candy[i - m]; 
        if (current_sum == d) {
            ++count;
        }
    }
    
    return count;
}
