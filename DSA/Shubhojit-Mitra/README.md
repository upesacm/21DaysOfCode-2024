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

## Day 2

### DSA

#### Q1.js
```javascript
const isClassCancelled = (threshold, arrival_times) => {
    // Count the number of students who arrived on time
    let onTimeArrivals = arrival_times.filter(time => time <= 0).length;
    
    // Check if the number of on-time arrivals is less than the threshold
    if (onTimeArrivals < threshold) {
        return "YES"; // Class is cancelled
    } else {
        return "NO"; // Class is not cancelled
    }
}
```
### Explanation

- This function takes two parameters: `threshold` and `arrival_times`.
- It uses the `filter` method to count the number of students who arrived on time (t)
- It checks if the number of on-time arrivals is less than the threshold.
- If the number of on-time arrivals is less than the threshold, it returns "YES", indicating the class is cancelled!
- Otherwise, it returns "NO", indicating the class is not cancelled.

---
#### Q2.js
```javascript
unction climbingLeaderboard(leaderboard, player_scores) {
    // Remove duplicates from leaderboard and sort in descending order
    const uniqueLeaderboard = [...new Set(leaderboard)].sort((a, b) => b - a);
    
    // Initialize an array to hold the player's ranks
    const ranks = [];
    
    // Iterate through each of the player's scores
    player_scores.forEach(score => {
        // If the score is higher than the highest score, rank 1
        if (score >= uniqueLeaderboard[0]) {
            ranks.push(1);
        } else if (score < uniqueLeaderboard[uniqueLeaderboard.length - 1]) {
            // If the score is lower than the lowest score, rank is last
            ranks.push(uniqueLeaderboard.length + 1);
        } else {
            // Binary search to find the rank
            let low = 0;
            let high = uniqueLeaderboard.length - 1;
            while (low <= high) {
                let mid = Math.floor((low + high) / 2);
                if (uniqueLeaderboard[mid] === score) {
                    ranks.push(mid + 1);
                    break;
                } else if (uniqueLeaderboard[mid] < score) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                // Adjust rank for scores between two leaderboard scores
                if (low > high) {
                    ranks.push(low + 1);
                }
            }
        }
    });
    
    return ranks;
}
```
### Explanation
This function takes two arrays as input: `leaderboard` and `player_scores`.
- `leaderboard` is an array of scores from a leaderboard, and `player_scores` is an array for player's score.
- The function returns an array of ranks for each of the player's scores.
- The function first removes duplicates from the leaderboard and sorts it in descending order.
- Then, it uses binary search to determine the position of player's score.