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

// const candy = [2, 2, 1, 3, 2];
// const day = 4;
// const month = 2;
// console.log(countWays(candy, day, month)); // Output: 2