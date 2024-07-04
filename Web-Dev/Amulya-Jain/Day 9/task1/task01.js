const date = new Date();
const hour = date.getHours();
let message;
if (hour >= 6 && hour <= 12) {
    message = 'Good morning!';
} else if (hour >= 13 && hour <= 17) {
    message = 'Good afternoon!';
} else {
    message = 'Good night!';
}
document.getElementById('greeting').innerText = message;
