let result = 0;

document.addEventListener("DOMContentLoaded", function() {
    const numButtons = document.querySelectorAll(".num-button");
    const resetButton = document.querySelector(".reset-button");
    const resultElement = document.getElementById("result");

    numButtons.forEach(function(button) {
        button.addEventListener("click", function() {
            result += parseInt(button.value);
            resultElement.textContent = result;
        });
    });

    resetButton.addEventListener("click", function() {
        result = 0;
        resultElement.textContent = result;
    });
});