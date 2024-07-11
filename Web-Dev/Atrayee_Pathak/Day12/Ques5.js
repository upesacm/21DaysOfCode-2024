const dayjs = require('dayjs');

// Function to check if the given date is a weekend
function isWeekend(date) {
    // Get the day of the week
    const dayOfWeek = date.format('dddd');
    
    // Check if it's Saturday or Sunday
    return dayOfWeek === 'Saturday' || dayOfWeek === 'Sunday';
}

// Example usage
const today = dayjs();
console.log(isWeekend(today)); // Outputs true if today is Saturday or Sunday, false otherwise
