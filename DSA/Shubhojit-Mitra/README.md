# Shubhojit Mitra - 21DaysOfCode

## Day 1

### DSA


#### Q1.js
```javascript
const countWays = (candy, day, month) => {
    let count = 0; // Initialized the counter to 0

    for (let i = 0; i <= candy.length - month; i++) {
        // calculate the sum of `month` consecutive squares
        let sum = 0;  // Initialized the sum to 0
        for (let j = i; j < i + month; j++) {
            sum += candy[j];
        } // If the sum equals `day` then increment counter
        if (sum === day) {
            count++;
        }
    }
    return count;
}
```

### Explanation
- This function takes three parameters: `candy`, `day`, and `month`.
- It initializes a counter variable `count` to 0.
- It uses a nested loop to iterate over the `candy` array.
- The outer loop iterates from 0 to `candy.length` - `month`.
- The inner loop calculates the sum of `month` consecutive elements in the `candy` array.
- If the sum equals the value of `day`, it increments the `count` variable.
- Finally, it returns the value of `count`.

---

#### Q2.js
```javascript
function countDivisiblePairs(arr, k) {
    let count = 0;
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            if ((arr[i] + arr[j]) % k === 0) {
                count++;
            }
        }
    }
    return count;
}
```
### Explanation
- This function takes two parameters: `arr` and `k`.
- It initializes a counter variable `count` to 0.
- It uses a nested loop to iterate over the `arr` array.
- The outer loop iterates from 0 to `arr.length` - 1.
- The inner loop iterates from `i + 1` to `arr.length`.
- It checks if the sum of the current pair of elements is divisible by `k`.
- If the sum is divisible by `k`, it increments the `count` variable.
- Finally, it returns the value of `count`.

---
