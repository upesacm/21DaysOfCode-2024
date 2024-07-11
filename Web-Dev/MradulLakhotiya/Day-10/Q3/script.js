const heads = document.getElementById('heads');
const tails = document.getElementById('tails');
const res = document.getElementById('text');

heads.addEventListener('click', () => {
    res.innerHTML = "You Chose Heads";
});

tails.addEventListener('click', () => {
    res.innerHTML = "You Chose Tails";
});