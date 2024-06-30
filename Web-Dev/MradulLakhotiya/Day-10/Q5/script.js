const hide = document.querySelector('.hide-me');
const but = document.querySelector('button');

but.addEventListener('click', () => {
    let value = hide.style.display;

    if (value === 'none') {    
        hide.style.display = 'block';
    } 
    else {
        hide.style.display = 'none';
    }
});