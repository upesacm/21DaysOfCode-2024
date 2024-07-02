const dayjs = require('dayjs');

// Get today's date
const today = dayjs();

// Add 1 month
const futureDate = today.add(1, 'month');

// Format the date
const formattedDate = futureDate.format('MMMM D');

console.log(formattedDate);
