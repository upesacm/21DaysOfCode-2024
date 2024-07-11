const dayjs = require('dayjs');

const today = dayjs();

const futureDate = today.add(1, 'month'); // Adding 1 month to the current day

const formattedDate = futureDate.format('MMMM D'); // Changing the format
console.log(formattedDate);