const age = 70;
let message;
if (age <= 6 || age >= 65) {
    message = 'Discount';
} 
else {
    message = 'No discount';
}
document.getElementById('discount').innerText = message;
