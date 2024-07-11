const but = document.querySelector('.but');


but.addEventListener('click', () => {
    setTimeout(() => {
        but.innerHTML = 'Finished!'
    }, 1000);
});