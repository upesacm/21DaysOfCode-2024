document.addEventListener('DOMContentLoaded', function() {
    const DayOfWeek = dayjs().format('dddd');
    document.getElementById('para1').innerText = DayOfWeek;
});
