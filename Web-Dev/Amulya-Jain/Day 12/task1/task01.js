document.addEventListener('DOMContentLoaded', function() {
    const date = dayjs().add(5, 'day').format('MMMM D');
    document.getElementById('para1').innerText = date;
});
