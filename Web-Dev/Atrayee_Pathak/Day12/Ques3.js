const dayjs = require('dayjs');

// Get today's date
const today = dayjs();

// Subtract 1 month
const pastDate = today.subtract(1, 'month');

// Format the date
const formattedDate = pastDate.format('MMMM D');

console.log(formattedDate);
