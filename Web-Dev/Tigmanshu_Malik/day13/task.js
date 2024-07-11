const x = Math.random()
console.log(x)

const result = (x < 0.5) ? "tails" : "heads"

const userInput = prompt("Enter your choice (heads/tails)")

console.log(result == userInput ? "You win !!" : "You Lose !!")
