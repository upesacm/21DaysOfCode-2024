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

// Example usage
const threshold = 3;
const arrival_times = [-1, -3, 4, 2];
console.log(isClassCancelled(threshold, arrival_times)); // Output: YES