document.addEventListener('DOMContentLoaded', function() {
    function Check_Weekend(date) {
        const day = date.format('dddd');
        return day === 'Saturday' || day === 'Sunday';
    }
    // added check weekday and weekend also
    const today = dayjs();
    const message = Check_Weekend(today) ? 'Weekend' : 'Weekday';
    document.getElementById('para1').innerText = message;
});
