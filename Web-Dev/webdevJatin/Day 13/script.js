const { gu } = require("translate-google/languages");

const tossButton = document.getElementById('toss-button');
const resultElement = document.getElementById('result');
tossButton.addEventListener('click', tossCoin);
function tossCoin()
{
    const randomNumber = Math.random();
    let result;

    if(randomNumber< 0.5)
    {
        result = 'heads';
    }

    else{
        result = 'tails';
    }

    const guess = prompt('enter your guess');
    if(guess.toLowerCase()===result){
        resultElement.textContent= 'You win!'

    }
    else{
        resultElement.textContent='You Lose!'
    }
}