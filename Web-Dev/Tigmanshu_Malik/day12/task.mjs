import dayjs from 'dayjs';

const now = dayjs();

const task1 = now.add(5, 'day')
console.log(task1.format('MM-DD'))

const task2 = now.add(1, 'month')
console.log(task2.format('MM-DD'))

const task3 = now.subtract(1, 'month')
console.log(task3.format('MM-DD'))

console.log(now.format('dddd'))

const isWeekend = (date) => {
    return (date.day() == 6 || date.day() == 0) ? "Weekend" : "Weekday"
}

console.log(isWeekend(now.add(5, 'day')))

