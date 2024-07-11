document.getElementById('toggle-button').onclick = function() {
    const element = document.getElementById('toggleElement');
    if (element.style.display === 'none') {
        element.style.display = 'block';
    } else {
        element.style.display = 'none';
    }
};
