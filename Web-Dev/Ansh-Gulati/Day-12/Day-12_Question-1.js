const dayjs = require('dayjs');

const today = dayjs();

const futureDate = today.add(5, 'day'); // Adding 5 days to the current day

const formattedDate = futureDate.format('MMMM D'); // Changing the format
console.log(formattedDate);