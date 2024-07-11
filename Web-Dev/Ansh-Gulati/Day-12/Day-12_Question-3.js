const dayjs = require('dayjs');

const today = dayjs();

const pastDate = today.subtract(1, 'month'); // Subtracting 1 month from the current day

const formattedDate = pastDate.format('MMMM D'); // Changing the format
console.log(formattedDate);