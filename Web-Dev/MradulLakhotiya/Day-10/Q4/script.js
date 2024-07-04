const input_box = document.querySelector('input');
const but = document.querySelector('button');
const text = document.querySelector('p');

but.addEventListener('click' , () => {
    text.textContent = "Your Name is "+ input_box.value;
    input_box.value = '';
});