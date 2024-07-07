let inputfield = document.querySelector(".input-field");
let resultfield = document.querySelector(".result");
let buttonfield = document.querySelector(".submit")
let guessfield = document.querySelector(".guess")
function handleSubmit() {
    let rand = Math.random()  // Example random number for testing

    if(rand < 0.5){
        if (inputfield.value == rand) {
            resultfield.textContent = "You guessed right!";
            guessfield.textContent = "The correct guess was : " + rand;
        } else {
            resultfield.textContent = "OOPS! You guessed wrong!";
            buttonfield.textContent = "Try Again?";
            guessfield.textContent = "The correct guess was : " + rand;
        }
    }
    else{
        resultfield.textContent = "Our Program guessed out of range!!"
        buttonfield.textContent = "Play again?";
    }

    
}
