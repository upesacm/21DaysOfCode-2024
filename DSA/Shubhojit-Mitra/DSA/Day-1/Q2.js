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


// const arr = [1, 3, 2, 6, 1, 2];
// const k = 3;
// console.log(countDivisiblePairs(arr, k)); // Output: 5