document.addEventListener('DOMContentLoaded', function() {
    const tossButton = document.getElementById('toss-button');
    const resultDisplay = document.getElementById('result');
    const outcomeDisplay = document.getElementById('outcome');

    tossButton.addEventListener('click', function() {
        const randomNumber = Math.random();
        const result = randomNumber < 0.5 ? 'heads' : 'tails';
        resultDisplay.innerText = `Result: ${result}`;

        const guess = document.getElementById('guess').value;
        if (guess === result) {
            outcomeDisplay.innerText = 'You win!';
            outcomeDisplay.style.color = 'green';
        } else {
            outcomeDisplay.innerText = 'You lose!';
            outcomeDisplay.style.color = 'red';
        }
    });
});
