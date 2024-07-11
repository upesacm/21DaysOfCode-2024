// Import DayJS library
const dayjs = require('dayjs');

// Get today's date
const today = dayjs();

// Add 5 days
const futureDate = today.add(5, 'day');

// Format the date
const formattedDate = futureDate.format('MMMM D');

console.log(formattedDate);
