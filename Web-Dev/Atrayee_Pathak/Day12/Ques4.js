const dayjs = require('dayjs');

// Get today's date
const today = dayjs();

// Format the date to get the day of the week
const dayOfWeek = today.format('dddd');

console.log(dayOfWeek);
