document.addEventListener('DOMContentLoaded', function() {
    const date_bef_one_month = dayjs().subtract(1, 'month').format('MMMM D');
    document.getElementById('para1').innerText = date_bef_one_month;
});
