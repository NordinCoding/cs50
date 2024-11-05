function moveButton() {
    const button = document.getElementById('testButton')

    const screenWidth = window.innerWidth;
    const buttonWidth = button.offsetWidth;
    const newLeft = screenWidth - buttonWidth;

    button.style.left = `${newLeft}px`;
}

