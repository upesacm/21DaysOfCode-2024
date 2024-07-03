document.getElementById('submitBtn').onclick = function() {
    const text = document.getElementById('nameInput').value;
    document.getElementById('displayText').innerText = `Your name is: ${text}`;
};
