
const soupPrice = 10;
const burgerPrice = 8;
const iceCreamPrice = 5;


const soupQuantity = 1;
const burgerQuantity = 3;
const iceCreamQuantity = 1;


const totalCost = (soupPrice * soupQuantity) + (burgerPrice * burgerQuantity) + (iceCreamPrice * iceCreamQuantity);

document.getElementById("order-cost").innerHTML = "Total Cost: $" + totalCost;
