let sum = 0;
values = [2, 3, 4, 5, -1, -2, -3];
buttonsContainer = document.getElementById('buttons');
resultDiv = document.getElementById('result');

function addToSum(value) {
    sum += value;
    resultDiv.innerText = 'Sum: ' + sum;
}

function resetSum() {
    sum = 0;
    resultDiv.innerText = 'Sum: ' + sum;
}
// implementing button creation thr script
values.forEach(value => {
    const button = document.createElement('button');
    button.className = 'button';
    button.innerText = (value > 0 ? '+' : '') + value;
    button.addEventListener('click', () => addToSum(value));
    buttonsContainer.appendChild(button);
});

document.getElementById('resetButton').addEventListener('click', resetSum);
