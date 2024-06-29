let soupP = 10;
let burgerP = 8;
let iceCreamP = 5;

let soupQ = 1;
let burgerQ = 3;
let iceCreamQ = 1;

let totalCost = (soupP * soupQ) + (burgerP * burgerQ) + (iceCreamP * iceCreamQ);

console.log("cost of the order is $" + totalCost);

document.body.innerHTML = '<h1>cost of the order is $' + totalCost + '</h1>';
