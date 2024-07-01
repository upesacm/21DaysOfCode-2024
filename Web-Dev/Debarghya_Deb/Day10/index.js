document.addEventListener("DOMContentLoaded", () => {
    let result = document.querySelector(".result");

    window.head = function head() {
        result.textContent = "You chose: head";
    };
    
    window.tail = function tail() {
        result.textContent = "You chose: tails";
    };
});
