document.addEventListener('DOMContentLoaded', function() {
    const date_after_Month = dayjs().add(1, 'month').format('MMMM D');
    document.getElementById('para1').innerText = date_after_Month;
});
