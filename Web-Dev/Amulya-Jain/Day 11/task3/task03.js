document.getElementById('changeBtn').onclick = function() {
    setTimeout(function() {
        const button = document.getElementById('changeBtn');
        button.innerText = 'Finished!!';
    }, 1000);
};
