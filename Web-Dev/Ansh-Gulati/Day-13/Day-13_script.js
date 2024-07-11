function tossCoin(guess) {
    // Step-1
    let randomNum = Math.random();

    // Step 2
    let result;

    if (randomNum < 0.5) 
    {
        result = 'heads';
    }
    else
    {
        result = 'tails';
    }

    // Step 3
    let message;
    
    if (guess == result)
    {
        message = 'You win!';
    }
    else
    {
        message = 'You lose!';
    }

    console.log(message);
    document.getElementById('result').textContent = `Result: ${result}. ${message}`;
}
