//here is the solution to the DSA Question 1 , Day 2
#include <iostream>
#include <vector>

using namespace std;

bool is_class_cancelled(int threshold, const vector<int>& arrival_times) {
  """
  Checks if class is cancelled based on student arrival times.
  """
  int on_time = 0;
  for (const int& time : arrival_times) {
    if (time <= 0) {
      on_time++;
    }
  }
  return on_time < threshold;
}
int main() {
  int threshold, num_students;

  cout << "Enter threshold number of students: ";
  cin >> threshold;

  cout << "Enter number of students: ";
  cin >> num_students;

  vector<int> arrival_times(num_students);

  cout << "Enter arrival times (non-positive for on-time):" << endl;
  for (int i = 0; i < num_students; i++) {
    cin >> arrival_times[i];
  }

  bool cancelled = is_class_cancelled(threshold, arrival_times);
  cout << (cancelled ? "YES" : "NO") << endl;  

  return 0;
}
