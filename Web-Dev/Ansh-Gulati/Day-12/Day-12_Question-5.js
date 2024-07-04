const dayjs = require('dayjs');

function isWeekend(date) {
    const dayOfWeek = date.format('dddd');
    return dayOfWeek === 'Saturday' || dayOfWeek === 'Sunday';
}

// Example Input
const date1 = dayjs('2024-07-06');
const date2 = dayjs('2024-07-08');

console.log(isWeekend(date1));
console.log(isWeekend(date2)); 
