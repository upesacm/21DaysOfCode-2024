let coffeeP = 5;
let bagelP = 3;
let soupP = 9;

let coffeeQ = 1;
let bagelQ = 2;
let soupQ = 1;

let cost = (coffeeP * coffeeQ) + (bagelP * bagelQ) + (soupP * soupQ);

console.log("cost = $" + cost);

document.body.innerHTML = '<h1>Cost: $' + cost + '</h1>';
