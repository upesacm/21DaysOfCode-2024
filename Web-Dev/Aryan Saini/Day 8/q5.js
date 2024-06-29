
const coffeePrice = 5;
const bagelPrice = 3;
const soupPrice = 9;


const coffeeQuantity = 1;
const bagelQuantity = 2;
const soupQuantity = 1;


const cost = (coffeePrice * coffeeQuantity) + (bagelPrice * bagelQuantity) + (soupPrice * soupQuantity);


document.getElementById("order-cost").innerHTML = "Total Cost: $" + cost;

