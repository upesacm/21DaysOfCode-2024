let sum = 0;

function updateSum(value) {
    sum += value;
    document.getElementById('sum').textContent = sum;
}

function resetSum() {
    sum = 0;
    document.getElementById('sum').textContent = sum;
}
